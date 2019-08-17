#include <stdio.h>
#include <stdlib.h>
#include "List.h"
int main()
{
	List list;
	ListInit(&list);
	ListPushFront(&list, 7);
	ListPushFront(&list, 6);
	ListPushFront(&list, 5);
	ListPushFront(&list, 4);
	ListPopBack(&list);
	ListPopFront(&list);
	
	ListPrint(&list);
	ListDestroy(&list);
	system("pause");
	return 0;



}