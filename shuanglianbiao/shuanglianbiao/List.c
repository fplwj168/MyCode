#include "List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));//给头开辟空间
	memset(&plist->_head->_data, 0, sizeof(LTDataType));//类型数据清零
	plist->_head->_next = plist->_head->_prev = plist->_head;//下一个节点等于自己等于上一个节点

}
void ListPushBack(List* plist, LTDataType x)//尾插
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_prev ->_next = cur;
	cur->_prev = plist->_head->_prev;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;	
}
void ListPopBack(List* plist)//尾删
{
	ListNode *tmp = plist->_head->_prev;
	if (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}
void ListPushFront(List* plist, LTDataType x)//头插
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;

	plist->_head->_next ->_prev = cur;
	cur->_next = plist->_head->_next;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
	
}
void ListPopFront(List* plist)//头删
{
	ListNode *tmp = plist->_head->_next;
	if (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}
}
void ListPrint(List* plist)//打印
{
	ListNode *cur;
	printf("head<-->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d<-->", cur->_data);
	}
	printf("head\n");

}
void ListDestroy(List* plist)//销毁
{
	ListNode *tmp = plist->_head->_next;
	while (tmp != plist->_head)
	{
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
		tmp = plist->_head->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}