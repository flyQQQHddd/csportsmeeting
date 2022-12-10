#ifndef _TOOL_H
#define _TOOL_H

//#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>


//交换任意数据类型的函数
static void swap(void* x, void* y, const int n)
{
	void* p = malloc(n);
	if (p == NULL)
	{
		perror("交换函数创建p临时空间失败");
		Exit(-1);
	}
	memcpy(p, x, n);
	memcpy(x, y, n);
	memcpy(y, p, n);
	free(p);
}

void color(const unsigned short textColor)
{
	if (textColor >= 0 && textColor <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//color(0);   printf("黑色\n");
//color(1);   printf("蓝色\n");
//color(2);   printf("绿色\n");
//color(3);   printf("湖蓝色\n");
//color(4);   printf("红色\n");
//color(5);   printf("紫色\n");
//color(6);   printf("黄色\n");
//color(7);   printf("白色\n");
//color(8);   printf("灰色\n");
//color(9);   printf("淡蓝色\n");
//color(10);  printf("淡绿色\n");
//color(11);  printf("淡浅绿色\n");
//color(12);  printf("淡红色\n");
//color(13);  printf("淡紫色\n");
//color(14);  printf("淡黄色\n");
//color(15);  printf("亮白色\n")






#endif