/****************三种方法排序（插入排序、希尔排序、归并排序）************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define BUFSIZE 10000
void printfArray( int*src, int n)          //打印数组函数
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

#if 1                                                //1切换0执行else产生随机数进行排序
	int src[10] = { 3, 1, 6, 7, 9, 2, 4, 8, 10, 5 };
	//InsertSort(src,10);             //插入排序
	ShellSort(src, 10);              //希尔排序
	//MergeSort(src, 10);            //归并排序
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