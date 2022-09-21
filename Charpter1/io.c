/*************************************************************************
	> File Name: io.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 14:18:39 2022
 ************************************************************************/

#include<stdio.h>
#include"../apue.h"
#include "../err_log.h"
#define BUFFSIZE 4096

int main(void)
{
	int n;
	char buf[BUFFSIZE];

	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if(write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	}

	if(n < 0){
		err_sys("read error");
	}
	return 0;
}
