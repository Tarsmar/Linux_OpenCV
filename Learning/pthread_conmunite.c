/*************************************************************************
    > File Name: pthread_communicate.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 14时30分32秒
	> Description: 通过全局变量实现进程间通信
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<pthread.h>

int i = 3;
void *func(void * arg);//线程执行函数1

int main(int argc, char *argv[])
{
	int ret;
	pthread_t pid;

	//创建线程1
	ret = pthread_create(&pid, NULL, func, NULL);
	if(ret < 0)
	{
		printf("创建线程失败\n");
		return -1;
	}

	ret = pthread_detach(pid);//将子线程与主线程分离
	if(ret < 0)
	{
		printf("分离线程失败\n");
		return -1;
	}
	

	while(1)
	{
		printf("main:i = %d\n", i);
		sleep(1);
	}

    return 0;
}

void *func(void * arg)
{
	while(1)
	{
		printf("func:i = %d\n", i++);
		sleep(1);
	}
}

