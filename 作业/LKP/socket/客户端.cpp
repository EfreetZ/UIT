#include<iostream>
#include<winsock2.h>
#include<string.h>                                    //TCP的socket 
#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main()
{
	WORD wVersionRequested=MAKEWORD(2,2);//初始化 WS2_32动态库
	WSADATA WSAData;//WSADATA结构体 
	int i=WSAStartup(wVersionRequested,&WSAData);
	if(i==-1)
	{
		cout<<"初始化失败"<<endl;
		return 0;//wVersionRequested调用成功返回0 ，失败-1 
	}
	
	SOCKET sock = socket(AF_INET,SOCK_STREAM,0);//创建一个套接字
		if(sock == -1)
		{
			cout<<"套接字创建失败"<<endl;
			return 0;
		}
		
		//绑定IP和端口号
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(6666);
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//回送地址（127.x.x.x）是本机回送地址
		if(connect(sock, (sockaddr *)&addr, sizeof(addr)) == -1)
		{  //连接失败 
			cout<<"连接失败"<<endl;
			closesocket(sock);//关闭套接字
			return 0;
		}
		cout<<"连接成功"<<endl;
		
	while(1){
		 
		
		//发送数据 
		cout<<"客户："; 
		string data;
		cin>>data;
		const char * sendData;
		sendData = data.c_str();   //string转const char* 
		send(sock, sendData, strlen(sendData), 0);//在已经建立连接的套接字上发送数据
		
		char recData[255];
		int ret = recv(sock, recData, 255, 0);
		if(ret>0){
			recData[ret] = 0x00;
			cout<<"服务端："<<recData<<endl;
		} 
	 
	}
	
		closesocket(sock); //关闭套接字
	WSACleanup();//用于终止使用WS2_32动态库
	return 0;
	
}

