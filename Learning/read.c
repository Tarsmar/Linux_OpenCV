/*************************************************************************
    > File Name: read.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 10时14分26秒
	> Description: 打开目标文件并读取后打印
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#include<unistd.h>

int main(int argc, char *argv[])
{
	//打开文件
	int ret;
	int fd = open("./struct.c", O_RDONLY);
	if(fd < 0)
	{
		perror("open");//通过perror函数得到错误原因
		return -1;
	}

	printf("fd = %d\n", fd);

	//读取文件
	while(1)
	{
		//缓冲区，存放读取到的文件内容
		char buf[128] = {0};

		ret = read(fd, buf, sizeof(buf));
		if(ret < 0)
		{
			perror("read");
			break;
		}
		else if(ret == 0)
			break;

		printf("%s", buf);
	}

	printf("\n");

	//关闭文件
	close(fd);
    return 0;
}
