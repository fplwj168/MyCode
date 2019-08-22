#include "sort.h"
#include <stdlib.h>
void InsertSort(int*src, int n)//直接插入排序，时间复杂度是O（N）~O（N的平方）
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)                      //循环遍历
	{
		tmp = src[i];                            //将第二个数取出来存放在tmp中，此时第二个位置没有内容。
		for (j = i; j>0 && src[j - 1]>tmp; j--)  //判断第一个数是否大于第二个数tmp，
		{                                        //若大于，则进for循环
			src[j] = src[j - 1];                 //将第一个数赋值给第二个没有内容的位置，进行j--
		}
		src[j] = tmp;                            //将tmp的值赋值给第一个数
	}
}
void ShellSort(int*src,int n )//希尔排序，缩小增量法
{
	int i,j,k;
	int tmp,gap;
	for (gap = n / 2; gap; gap /= 2)
	{
		for (k = 0; k<gap; k++)
		{
			for (i = gap+k; i < n; i+=gap)                         //进行直接插入排序
			{
				tmp = src[i];                                      
				for (j = i; j>=gap && src[j - gap]>tmp; j-=gap)
				{
					src[j] = src[j - gap];
				}
				src[j] = tmp;                                     //直接插入排序
			}
	   }
   }

}
void dealMergeSort(int*src, int *tmp, int start, int end)//归并排序内部。采用分治法，二分法也是如此。进行的是类似于二叉树的后序遍历过程，左右根
{                                                        //过程是先进行二分，直到分成单独数字为止。
	if (start >= end)                                    //判断数头是否大于等于数尾，如果数头大于等于数尾，则跳出。
	{
		return;
	}
	int mid = (start + end) / 2;                        //进行二分，求取中间值
	dealMergeSort(src, tmp, start, mid);                //数头到中间，进行排序
	dealMergeSort(src, tmp, mid+1,end);                 //中间数的下一个到数尾进行排序
	int a = start;                                      // 定义
	int b = mid + 1;
	int c = start;
	while (a<=mid&&b<=end)                              //判断当数头小于中间数并且下一个数小于等于数尾时，
	{
		if (src[a] < src[b])                            //如果数头小于中间数的下一个数，
		{
			tmp[c] = src[a];                            //则将数头存放在待排序的数组tmp中，
			a++;                                        //将数头进行下标的自加，下标向后移动
		}
		else                                            //如果数头大于中间数的下一个数
		{
			tmp[c] = src[b];                            //则将中间数的下一个数存放在待排序数组tmp中
			b++;                                        //将中间数的下一个数进行下标的自加，下标向后移动
		}
		c++;                                            //待排序数组tmp的下标指向也向后移动
	}
	for (; a <= mid; a++, c++)                          //遍历数头到中间数，类似于二叉树中的左孩子
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)                          //遍历中间数的下一个数到数尾，类似于二叉树中的右孩子
	{
		tmp[c] = src[b];
	}
	int i;
	for (i = start; i <= end; i++)                     //从数头到数尾进行遍历，
	{
		src[i] = tmp[i];                               //将tmp数组又返回给src
	}

}
void MergeSort(int*src, int n)//归并排序,给外部调用的接口
{
	int *tmp = (int*)malloc(n*sizeof(int));           //给tmp开辟空间
	dealMergeSort(src, tmp, 0, n - 1);
	free(tmp);                                        //释放空间
}
