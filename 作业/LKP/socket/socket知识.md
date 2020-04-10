# socket知识
## socket调用库函数
1. 创建套接字： Socket(af,type,protocol)
2. 建立地址和套接字的联系： bind(sockid, local addr, addrlen)
3. 服务器端侦听客户端的请求：listen( Sockid ,quenlen)
4. 建立服务器/客户端的连接 (面向连接TCP）
       * 客户端请求连接：Connect(sockid, destaddr, addrlen)
  * 服务器端等待从编号为Sockid的Socket上接收客户连接请求：
        newsockid=accept(Sockid，Clientaddr, paddrlen)
5. 发送/接收数据
       * 面向连接：send(sockid, buff, bufflen)
       * recv( )
       * 面向无连接：sendto(sockid,buff,…,addrlen)
       * recvfrom( )
6. 释放套接字
       * close(sockid)

## sockaddr_in结构体:
SOCKADDR_IN  SrvAddr;

SrvAddr.family=AF_INET;

SrvAddr.port=hotns(666）; //其中666代表端口号

SrvAddr.sin_addr.S_un.S_addr=htonl(127.0.0.1);

或SrvAddr.sin_addr.S_un.S_addr=INADDR_ANY;(指绑定到本机的任一块网卡上)