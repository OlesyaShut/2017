#ifndef dk_tools_h
#define dk_tools_h



typedef struct aNode {
	int data;
	struct aNode *next;
}Node;


void CreateList(Node **head, Node **last);
void AddElementToList(Node **head, Node **last);
void addElement(Node **theNode, char val);
	void PrintEdge(Node **head, Node **last, int edge);
	void PrintRange(Node **head, Node **last, int a, int b);
	void PrintNOTRange(Node **head, Node **last, int a, int b);




#endif
