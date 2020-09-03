/*************************************************************************
    > File Name: open.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 10时14分26秒
	> Description: 通过open函数实现打开文件
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
	//int fd = open("./test.txt", O_RDWR | O_CREAT, 0644);
	int fd = open("./test.c", O_RDONLY);
	if(fd < 0)
	{
		perror("open");//通过perror函数得到错误原因
		return -1;
	}

	printf("fd = %d\n", fd);

	close(fd);
    return 0;
}
