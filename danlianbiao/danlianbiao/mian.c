#include "slist.h"
void listtest()
{
	SList test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 4);
	SListPushFront(&test, 6);
	SListPushFront(&test, 9);

	SListPrint(&test);

	SListPopFront(&test);
	SListPrint(&test);

	SListInsertAfter(SListFind(&test,4),8);
	SListPrint(&test);
	SListEraseAfter(SListFind(&test,8));
	SListPrint(&test);

	//SListInsertFront(&test,8,10);
	//SListPrint(&test);
	SListDestory(&test);




}
int main()
{
	listtest();
	system("pause");
	return 0;
}