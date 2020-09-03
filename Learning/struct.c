/*************************************************************************
  > File Name: struct.c
  > Author: Tarsmar
  > Mail: tujianju@gmail.com
  > Created Time: 2020年09月03日 星期四 08时44分15秒
  > Description: 结构体复习
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct score {
	int Chinese;
	int Math;
	int English;
};//定义一个结构体类型，存放成绩信息

struct student {
	int num;
	char name[128];
	char sex;
	struct score se;//定义一个成绩的结构体变量
}; //定义一个学生结构体类型

int main(int argc, char *argv[])
{
	//定义一个学生结构体变量
	//数据类型      变量名
	struct student	st1;
	struct student	st2 = {2, "lisi", 'M', {88, 77, 66}};

	//定义一个结构体指针
	//数据类型		*指针名
	struct student	*p = &st2;

	st1.num = 1;
	//st1.name = "zhangsan";//error,给字符形数组赋值不可以使用等号(=)
	/*
	st1.name[0] = 'z';
	st1.name[1] = 'h';
	st1.name[2] = 'a';
	*/

	strcpy(st1.name, "zhangsan");
	st1.sex = 'M';
	st1.se.Chinese = 90;
	st1.se.Math = 99;
	st1.se.English = 89;

	printf("%d %s %c %d %d %d\n", st1.num, st1.name, st1.sex, st1.se.Chinese, st1.se.Math, st1.se.English);
	printf("%d %s %c %d %d %d\n", st2.num, st2.name, st2.sex, st2.se.Chinese, st2.se.Math, st2.se.English);
	printf("%d %s %c %d %d %d\n", (*p).num, (*p).name, (*p).sex, (*p).se.Chinese, (*p).se.Math, (*p).se.English);
	printf("%d %s %c %d %d %d\n", p->num, p->name, p->sex, p->se.Chinese, p->se.Math, p->se.English);

	return 0;
}
