/*************************************************************************
	> File Name: 1_5.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 14:32:06 2022
 ************************************************************************/

#include<stdio.h>
#include"../apue.h"
#include "../err_log.h"


int main(void)
{
	int c;
	while((c = getc(stdin)) != EOF){
		if(putc(c, stdout) == EOF){
			err_sys("output error!");
		}		
	}

	if(ferror(stdin)){
		err_sys("input error!");
	}
	exit(0);
}
