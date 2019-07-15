#include "slist.h"
void SListInit(SList* plist)
{
	plist->_head = NULL;
}
void SListDestory(SList* plist)//释放链表，不停的砍头
{
	assert(plist);
	SListNode * tmp;
	while (plist->_head)   //判断头是否为空，为空就跳出
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x)//头插
{
	assert(plist);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;

}
void SListPopFront(SList* plist)//头删
{
	assert(plist);
	SListNode * tmp;
	if (plist->_head)
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)//某一位置后面进行插入
{
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;//不怎么理解，需要加深
	pos->_next = cur;
}
// 在pos的前面进行插入
/*void SListInsertFront(SListNode* pos, SLTDataType x,SLTDataType src)某一位置前面插入
{
	SListNode * cur;
	SListNode * newdata=(SListNode *)malloc(sizeof(SListNode));
	if(plist->_head->_data==x)
	{
		SListPopFront(plist,src);
		return;
	}
	for (cur = plist->_head; cur->_next; cur = cur->_next)
	{
		if (cur->_next->_data == x)
		{
			break;
		}
	}
	newdata->_data=src;
	newdata->_next=cur->_next;
	cur->_next=newdata;
}
*/

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode * tmp=pos->_next;
	pos->_next = tmp->_next;
	free(tmp);
}
void SListPrint(SList *plist)
{
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}
