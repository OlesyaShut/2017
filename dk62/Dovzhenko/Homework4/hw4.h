#ifndef hw4.h
#define hw4.h

typedef struct position
{
	int x;
	int y;
	int z;
	int R;
}SpherePosition;

typedef struct List
{
	SpherePosition *spheres;
	int size;
	int currentSize;
	
}SphereList;

SphereList * createSphereList(int aSize);
void removeSphereList(SphereList *aSphere);
int createnewSphere(SphereList *aSphere, int x,int y,int z , int R);
float Squareareas(SpherePosition * theSphere);
void sorting_Inserts(SphereList *theSphere);
void bubble_Sort(SphereList *aSphere);
void selection_Sort(SphereList *aSphere);
//int switchh(int m);

#endif
