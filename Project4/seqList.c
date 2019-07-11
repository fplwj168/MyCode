#include "seqList.h"
void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->capicity = capacity;//开辟容量大小
	psl->array = (SLDataType *)malloc(capacity* sizeof(SLDataType));//malloc 开辟内存空间
	assert(psl->array);//
	psl->size = 0;//初始化有效数据
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}
void CheckCapacity(SeqList* psl)//检查容量大小，是否扩充容量
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;

}
void SeqListPopBack(SeqList* psl)//
{
	assert(psl || psl->size);
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//头插  从后向前移，逆向遍历数组
{
	assert(psl);
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//头删  数组正向遍历
{
	assert(psl);
	CheckCapacity(psl);
	int i;
	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d",psl->array[i]);
	}
	putchar('\n');
	system("pause");
	return 0;

}
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos<= psl->size);
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl || pos < psl->size);
	int i;
	psl->size--;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	int pos = SeqListFind(psl, x);
	if (pos >= 0)
	{
		SeqListErase(psl, pos);
	}
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl || pos < psl->size);
	psl->array[pos-1] = x;
}
