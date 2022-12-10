#ifndef _TOOL_H
#define _TOOL_H

//#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>


//���������������͵ĺ���
static void swap(void* x, void* y, const int n)
{
	void* p = malloc(n);
	if (p == NULL)
	{
		perror("������������p��ʱ�ռ�ʧ��");
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

//color(0);   printf("��ɫ\n");
//color(1);   printf("��ɫ\n");
//color(2);   printf("��ɫ\n");
//color(3);   printf("����ɫ\n");
//color(4);   printf("��ɫ\n");
//color(5);   printf("��ɫ\n");
//color(6);   printf("��ɫ\n");
//color(7);   printf("��ɫ\n");
//color(8);   printf("��ɫ\n");
//color(9);   printf("����ɫ\n");
//color(10);  printf("����ɫ\n");
//color(11);  printf("��ǳ��ɫ\n");
//color(12);  printf("����ɫ\n");
//color(13);  printf("����ɫ\n");
//color(14);  printf("����ɫ\n");
//color(15);  printf("����ɫ\n")






#endif