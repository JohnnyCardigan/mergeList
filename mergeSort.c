#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
//#include <pussy.h>

#define fucktwatshit 69

typedef struct node
{
    int num;
    struct node* next;
}Node;

void printList(Node* list)
{
    while (list != NULL)
    {
        printf("%d -> ",list->num);
        list = list->next;
    }
    printf("N\n");
    return;
}

Node* new_Node(int i)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = i;
    newNode->next = NULL;
    return newNode;
}

Node* initList(int* intarray, int nints)
{
    if (nints==0)
        return NULL;
    
    Node* head = new_Node(intarray[0]);
    Node* newNode = head;
    
    for (int i = 1; i < nints; i++)
    {
        newNode->next = new_Node(intarray[i]);
        newNode = newNode->next;
    }
    return head;
}

void deleteList(Node* list)
{
    Node* head = list;
    while (head != NULL)
    {
        Node* toDelete = head;
        head = head->next;
        free(toDelete);
    }
    return;
}

Node* mergeLists(Node* list1, Node* list2)
{
    Node* mergedHead = NULL;
    
    if (list1 == NULL || list2 == NULL)
    {
        mergedHead = list1 == NULL ? list2 : list1;
        return mergedHead;
    }
    
    if (list1->num <= list2->num)
    {
        mergedHead = list1;
        list1 = list1->next;
    }
    else
    {
        mergedHead = list2;
        list2 = list2->next;
    }
    Node* mergedTail = mergedHead;
    
    while (list1 && list2)
    {
        if (list1->num <= list2->num)
        {
            mergedTail->next = list1;
            list1 = list1->next;
        }
        else
        {
            mergedTail->next = list2;
            list2 = list2->next;
        }
        mergedTail = mergedTail->next;
    }
    mergedTail->next = (list1 == NULL ? list2 : list1);
    
    return mergedHead;
}

int listsize(Node* list)
{
    int size = 0;
    Node* itr = list;
    while (itr!=NULL)
    {
        size++;
        itr = itr->next;
    }
    return size;
}


Node* mergeSort(Node* list)//WE GOIN RECURSIVE BITCHES
{
    int size = listsize(list);
    if (size <= 1) return list;//BASE CASE MOFOES
    
    // Cut the list in half, with the second half's head as rightHalf
    Node* halfPtr = list;
    for(int i = 0; i < size/2-1; i++)
        halfPtr = halfPtr->next;
        
    Node* rightHalf = halfPtr->next;
    halfPtr->next = NULL; // WHAT MAKES YOU THINK I WON"T CUT YOU IN HALF??
    
    list = mergeSort(list);
    rightHalf = mergeSort(rightHalf);
    return mergeLists(list,rightHalf);
}


int main()///***!!!HERE IS MAIN*******************
{
    int l1[3] = {1,5,7},
        l2[4] = {2,3,9,21};
    
    Node* list1 = initList(l1,3);
    Node* list2 = initList(l2,4);

    Node* merged = mergeLists(list1,list2);
    //printList(merged);
    //printf("%d\n",listsize(merged));
    deleteList(merged);

    int l3[8] = {4,2,7,9,21,55,3,12};
    Node* list3 = initList(l3,8);
    list3 = mergeSort(list3);
    printList(list3);

    deleteList(list3);

    return 0;
}