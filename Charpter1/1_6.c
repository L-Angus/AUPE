/*************************************************************************
	> File Name: 1_6.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 14:48:47 2022
 ************************************************************************/

/*打印进程ID*/
#include<stdio.h>
#include"../apue.h"

int main(void)
{
	printf("hello world from process ID: %ld\n", (long)getpid());
	exit(0);
}
