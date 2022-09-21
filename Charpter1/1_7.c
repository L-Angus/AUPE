/*************************************************************************
	> File Name: 1_7.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 15:10:43 2022
 ************************************************************************/

#include<stdio.h>
#include "../apue.h"
#include <sys/wait.h>
#include "../err_log.h"

static void sig_int(int);

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if(signal(SIGINT, sig_int) == SIG_ERR){
		err_sys("signal error!");
	}

	printf("%% ");
	while(fgets(buf, MAXLINE, stdin) != NULL){
		if(buf[strlen(buf)-1] == '\n'){
			buf[strlen(buf)-1] = 0; /*replace newline with null*/
		}

		if((pid = fork()) < 0){
			err_sys("fork error!");
		}else if(pid == 0){	/* child */
			execlp(buf, buf, (char *)0);
			err_ret("couldn't exectue: %s", buf);
			exit(127);
		}
		/* parent */

		if((pid = waitpid(pid, &status, 0)) < 0){
			err_sys("waitpid error");
		}
		printf("%% ");
	}


	exit(0);
}

void sig_int(int signo){
	printf("interrupt\n%% ");
}
