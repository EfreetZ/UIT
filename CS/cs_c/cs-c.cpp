#include<stdio.h>
#include<Winsock2.h>

#pragma comment(lib,"Ws2_32.lib")

int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2,2),&wsaData);
	if(LOBYTE(wsaData.wVersion)!=2||HIBYTE(wsaData.wVersion)!=2)
	{
		printf("error!\n");
		return -1;
	}
	printf("请求协议版本成功\n");

	SOCKET clientSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(SOCKET_ERROR==clientSocket)
	{
		printf("ERROR!\n");
		return -1;
	}
	printf("创建socket成功\n");

	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(10086);

	int r=connect(clientSocket,(sockaddr *)&addr,sizeof(addr));
	if(r==-1)
	{
		printf("ERROR!\n");
		return -1;
	}
	printf("连接服务器成功\n");

	char buff[1024];
	while(1)
	{
		memset(buff,0,1024);
		scanf("%s",buff);
		r=send(clientSocket,buff,strlen(buff),0);
		if(r)
		{
			printf("发送成功\n");
		}
	}


	return 0;
}
