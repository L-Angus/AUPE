/*************************************************************************
	> File Name: error_msg.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 15:57:08 2022
 ************************************************************************/

#include<stdio.h>
#include "../apue.h"
#include <errno.h>

int main(int argc, char* argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);

	exit(0);
}
