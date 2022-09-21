/*************************************************************************
	> File Name: err_log.h
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 11:16:34 2022
 ************************************************************************/

#ifndef ERR_LOG_H
#define ERR_LOG_H
#include "apue.h"
#include <errno.h>
#include <stdarg.h>

static void err_doit(int, int, const char*, va_list);

void err_sys(const char*fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_quit(const char* fmt,...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(0,0,fmt, ap);
	va_end(ap);
	exit(1);
}

void err_ret(const char* fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

static void err_doit(int errnoflag, int error, const char*fmt, va_list ap){
	char buf[MAXLINE];
	vsnprintf(buf, MAXLINE-1, fmt, ap);
	if(errnoflag){
		snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1,": %s", strerror(error));
	}
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);
}

#endif 
