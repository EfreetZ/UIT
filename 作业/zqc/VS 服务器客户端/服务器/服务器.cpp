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
    //��socket��汾
    if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
    {
        cout << "��socket��汾ʧ��" << endl;
        exit(EXIT_FAILURE);
    }
    //��ʼ��Э����
    listen_ADDR.sin_family = AF_INET;       //���õ�ַ����
    listen_ADDR.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    listen_ADDR.sin_port = htons(5214);     //���ö˿�
    ser_listen = socket(AF_INET, SOCK_STREAM, 0);
    //���������˿�
    if (bind(ser_listen, (SOCKADDR*)&listen_ADDR, sizeof(SOCKADDR)) < 0)
    {
        cout << "socket��ʧ��!" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    //�ȴ����ӣ���ʱser_listen��Ϊ�����׽ӿ�
    if (listen(ser_listen, SOMAXCONN) < 0)
    {
        cout << "���ü���ʧ��!" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    cout << "�ȴ����ӣ�" << endl;
    
    int len = sizeof(SOCKADDR);
    //��ʱser_acceptΪ�����׽ӿ�
    if ((ser_accept = accept(ser_listen, (SOCKADDR*)&accept_ADDR, &len)) < 0)
    {
        cout << "����ʧ��!" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    cout << "���ӳɹ������ڿͻ�������!" << endl;
    //��Ϣ�Ĵ���
    while (1)
    {
        recv(ser_accept, recv_buf, 100, 0);
        cout << "�ͻ��ˣ�" << recv_buf << endl << "��������" << endl;
        cin >> send_buf;
        send(ser_accept, send_buf, 100, 0);
    }
    //�����ر��׽ӿ�
    closesocket(ser_listen);
    closesocket(ser_accept);
    WSACleanup();
}