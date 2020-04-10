#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
int main()
{
    char send_buf[100], recv_buf[100];
    SOCKET ser_listen, ser_accept;
    SOCKADDR_IN listen_ADDR, accept_ADDR;
    WSADATA wsa;
    //绑定socket库版本
    if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
    {
        cout << "绑定socket库版本失败" << endl;
        exit(EXIT_FAILURE);
    }
    //初始化协议族
    listen_ADDR.sin_family = AF_INET;       //设置地址家族
    listen_ADDR.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    listen_ADDR.sin_port = htons(5214);     //设置端口
    ser_listen = socket(AF_INET, SOCK_STREAM, 0);
    //绑定主机，端口
    if (bind(ser_listen, (SOCKADDR*)&listen_ADDR, sizeof(SOCKADDR)) < 0)
    {
        cout << "socket绑定失败!" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    //等待连接，此时ser_listen变为被动套接口
    if (listen(ser_listen, SOMAXCONN) < 0)
    {
        cout << "设置监听失败!" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    cout << "等待连接！" << endl;
    
    int len = sizeof(SOCKADDR);
    //此时ser_accept为主动套接口
    if ((ser_accept = accept(ser_listen, (SOCKADDR*)&accept_ADDR, &len)) < 0)
    {
        cout << "连接失败!" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    cout << "连接成功，请在客户端输入!" << endl;
    //消息的传递
    while (1)
    {
        recv(ser_accept, recv_buf, 100, 0);
        cout << "客户端：" << recv_buf << endl << "服务器：" << endl;
        cin >> send_buf;
        send(ser_accept, send_buf, 100, 0);
    }
    //结束关闭套接口
    closesocket(ser_listen);
    closesocket(ser_accept);
    WSACleanup();
}