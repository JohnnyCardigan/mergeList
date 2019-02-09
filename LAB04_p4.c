#include "LAB04_p4.h"


Node * initList(int* numList, int listSize)
{
	Node* pHead = NULL, *pMem = NULL, *pEnd = NULL;

	//*****!!!INSERTS AT END!!!*****!!!INSERTS AT END!!!*****!!!INSERTS AT END!!!

	for (int i = 0; i < listSize; i++)
	{
		if (!pHead)
		{
			pHead = (Node*)malloc(sizeof(Node));
			pHead->num = *(numList + i);
			pHead->pN = NULL;
			pEnd = pHead;
		}
		else
		{
			pMem = (Node*)malloc(sizeof(Node));
			pMem->num = *(numList + i);
			pMem->pN = NULL;
			pEnd->pN = pMem;
			pEnd = pMem;
		}
	}

	return pHead;
}


Node * mergeLists(Node * pL1, Node * pL2)
{
	Node* pHead = NULL;//return variable
	Node* pCur1 = pL1, *pPrev1 = NULL, *pCur2 = pL2, *pPrev2 = NULL;

	//check for empty lists
	if (!pL1)
	{
		return pL2;//if both lists empty, returns NULL
	}
	else if (!pL2)
	{
		return pL1;
	}

	if (pL1->num<pL2->num)//set pHead if NULL
	{
		pHead = pL1;
	}
	else//set pHead if NULL
	{
		pHead = pL2;
	}


	while (pCur1 && pCur2)//loop until end of either list is reached
	{
		if (pCur1->num <= pCur2->num)//value on pCur1 comes next
		{
			while (pCur1 && pCur1->num <= pCur2->num)
			{
				pPrev1 = pCur1;
				pCur1 = pCur1->pN;
			}
			pPrev1->pN = pCur2;
		}
		else//value on pCur2 comes next
		{
			while (pCur2 && pCur2->num <= pCur1->num)
			{
				pPrev2 = pCur2;
				pCur2 = pCur2->pN;
			}
			pPrev2->pN = pCur1;
		}
	}

	return pHead;

}