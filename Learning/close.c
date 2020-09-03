/*************************************************************************
    > File Name: close.c
    > Author: Tarsmar
    > Mail: tujianju@gmail.com
    > Created Time: 2020年09月03日 星期四 10时49分33秒
	> Description: 通过close函数关闭系统文件1（stout）展示在关闭后程序无法正常运行
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>

int main(int argc, char *argv[])
{
	printf("*******************\n");

	close(1);

	printf("*******************\n");
	printf("*******************\n");
	printf("*******************\n");
	printf("*******************\n");

    return 0;
}
