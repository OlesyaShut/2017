

#include "List.h"
#include <limits.h>
#include <stdlib.h>

IntNode *createIntNodeWithValue(int anIntValue);//�������� ����� ��� �������
IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex); //����� ����� 

IntList *CreateIntList( void )//������ ���'��� � ����� ��
{
	IntList *theList = (IntList *)malloc(sizeof(IntList));//sizeof ������� �������� � ������
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

void DestroyIntList(IntList *aList)// �������  ������
{
	if (NULL == aList)//�� aList �� �������
	{
		return;
	}

	if (NULL != aList->head)
	{
		int anIndex = aList->count - 1;
		
		do
		{
		IntNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);
		free (theNodeToDelete);
		anIndex--;		
		}while (anIndex >= 0);
	
		free(aList);
	}
}

IntNode *FindTheNodeAtIndex(IntList *aList, int anIndex)//��������� ���� �� ��������
{
	if(aList == NULL || anIndex < 0 || aList->count < anIndex )
	{
		return;
	}
	
	int i = 0;
	IntNode *theNode = aList->head;
	do
	{
		if (i == anIndex)
		{
			break;
		}
	
		theNode = theNode->next;
		i++;
	
	}while (theNode != aList->head);
	
	return theNode;
}


int AddIntValueToList(IntList *aList, int anIntValue)//����� �������� �� ������
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		IntNode *theNode = createIntNodeWithValue(anIntValue);
	
		if (NULL != theNode)
		{
		
			//1. ������ �������
			if (NULL == aList->head)
			{
				aList->head = theNode;
				aList->head->next = aList->head->prev = aList->head; //������ ������������ ���� �� ���
			}
			else
			{
				//2. ���� 2 ��� ����� ��������
				if (aList->head->next != aList->head)
				{
					// (head) a b(tail)  + c => (head) a b c (tail)
					aList->tail->next = theNode; // b->c
					theNode->prev = aList->tail; // b<-c
					
					aList->tail = theNode;	// ����� ����
					
					aList->tail->next = aList->head; // c->a
					aList->head->prev = aList->tail; // c<-a
				}
				else
				{
					//3. ���
					// (head) a  +  b  =>  (head) a b (tail)
					aList->tail = theNode;
					aList->head->next = aList->head->prev = aList->tail;
					aList->tail->next = aList->tail->prev = aList->head;	
				}
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	return theResult;
}


void PrintList(IntList *aList) //���� ��������� �������
{
	printf("List with count (%d):   ", aList->count);
	IntNode *theNode = aList->head;
	do
	{
		printf("(%d) ", theNode->value);
		theNode = theNode->next;
	
	}while (aList->head != theNode);
	
	printf ("\n");
}




IntNode *createIntNodeWithValue(int anIntValue)//������ ���'��� � ���� �������� ���
{
	IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = anIntValue;
	}
	
	return theNode;
}


// ���������  �������� ��� ������ ������ � �������� ��������� ������
int DeleteIntValueAtIndex(IntList *aList, int anIndex)
{
	int theResult = -1;
	
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}
	
	IntNode *theNodeToDelete = FindTheNodeAtIndex(aList, anIndex);
	
	//1. ���� � ������ 1 ������� {a} => {empty}
	if (aList->count == 1)	
	{
		free(theNodeToDelete);
		aList->count = 0;
		aList->head = NULL;
		aList->tail = NULL;
		theResult = 0;
		return theResult;
	}
	
	//2. ��� ������: {a, b, c} => {b, c}
	if (theNodeToDelete == aList->head)	
	{
		IntNode *theNextNode = aList->head->next;
		aList->head = theNextNode; 		//���� ������
		aList->head->next = theNextNode->next; 
		aList->head->prev = aList->tail;
		
		aList->tail->next = aList->head;
		theResult = 0;
	}
	else
	//3. ��� ������ {a, b, c} => {a, b}
	if (theNodeToDelete == aList->tail)	
	{
		aList->tail = aList->tail->prev; //���� ������
		aList->tail->next = aList->head;
		aList->head->prev = aList->tail;
		theResult = 0;
	}
	else
	//3. ��� ��������� � �������� {a, b, c} => {a, c} 
	{
		theNodeToDelete->prev->next = theNodeToDelete->next;
		theNodeToDelete->next->prev = theNodeToDelete->prev;
		theResult = 0;
	}
	
	free(theNodeToDelete);
	aList->count--;;
	return theResult;
}

void DeleteMultiplesElements(IntList *aList, int N)//������� N��� ������
{
	if (NULL == aList || N > aList->count - 1 || N < 1)//������� �� �� �� � ������ �������� ����� ��� N
	{
		return;
	}
	
	int step;					 
	int IndexToDelete, iteration;
	
	while (aList->count >= N )//���� ������� �������� ����� N �������� ���������
	{
		printf("\nAfter %d iteration:\n", iteration);
		PrintList (aList);
		step = 0;
		
		//������� ����� �������
		do
		{
			IndexToDelete = N * (step+1) - step - 1;//�������� ������ ���� ���� ���������
			DeleteIntValueAtIndex(aList, IndexToDelete ); //��������
			step ++;
			
		}	while( aList->count - 1 >= IndexToDelete );
		
		iteration ++;
	}
		printf("\nAfter %d iteration:\n", iteration); 
		PrintList (aList); //������� ���������
}

