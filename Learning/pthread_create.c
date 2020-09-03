/*************************************************************************
    > File Name: pthread_create.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 14时30分32秒
	> Description: 创建两个新线程实现多线程工作
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<pthread.h>

void *func(void * arg);//线程执行函数1
void *func1(void * arg);//线程执行函数2

int main(int argc, char *argv[])
{
	int ret;
	pthread_t pid, pid1;

	//创建线程1
	ret = pthread_create(&pid, NULL, func, NULL);
	if(ret < 0)
	{
		printf("创建线程失败\n");
		return -1;
	}
	//创建线程2
	ret = pthread_create(&pid1, NULL, func1, NULL);
	if(ret < 0)
	{
		printf("创建线程失败\n");
		return -1;
	}

	while(1)
	{
		printf("打游戏\n");
		sleep(1);
	}

    return 0;
}

void *func(void * arg)
{
	while(1)
	{
		printf("跟对象聊天\n");
		sleep(1);
	}
}

void *func1(void * arg)
{
	while(1)
	{
		printf("我还要学习\n");
		sleep(1);
	}
}
