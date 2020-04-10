#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
int main()
{
    char send_buf[100], recv_buf[100];
    SOCKET cli_accept;
    SOCKADDR_IN cli_ADDR;
    WSADATA wsa;
    //绑定套接字库版本
    if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
    {
        cout << "绑定socket库版本失败" << endl;
        exit(EXIT_FAILURE);
    }
    //初始化协议族
    cli_ADDR.sin_family = AF_INET;              //设置地址家族
    cli_ADDR.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//设置地址
    cli_ADDR.sin_port = htons(5214);        //设置端口
    cli_accept = socket(AF_INET, SOCK_STREAM, 0);
    //连接到服务端套接口
    if (connect(cli_accept, (SOCKADDR*)&cli_ADDR, sizeof(SOCKADDR)) < 0)
    {
        cout << "连接失败！" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "连接成功！" << endl;
    }
    //消息传递
    while (1)
    {
        cout << "客户端:" << endl;
        cin >> send_buf;
        send(cli_accept, send_buf, 100, 0);
        recv(cli_accept, recv_buf, 100, 0);
        cout << "服务器:" << recv_buf << endl;
    }
    //关闭套接口
    closesocket(cli_accept);
    WSACleanup();
}