#include<iostream>
#include<winsock2.h>
#include<string.h>                                  //TCP的socket 
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
	
	SOCKET sock=socket(AF_INET,SOCK_STREAM,0);//创建一个套接字  
	if(sock == -1)
		{
			cout<<"套接字创建失败"<<endl;
			return 0;
		}
		
	//绑定IP和端口号 
	sockaddr_in addr;
	addr.sin_family=AF_INET;//通信协议，通常为AF_INET 
	addr.sin_port=htons(6666);//端口号，一般1024以下的端口号已经被占用 
	addr.sin_addr.S_un.S_addr=INADDR_ANY;//绑定本地网卡 
	bind(sock,(LPSOCKADDR)&addr,sizeof(addr));//绑定IP和端口号 
	
	//将套接字设定为监听模式
	 if(listen(sock,5)==-1)//5为连接队伍的最大长度 
	 {
	 	cout<<"错误"<<endl;//成功返回0 错误返回-1
		 return 0; 
	 }
	
	//循环接收数据
	SOCKET sock1;//新的套接字 
	sockaddr_in addr1;//请求连接放的IP和端口信息
	int p=sizeof(addr1);
	char revdata[255];//定义缓存区 
	cout<<"等待连接..."<<endl;
		sock1=accept(sock,(SOCKADDR*)&addr1,&p);
		cout<<"接收到一个数据："<<inet_ntoa(addr1.sin_addr)<<endl;//打印IP地址  addr1.sin_addr转换IP值 
		
	while(1)
	{
		
		 //接收数据  
        int ret = recv(sock1, revdata, 255, 0);         
        if(ret > 0)  
        {  
            revdata[ret] = 0x00;  
            cout<<"客户："<<revdata<<endl;  
        }
        
        //发送数据  
        cout<<"服务端："; 
         string data;
		cin>>data;
		const char * sendData;
		sendData = data.c_str();//string转const char*
        send(sock1, sendData, strlen(sendData), 0);  //在已经建立连接的套接字上发送数据
         
	 } 
	 closesocket(sock1);//关闭套接字
	closesocket(sock);  //关闭套接字 
    WSACleanup();  //用于终止使用WS2_32动态库
    return 0; 
	

 } 
