/*
������ 5 
� ��������� ������ �������� ����� ����� �������, 
���� �� ���������� ����� �����. 
³��������� ������ �� �����
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"



int main( void )
{
	
int count = 12;
	
	IntList *theList = CreateIntList();//�������� ������ ��������
	if (NULL == theList)
	{
		return -1;
	}

	int z;
	for( z = 0; z < count;  z++)
	{
		AddIntValueToList(theList, rand() % 999);//����� �������� �� ������
	}
	
	DeleteMultiplesElements(theList, 3);//������� ����� 3 ������� 
	
	DestroyIntList(theList); //��������� ������
	return 0;
}

