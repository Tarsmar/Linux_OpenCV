/*************************************************************************
    > File Name: write.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 10时14分26秒
	> Description: 从键盘输入并读取后写入目标文件
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
	int fd = open("./test.txt", O_RDWR | O_CREAT, 0644);
	if(fd < 0)
	{
		perror("open");//通过perror函数得到错误原因
		return -1;
	}

	printf("fd = %d\n", fd);

	//写入文件
	while(1)
	{
		char buf[128] = {0};

		//从标准输入得到数据
		fgets(buf, sizeof(buf), stdin);

		ret = write(fd, buf, strlen(buf));

		if(ret < 0)
		{
			perror("write");
			break;
		}
		else if(ret == 0)
			break;
	}

	//关闭文件
	close(fd);
    return 0;
}
