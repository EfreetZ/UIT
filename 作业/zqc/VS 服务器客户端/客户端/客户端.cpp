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
    //���׽��ֿ�汾
    if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
    {
        cout << "��socket��汾ʧ��" << endl;
        exit(EXIT_FAILURE);
    }
    //��ʼ��Э����
    cli_ADDR.sin_family = AF_INET;              //���õ�ַ����
    cli_ADDR.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//���õ�ַ
    cli_ADDR.sin_port = htons(5214);        //���ö˿�
    cli_accept = socket(AF_INET, SOCK_STREAM, 0);
    //���ӵ�������׽ӿ�
    if (connect(cli_accept, (SOCKADDR*)&cli_ADDR, sizeof(SOCKADDR)) < 0)
    {
        cout << "����ʧ�ܣ�" << endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "���ӳɹ���" << endl;
    }
    //��Ϣ����
    while (1)
    {
        cout << "�ͻ���:" << endl;
        cin >> send_buf;
        send(cli_accept, send_buf, 100, 0);
        recv(cli_accept, recv_buf, 100, 0);
        cout << "������:" << recv_buf << endl;
    }
    //�ر��׽ӿ�
    closesocket(cli_accept);
    WSACleanup();
}