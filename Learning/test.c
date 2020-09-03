/*************************************************************************
    > File Name: test.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 14时15分54秒
	> Description: 测试说明在不分线程的情况下计算机无法同时执行两个while函数
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>

int main(int argc, char *argv[])
{
	while(1)
	{
		printf("打游戏\n");
		sleep(1);
	}

	while(1)
	{
		printf("跟对象聊天\n");
		sleep(1);
	}

    return 0;
}
