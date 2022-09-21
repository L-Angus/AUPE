/*************************************************************************
	> File Name: ID.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 16:13:09 2022
 ************************************************************************/

#include<stdio.h>
#include "../apue.h"

int main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	return 0;
}
