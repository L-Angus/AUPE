/*************************************************************************
	> File Name: exe.c
	> Author: angus.li
	> Mail: lsd15651008321@163.com 
	> Created Time: 三  9/21 16:59:21 2022
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int workflow(int32_t t){
	if(t*24*60*60*100 > pow(2, 32))
		return t;
}

int main()
{
	int32_t t;
	printf("%d\n", workflow(t));
	return 0;
}
