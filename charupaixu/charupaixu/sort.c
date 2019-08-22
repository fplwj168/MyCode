#include "sort.h"
#include <stdlib.h>
void InsertSort(int*src, int n)//ֱ�Ӳ�������ʱ�临�Ӷ���O��N��~O��N��ƽ����
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)                      //ѭ������
	{
		tmp = src[i];                            //���ڶ�����ȡ���������tmp�У���ʱ�ڶ���λ��û�����ݡ�
		for (j = i; j>0 && src[j - 1]>tmp; j--)  //�жϵ�һ�����Ƿ���ڵڶ�����tmp��
		{                                        //�����ڣ����forѭ��
			src[j] = src[j - 1];                 //����һ������ֵ���ڶ���û�����ݵ�λ�ã�����j--
		}
		src[j] = tmp;                            //��tmp��ֵ��ֵ����һ����
	}
}
void ShellSort(int*src,int n )//ϣ��������С������
{
	int i,j,k;
	int tmp,gap;
	for (gap = n / 2; gap; gap /= 2)
	{
		for (k = 0; k<gap; k++)
		{
			for (i = gap+k; i < n; i+=gap)                         //����ֱ�Ӳ�������
			{
				tmp = src[i];                                      
				for (j = i; j>=gap && src[j - gap]>tmp; j-=gap)
				{
					src[j] = src[j - gap];
				}
				src[j] = tmp;                                     //ֱ�Ӳ�������
			}
	   }
   }

}
void dealMergeSort(int*src, int *tmp, int start, int end)//�鲢�����ڲ������÷��η������ַ�Ҳ����ˡ����е��������ڶ������ĺ���������̣����Ҹ�
{                                                        //�������Ƚ��ж��֣�ֱ���ֳɵ�������Ϊֹ��
	if (start >= end)                                    //�ж���ͷ�Ƿ���ڵ�����β�������ͷ���ڵ�����β����������
	{
		return;
	}
	int mid = (start + end) / 2;                        //���ж��֣���ȡ�м�ֵ
	dealMergeSort(src, tmp, start, mid);                //��ͷ���м䣬��������
	dealMergeSort(src, tmp, mid+1,end);                 //�м�������һ������β��������
	int a = start;                                      // ����
	int b = mid + 1;
	int c = start;
	while (a<=mid&&b<=end)                              //�жϵ���ͷС���м���������һ����С�ڵ�����βʱ��
	{
		if (src[a] < src[b])                            //�����ͷС���м�������һ������
		{
			tmp[c] = src[a];                            //����ͷ����ڴ����������tmp�У�
			a++;                                        //����ͷ�����±���Լӣ��±�����ƶ�
		}
		else                                            //�����ͷ�����м�������һ����
		{
			tmp[c] = src[b];                            //���м�������һ��������ڴ���������tmp��
			b++;                                        //���м�������һ���������±���Լӣ��±�����ƶ�
		}
		c++;                                            //����������tmp���±�ָ��Ҳ����ƶ�
	}
	for (; a <= mid; a++, c++)                          //������ͷ���м����������ڶ������е�����
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)                          //�����м�������һ��������β�������ڶ������е��Һ���
	{
		tmp[c] = src[b];
	}
	int i;
	for (i = start; i <= end; i++)                     //����ͷ����β���б�����
	{
		src[i] = tmp[i];                               //��tmp�����ַ��ظ�src
	}

}
void MergeSort(int*src, int n)//�鲢����,���ⲿ���õĽӿ�
{
	int *tmp = (int*)malloc(n*sizeof(int));           //��tmp���ٿռ�
	dealMergeSort(src, tmp, 0, n - 1);
	free(tmp);                                        //�ͷſռ�
}
