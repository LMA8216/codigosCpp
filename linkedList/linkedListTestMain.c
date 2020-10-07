#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
    
};

void printList(struct ListNode *n){

    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    
    puts("\r");

}

void insertLinkedList(struct ListNode **head, int data, int position){

    int k = 1;
    struct ListNode *p,*q, *newNode;
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(!newNode){
        printf("Memory Error");
        return;
    }

    newNode->data = data;
    p = *head;

    if (position == 1)
    {
        newNode->next = p;
        *head = newNode;
    }
    else
    {
        while ((p != NULL) && (k < position))
        {   
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
        
    }
}




void main(){

    struct ListNode *first, *second, *third;
    struct ListNode **head;

    first = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));



    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    printList(first);

   // insertLinkedList()
}