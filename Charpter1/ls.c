/************************************************************************
	> File Name: ls.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 10:53:23 2022
 ************************************************************************/

#include<stdio.h>
#include <dirent.h>
#include "../apue.h"
#include "../err_log.h"

int main(int argc, char* argv[]){
	DIR	*dp;
	struct dirent *dirp;
	if(argc != 2){
		err_quit("Usage: ls directory_name");
		//printf("Usage: ls directory_name\n");
		//	exit(1);
	}
	
	if((dp = opendir(argv[1])) == NULL){
		err_sys("can't open %s", argv[1]);
		//printf("can't open %s\n",argv[1] );
		//exit(1);
	}
	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}
