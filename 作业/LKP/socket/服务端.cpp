#include<iostream>
#include<winsock2.h>
#include<string.h>                                  //TCP��socket 
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
	
	SOCKET sock=socket(AF_INET,SOCK_STREAM,0);//����һ���׽���  
	if(sock == -1)
		{
			cout<<"�׽��ִ���ʧ��"<<endl;
			return 0;
		}
		
	//��IP�Ͷ˿ں� 
	sockaddr_in addr;
	addr.sin_family=AF_INET;//ͨ��Э�飬ͨ��ΪAF_INET 
	addr.sin_port=htons(6666);//�˿ںţ�һ��1024���µĶ˿ں��Ѿ���ռ�� 
	addr.sin_addr.S_un.S_addr=INADDR_ANY;//�󶨱������� 
	bind(sock,(LPSOCKADDR)&addr,sizeof(addr));//��IP�Ͷ˿ں� 
	
	//���׽����趨Ϊ����ģʽ
	 if(listen(sock,5)==-1)//5Ϊ���Ӷ������󳤶� 
	 {
	 	cout<<"����"<<endl;//�ɹ�����0 ���󷵻�-1
		 return 0; 
	 }
	
	//ѭ����������
	SOCKET sock1;//�µ��׽��� 
	sockaddr_in addr1;//�������ӷŵ�IP�Ͷ˿���Ϣ
	int p=sizeof(addr1);
	char revdata[255];//���建���� 
	cout<<"�ȴ�����..."<<endl;
		sock1=accept(sock,(SOCKADDR*)&addr1,&p);
		cout<<"���յ�һ�����ݣ�"<<inet_ntoa(addr1.sin_addr)<<endl;//��ӡIP��ַ  addr1.sin_addrת��IPֵ 
		
	while(1)
	{
		
		 //��������  
        int ret = recv(sock1, revdata, 255, 0);         
        if(ret > 0)  
        {  
            revdata[ret] = 0x00;  
            cout<<"�ͻ���"<<revdata<<endl;  
        }
        
        //��������  
        cout<<"����ˣ�"; 
         string data;
		cin>>data;
		const char * sendData;
		sendData = data.c_str();//stringתconst char*
        send(sock1, sendData, strlen(sendData), 0);  //���Ѿ��������ӵ��׽����Ϸ�������
         
	 } 
	 closesocket(sock1);//�ر��׽���
	closesocket(sock);  //�ر��׽��� 
    WSACleanup();  //������ֹʹ��WS2_32��̬��
    return 0; 
	

 } 
