#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
int main (int argc, char *argv[])
{
	printf( "enter a nomber of paralelepipeds:");
	int number = scan();//������ ���� � ���������
	mylist *List=createMyList(number);// ���������  ������
	int i;
    for(i=0; i<number; i++)
    {
    addCoor(List);//������ �������� � ���������
    }
	printMyFigure(List); //���� ������� �������
	destroyMyList(List); //��������� ������ (��� �� �������� ���'���)
	return 0;
	
}


