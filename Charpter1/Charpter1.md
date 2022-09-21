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



