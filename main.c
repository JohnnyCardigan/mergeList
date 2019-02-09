#include "LAB04_p4.h"

int main(void)
{
	int list1[10] = { 1,3,5,7,9,11,13,15,17,19 };//list 1 values, !!!must be in ascending order!!!
	int list2[10] = { 2,4,6,8,10,12,14,16,18,20 };//list 2 values, !!!must be in ascending order!!!
	Node* pL1 = initList(list1, 10);//allocate dynamic memory for list 1 values
	Node* pL2 = initList(list2, 10);//allocate dynamic memory for list 2 values
	Node* pTemp = NULL;//multi-purpose temporary pointer
	//Node* pL1 = NULL;//set list 1 empty
	//Node* pL2 = NULL;//set list 2 empty



	//START***print list 1 if not empty****************************
	pTemp = pL1;
	while (pL1)
	{
		printf("%d -> ", pL1->num);
		pL1 = pL1->pN;
	}
	pL1 = pTemp;
	printf("\n\n");
	//END***print list 1 if not empty****************************


	
	//START***print list 2 if not empty****************************
	pTemp = pL2;
	while (pL2)
	{
		printf("%d -> ", pL2->num);
		pL2 = pL2->pN;
	}
	pL2 = pTemp;
	printf("\n\n");
	//END***print list 2 if not empty****************************



	//START***merge lists****************************************
	Node* pMerged = mergeLists(pL1, pL2);//merge list 1 and 2
	pL1 = NULL;
	pL2 = NULL;
	//END***merge lists******************************************



	//START***print merged list**********************************
	if (!pMerged)//print msg if merged list is empty
	{
		printf("Both lists empty.\n\n");
	}
	else//print merged list if not empty
	{
		while (pMerged)
		{
			printf("%d -> ", pMerged->num);
			pMerged = pMerged->pN;
		}
		printf("\n\n");
	}
	//END***print merged list************************************



	//START***free all dynamic memory used in program************
	while (pMerged)
	{
		pTemp = pMerged;
		pMerged = pMerged->pN;
		free(pTemp);
	}
	//END***free all dynamic memory used in program**************



	return 0;
}