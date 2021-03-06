#ifndef List_h
#define List_h
#include "List.h"
#include <stdio.h>

typedef struct __DoubleElement DoubleElement;

typedef struct __DoubleList
{
	DoubleElement *head;
	DoubleElement *tail;
	int count;
}DoubleList;

DoubleList *CreateList();
void FreeList(DoubleList *aList);
DoubleElement *AddElement(DoubleList *aList, DoubleElement *aNewElement);
int CountList(const DoubleList *aList);
void AddElementAtIndex(DoubleList *aList, DoubleElement *aNewElement, int anIndex);
void DeleteElementAtIndex(DoubleList *aList, int anIndex);
DoubleElement *ElementAtIndex(const DoubleList *aList, int anIndex);
void doPrintList(const DoubleList *aList);
void DeleteElement (DoubleList *aList);

#endif
