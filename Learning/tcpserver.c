/*************************************************************************
    > File Name: tcpserver.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月04日 星期五 09时49分40秒
	> Description: 服务器接收代码
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<unistd.h>
#include<arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int ret = 0;

	//1.创建服务器套接字
	int server = socket(AF_INET, SOCK_STREAM, 0);
	if(server < 0)
	{
		printf("socket failed\n");
		return -1;
	}

	printf("server = %d\n", server);

	//2.绑定ip和端口
	struct sockaddr_in s_addr;

	s_addr.sin_family = AF_INET;
	s_addr.sin_port	  = htons(6666);//主机转成网络字节序
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//字符串ip转成整型ip
	memset(s_addr.sin_zero, 0, 8);

	socklen_t s_len = sizeof(s_addr);

	ret = bind(server, (struct sockaddr *)&s_addr, s_len);
	if(ret < 0)
	{
		printf("bind failed\n");
		close(server);
		return -1;
	}

	//3.设置监听数
	ret = listen(server, 5);
	if(ret < 0)
	{
		printf("listen failed\n");
		close(server);
		return -1;
	}

	printf("wait for a client...\n");

	//4.等待连接
	struct sockaddr_in c_addr;//保存客户端的地址结构
	socklen_t c_len = sizeof(c_addr);

	int rws = accept(server, (struct sockaddr *)&c_addr, &c_len);
	if(rws < 0)
	{
		printf("accept failed\n");
		close(server);
		return -1;
	}	

	printf("Connected!\n");

	//5.处理连接
	while(1)
	{
		char buf[128] = {0};
		char buflen[10] = {0};

		//1.读取数据的大小
		ret = read(rws, buflen, sizeof(buflen));
		if(ret <= 0)
		{
			break;
		}
		int num = atoi(buflen);
		//printf("num = %d\n", num);

		//2.接收数据内容
		ret = read(rws, buf, num);
		/*错误处理*/

		printf("recv:%s\n", buf);
	}

	close(server);
    return 0;
}
