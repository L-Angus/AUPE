# 第一章 Unix基础知识

## 1. Unix的体系结构

1. 操作系统严格意义上是一种软件，位于系统换件的核心，因此称为内核。
2. 它可以控制计算机硬件资源，提供程序运行的环境。
3. 内核的外层是内核的接口，又称系统调用（system call）。
4. 系统调用的外层是shell和公用函数库：shell是一个特殊的应用程序，未运行其他程序提供了一个接口；公用函数库则可以理解为是系统调用的二次封装，用户层可以调用函数库，也可以直接调用系统调用。

从广义上来说，操作系统就是包括了内核和一些其他软件，其他软件包括：系统使用程序、应用程序、shell以及公用函数库等。


## 2. 登录
系统口令文件：/etc/passed
组成：登录名、加密口令、数字用户ID、数字组、注释字段、起始目录以及shell程序。

**shell**：用户登录后跟系统交互的桥梁是shell，shell是一个命令行解释器，它读取用户命令，然后执行命令。

## 3. 文件和目录

### 文件系统

Unix文件系统是目录和文件的一种层次结构，所有东西的起点是根目录（root），目录名称'/'；
目录是一个包含目录项的文件。
```markdown
逻辑上，可以认为每个目录项都包含一个文件名以及该文件的属性信息（文件类型、文件大小、文件所有者、文件权限、文件最后修改时间等）；
```

### 文件名
目录中的每个名字称为文件名。斜线和空字符不能用作文件名：
```markdown
斜线用来分隔构成路径的文件名；
空格符用来终止一个路径名。
```
推荐文件名组成：a-zA-Z、0-9、.、-、_

创建目录时会自动创建两个文件名：.和..；前者指向当前目录；后者指向父目录。

### 路径名
用斜线分隔的一个或多个文件名组成的序列构成路径名：
1. 以斜线开头的路径称为绝对路径名；
2. 否则为相对路径。

### 工作目录
每个工作进程都有一个工作目录，所有相对路径都是从工作目录开始解释的。例如doc/memo/test; 绝对路径是/usr/lib/lint。

## 4. 输入和输出

### 文件描述符
文件描述符通常是一个小的非负整数，内核用以标识一个特定进程正在访问的文件。当内核打开一个文件或者创建一个文件时，都会返回一个文件描述符。在读写时，使用文件描述符。

### 标准输入、标准输出和标准错误
当运行一个新程序时，shell会自动打开三个文件描述符：标准输入、标准输出以及标准错误。

### 不带缓冲的I/O
函数open、read、write、lseek以及close提供了不带缓冲的I/O，使用文件描述符

```c
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
```

### 标准io

标准io为那些不带缓冲的I/O函数提供了一个带缓冲的接口。

```c
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
```

## 5. 程序和进程
### 程序
程序是一个存储在磁盘上的某个目录下的可执行文件。内核使用exec函数将程序读入内存，并执行程序。

### 进程和进程ID
程序的执行实例被称为进程。或者说运行起来的程序就是进程。某些操作系统用任务（task）来表示执行的程序。
进程ID：每一个进程都有一个唯一标识的数字标识符，即为进程ID，非负整数。可以通过getpid()函数获取。

```c
/*打印进程ID*/
#include<stdio.h>
#include"../apue.h"

int main(void)
{
	printf("hello world from process ID: %ld\n", (long)getpid());
	exit(0);
}
```
### 进程控制
进程控制的主要函数有3个：fork，exec和waitpid。
其中，exec函数有7中变体，统称exec函数。

```c
#include<stdio.h>
#include "../apue.h"
#include <sys/wait.h>
#include "../err_log.h"

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

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
```

### 线程和线程ID
通常，一个进程只有一个控制线程。

## 6. 用户标识
### 用户ID：
用户ID为0的为根用户或超级用户，其登录名为root。

### 组ID
口令文件登录项也包括用户的组ID，他是一个数值。
组文件将组名映射为数组的组ID，组文件通常是/etc/group

```c
#include<stdio.h>
#include "../apue.h"

int main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	return 0;
}
```

## 7. 信号
信号用于通知进程发生的某种情况。
1. 忽略信号；
2. 按系统默认方式处理；
3. 提供一个函数，信号发生时调用该函数，这被称为捕捉该信号。
