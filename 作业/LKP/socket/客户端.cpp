#include<iostream>
#include<winsock2.h>
#include<string.h>                                    //TCP��socket 
#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main()
{
	WORD wVersionRequested=MAKEWORD(2,2);//��ʼ�� WS2_32��̬��
	WSADATA WSAData;//WSADATA�ṹ�� 
	int i=WSAStartup(wVersionRequested,&WSAData);
	if(i==-1)
	{
		cout<<"��ʼ��ʧ��"<<endl;
		return 0;//wVersionRequested���óɹ�����0 ��ʧ��-1 
	}
	
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);//����һ���׽���
		if(sock == -1)
		{
			cout<<"�׽��ִ���ʧ��"<<endl;
			return 0;
		}
		
		//��IP�Ͷ˿ں�
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(6666);
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//���͵�ַ��127.x.x.x���Ǳ������͵�ַ
		if(connect(sock, (sockaddr *)&addr, sizeof(addr)) == -1)
		{  //����ʧ�� 
			cout<<"����ʧ��"<<endl;
			closesocket(sock);//�ر��׽���
			return 0;
		}
		cout<<"���ӳɹ�"<<endl;
		
	while(1){
		 
		
		//�������� 
		cout<<"�ͻ���"; 
		string data;
		cin>>data;
		const char * sendData;
		sendData = data.c_str();   //stringתconst char* 
		send(sock, sendData, strlen(sendData), 0);//���Ѿ��������ӵ��׽����Ϸ�������
		
		char recData[255];
		int ret = recv(sock, recData, 255, 0);
		if(ret>0){
			recData[ret] = 0x00;
			cout<<"����ˣ�"<<recData<<endl;
		} 
	 
	}
	
		closesocket(sock); //�ر��׽���
	WSACleanup();//������ֹʹ��WS2_32��̬��
	return 0;
	
}

