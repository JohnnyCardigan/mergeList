#ifndef LAB04_PH_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
	int num;
	struct node* pN;
}Node;


Node * initList(int* numList, int listSize);

Node * mergeLists(Node * pL1, Node * pL2);






#define LAB04_PH_H


#endif // !LAB04_PH_H
