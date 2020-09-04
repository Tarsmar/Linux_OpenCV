/*************************************************************************
    > File Name: tcpclient.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月04日 星期五 14时07分04秒
	> Description: 客户端发送代码
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int ret = 0;

	//1.创建套接字
	int client = socket(AF_INET, SOCK_STREAM, 0);
	if(client < 0)
	{
		printf("socket failed\n");
		return -1;
	}

	//2.连接服务器
	//要连接的服务器的信息
	struct sockaddr_in s_addr;

	s_addr.sin_family = AF_INET;
	s_addr.sin_port   = htons(6666);
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(s_addr.sin_zero, 0, 8);

	socklen_t s_len = sizeof(s_addr);

	ret = connect(client, (struct sockaddr *)&s_addr, s_len);
	if(ret < 0)
	{
		printf("connect failed\n");
		close(client);
		return -1;
	}

	printf("Connect server success\n");

	//3.通信
	while(1)
	{
#if 0 //客户端发送
		char buf[128] = {0};

		fgets(buf, sizeof(buf), stdin);

		ret = write(client, buf, strlen(buf));
		if(ret <= 0)
		{
			printf("snd failed\n");
			break;
		}

		printf("send[%d]:%s\n", strlen(buf), buf);
#else //粘包问题
		char buf[] = "hello";
		char buflen[10] = {0};

		int num = strlen(buf);//得到数据的大小
		sprintf(buflen, "%d", num);

		//1.发送数据长度
		write(client, buflen, sizeof(buflen));

		//2.发送数据
		write(client, buf, strlen(buf));
#endif
	}

	close(client);
    return 0;
}
