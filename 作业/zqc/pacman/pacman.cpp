// pacman.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "pacman.h"
#include "GMap.h"
#include "GObject.h"

using namespace std;     //++++++++++++++++++++++

#define WLENTH 750  // 高
#define WHIGHT 750  // 宽
#define STAGE_COUNT 3 // 一共三关
HWND g_hwnd; // 游戏窗口句柄
                         //++++++++++++++++++++++          
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //参数不再使用
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PACMAN, szWindowClass, MAX_LOADSTRING);
    //注册窗口化
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow)){
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PACMAN));
    //当前的关卡
    int s_n = 0; //[0,1,2]
    //地图
    GMap* MapArray[STAGE_COUNT] = { new Stage_1(), new Stage_2(), new Stage_3() };
    
    //玩家对象
    //自己
    auto g_me = std::make_shared<PacMan>(P_ROW, P_ARRAY);
    // 设定四个敌人对象
    auto e1 = std::make_shared<RedOne>(E_ROW, E_ARRAY);
    auto e2 = std::make_shared<RedOne>(E_ROW, E_ARRAY);
    auto e3 = std::make_shared<BlueOne>(E_ROW, E_ARRAY);
    auto e4 = std::make_shared<YellowOne>(E_ROW, E_ARRAY);
    // 关卡
    GObject::pStage = MapArray[s_n]; //初始化为第一关地图

    // 设定玩家
    Enermy::player = g_me;  //用一个指针指向玩家对象

    MSG msg;

    DWORD dwLastTime = 0;
    // 主消息循环:
    // 玩家没有被抓,并且关卡<3
    while (!g_me->IsOver() && s_n < STAGE_COUNT) {
        // 判断是否赢得比赛
        if (g_me->IsWin()) {
            s_n++;
            // 重设自己和敌人位置
            g_me->SetPosition(P_ROW, P_ARRAY);
            e1->SetPosition(E_ROW, E_ARRAY);    //设置敌军一的位置
            e2->SetPosition(E_ROW, E_ARRAY);    //设置敌军二的位置
            e3->SetPosition(E_ROW, E_ARRAY);    //设置敌军三的位置
            e4->SetPosition(E_ROW, E_ARRAY);    //设置敌军四的位置
            // 判断是否完成了3关,如果完成,退出游戏,否则进入下一关
            if (s_n < 3) {
                MessageBox(g_hwnd, _T("恭喜过关"), _T("吃豆子提示"), MB_OK);
                GObject::pStage = MapArray[s_n];
                RECT screenRect;
                screenRect.top = 0;
                screenRect.left = 0;
                screenRect.right = WLENTH;
                screenRect.bottom = WHIGHT;

                HDC hdc = GetDC(g_hwnd);                        //获取设备
                std::shared_ptr<HDC__> dc(hdc, [](HDC hdc) {    //智能指针，自动管理资源
                    ::ReleaseDC(g_hwnd, hdc);
                    });
                ::FillRect(dc.get(), &screenRect, CreateSolidBrush(RGB(255, 255, 255)));
                GObject::pStage->DrawMap(hdc);      // 画地图
                continue;                           // 继续进行循环
            }
            else {
                // 跳出循环
                break;
            }
        }

        // 获取消息
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);                 //翻译消息
            DispatchMessage(&msg);                  //分发消息
        }

        // 判断时间,否则画得太快
        if (GetTickCount() - dwLastTime >= 40) {
            dwLastTime = GetTickCount();            //记住本次的时间
        }
        else {
            // 时间不到,本次不进行绘画
            continue;
        }

        {
            // 获得设备
            HDC hdc = ::GetDC(g_hwnd);
            // 不使用时自动释放
            std::shared_ptr<HDC__> dc(hdc, [](auto hdc) {
                ::ReleaseDC(g_hwnd, hdc);
                });
            // 画豆子
            MapArray[s_n]->DrawPeas(hdc);
            // 画地图
            MapArray[s_n]->DrawMap(hdc);

            // 画敌人及自动运动
            {
                e1->action();
                e1->DrawBlank(hdc);
                e1->Draw(hdc);

                e2->action();
                e2->DrawBlank(hdc);
                e2->Draw(hdc);

                e3->action();
                e3->DrawBlank(hdc);
                e3->Draw(hdc);

                e4->action();
                e4->DrawBlank(hdc);
                e4->Draw(hdc);
            }

            {
                // 画自己
                g_me->DrawBlank(hdc);
                g_me->Draw(hdc);
                // 自己向前移动
                g_me->action();

                // 获取按键 : 控制自己的方向
                if (GetAsyncKeyState(VK_DOWN)) {   
                    g_me->SetTwCommand(DOWN);
                }
                if (GetAsyncKeyState(VK_LEFT)) {
                    g_me->SetTwCommand(LEFT);
                }
                if (GetAsyncKeyState(VK_RIGHT)) {
                    g_me->SetTwCommand(RIGHT);
                }
                if (GetAsyncKeyState(VK_UP)) {
                    g_me->SetTwCommand(UP);
                }
            }
        }
    }
        /*
        //画点测试
        {
            HDC hdc = ::GetDC(g_hwnd);
            SetPixel(hdc, rand() % WLENTH, rand() % WHIGHT,
                RGB(rand() % 256, rand() % 256, rand() % 256, ));
                ::ReleaseDC(g_hwnd, hdc);
        }
        */
        /*
        {
            //画线测试
            HDC hdc = ::GetDC(g_hwnd);
            //创建画笔
            HPEN pen = CreatePen(PS_SOLID, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
            //选择画笔
            HPEN oldpen = (HPEN)SelectObject(hdc, pen);
            MoveToEx(hdc, rand() % WLENTH, rand() % WHIGHT, NULL);
            LineTo(hdc, rand() % WLENTH, rand() % WHIGHT);

            //恢复画笔
            SelectObject(hdc, oldpen);
            ::ReleaseDC(g_hwnd, hdc);
            //暂停1毫秒
            Sleep(1);
        }
        */
        /*
        {
            //画矩型测试
            HDC hdc = ::GetDC(g_hwnd);
            {
                //创建画笔
                HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                //选择画笔
                HPEN oldPen=(HPEN)SelectObject(hdc,pen);
                //画矩型(空心)
                Rectangle(hdc, 100, 200, 300, 500);
                //恢复画笔
                SelectObject(hdc, oldPen); 
                DeleteObject(pen);
            }
            {
                //创建画笔
                HBRUSH bBrush=CreateSolidBrush(RGB(0,0,255));
                //填充矩型
                RECT rect;
                rect.left=50;
                rect.top = 270; 
                rect.right = 150; 
                rect.bottom = 370; 
                FillRect(hdc, &rect, bBrush); 
                DeleteObject(bBrush);
            }
            ::ReleaseDC(g_hwnd, hdc); 
            //暂停1豪秒
            Sleep(1);
        }
        */
        /*
        {
            HDC hdc = ::GetDC(g_hwnd); 
            Arc(hdc, 100, 100, 200, 300             //矩型左上点,右下点
                ,150,200                            //起点
                ,100,200                            //终点(与起点逆时针连接)
            );
            
            Arc(hdc,0,0,100,100
                ,50,100
                ,50,0
            );
            ::ReleaseDC(g_hwnd, hdc);
        }
        */

    // 如果游戏结束
    if (g_me->IsOver()) {
        MessageBoxA(NULL, "出师未捷", "吃豆子提示", MB_OK);
    }
    // 否则,提示赢得游戏
    else {
        MessageBoxA(NULL, "恭喜您赢得了胜利\n确定后游戏退出", "吃豆子提示", MB_OK);
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PACMAN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PACMAN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中
   // 创建窗口
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW
                               , 0 // 在屏幕中的位置 x
                               , 0 // 在屏幕中的位置 y
                               , WLENTH // 宽
                               , WHIGHT // 高
                               , nullptr, nullptr, hInstance, nullptr);

   if (!hWnd) {
       return FALSE;
   }

   // 保存游戏窗口
   g_hwnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
