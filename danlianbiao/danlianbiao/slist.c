#include "slist.h"
void SListInit(SList* plist)
{
	plist->_head = NULL;
}
void SListDestory(SList* plist)//�ͷ�������ͣ�Ŀ�ͷ
{
	assert(plist);
	SListNode * tmp;
	while (plist->_head)   //�ж�ͷ�Ƿ�Ϊ�գ�Ϊ�վ�����
	{
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x)//ͷ��
{
	assert(plist);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;

}
void SListPopFront(SList* plist)//ͷɾ
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
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x)//ĳһλ�ú�����в���
{
	assert(pos);
	SListNode * cur = (SListNode *)malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = pos->_next;//����ô��⣬��Ҫ����
	pos->_next = cur;
}
// ��pos��ǰ����в���
/*void SListInsertFront(SListNode* pos, SLTDataType x,SLTDataType src)ĳһλ��ǰ�����
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
