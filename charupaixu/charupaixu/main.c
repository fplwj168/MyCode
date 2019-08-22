/****************���ַ������򣨲�������ϣ�����򡢹鲢����************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define BUFSIZE 10000
void printfArray( int*src, int n)          //��ӡ���麯��
{
	int i;
	for (i = 0; i < n; i++)
	{
			printf("%d", src[i]);
			putchar(' ');
	}
}

int main()
{

#if 1                                                //1�л�0ִ��else�����������������
	int src[10] = { 3, 1, 6, 7, 9, 2, 4, 8, 10, 5 };
	//InsertSort(src,10);             //��������
	ShellSort(src, 10);              //ϣ������
	//MergeSort(src, 10);            //�鲢����
	printfArray(src, 10);
	system("pause");
	return 0;
	
#else
	srand(time(NULL));
	int src[10000];
	int i;
	for (i = 0; i < BUFSIZE; i++)
	{
		src[i]=rand()%5000+1;
	}
	//InsertSort(src, BUFSIZE);
	ShellSort(src, BUFSIZE);
	//MergeSort(src, BUFSIZE);
	printfArray(src, BUFSIZE);
	system("pause");
	return 0;
#endif
}