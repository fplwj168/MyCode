#ifndef _SLIST_H_
#define _SLIST_H_
/*
链表如何遍历
单向无头非循环链表便利方式：
for(cur = head; cur ; cur = cur->next) 类似于数组遍历
{
	cur;
}
双向带头循环的遍历方式:
for(cur = head->next; cur!=head ; cur = cur->next) 类似于数组遍历
{
cur;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// 1、无头单向非循环链表增删查改实现
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
void TestSList();
#endif//_SLIST_H_