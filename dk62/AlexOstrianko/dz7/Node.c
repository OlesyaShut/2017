#include "tree.h"
#include "Node.h"
#include <stdlib.h>

void destroyNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

CharNode *createCharNodeWithValue(char aValue)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}

CharNode *findNodeWithValue(CharTree *aTree, char aValue)
{
	CharNode *theCurrentNode = NULL;
	
	if (NULL != aTree)
	{
		theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{				
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{			
				break;
			}
		}
	}
	return theCurrentNode;
}

void deleteNodeWithValue(CharTree *aTree, char aValue)
{
	if(NULL == aTree)
		return;
	CharNode *theParentNode = NULL;	
	CharNode *aNodeToDelete = aTree->root; //<! - start from root
	while (aValue != aNodeToDelete->value) //<! - walk through the tree
	{		
		theParentNode = aNodeToDelete;		
		aNodeToDelete = (aValue < aNodeToDelete->value)
					? aNodeToDelete->leftChild
					: aNodeToDelete->rightChild;
	
		if (NULL == aNodeToDelete)
		{	
			printf("Don't find :(\n");		
			return;
		}
	}
	if(aNodeToDelete->leftChild == NULL && aNodeToDelete->rightChild == NULL)
	{
		if(NULL != theParentNode)	
		{
			if(aNodeToDelete->value < theParentNode->value)
			{			
				theParentNode->leftChild = NULL;
			}
			if(aNodeToDelete->value > theParentNode->value)
			{
				theParentNode->rightChild = NULL;
			}	
		}
	}
	else
	{
		if(NULL == aNodeToDelete->leftChild)
		{
			if(NULL != theParentNode)	
			{
				if(aNodeToDelete->value < theParentNode->value)
				{			
					theParentNode->leftChild = aNodeToDelete->rightChild;
				}	
				if(aNodeToDelete->value > theParentNode->value)
				{
					theParentNode->rightChild = aNodeToDelete->rightChild;					
				}
			}
			else					
				aTree->root = aNodeToDelete->rightChild;				
		}
		else
		{
			if(NULL == aNodeToDelete->rightChild)
			{
				if(NULL != theParentNode)	
				{
					if(aNodeToDelete->value < theParentNode->value)
					{			
						theParentNode->leftChild = aNodeToDelete->leftChild;				
					}		
					if(aNodeToDelete->value > theParentNode->value)
					{
						theParentNode->rightChild = aNodeToDelete->leftChild;	
					}
				}
				else					
					aTree->root = aNodeToDelete->leftChild;	
			}
			else
			{
				CharNode *ParentOfReceiver = NULL;
				CharNode *Receiver = aNodeToDelete->rightChild;
				if(Receiver->leftChild == NULL && Receiver->rightChild == NULL)
				{
					if(NULL != theParentNode)	
					{		
						if(aNodeToDelete->value < theParentNode->value)
						{			
							theParentNode->leftChild = Receiver;
						}	
						if(aNodeToDelete->value > theParentNode->value)
						{
							theParentNode->rightChild = Receiver;					
						}
					}
					else					
						aTree->root = Receiver;								
					Receiver->leftChild = aNodeToDelete->leftChild;
				}
				else
				{
					if(Receiver->leftChild == NULL)
					{
						if(NULL != theParentNode)					
							theParentNode->rightChild = Receiver;					
						else					
							aTree->root = Receiver;								
						Receiver->leftChild = aNodeToDelete->leftChild;	
					}
					else
					{
						while(Receiver->leftChild != NULL)
						{
							ParentOfReceiver = Receiver;
							Receiver = Receiver->leftChild;
						}
						if(Receiver->rightChild != NULL)
							ParentOfReceiver->leftChild = Receiver->rightChild;	
						else
							ParentOfReceiver->leftChild = NULL;
						if(NULL != theParentNode)					
							theParentNode->rightChild = Receiver;					
						else					
							aTree->root = Receiver;								
						Receiver->leftChild = aNodeToDelete->leftChild;		
						Receiver->rightChild = aNodeToDelete->rightChild;
					}
				}														
			}
		}		
	}
	free(aNodeToDelete);	
	aTree->count--;
	printf("Deleted!\n");
}
