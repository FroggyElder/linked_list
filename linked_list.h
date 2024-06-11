#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef int LL_ELEM_TYPE;
typedef struct student {
    char name[32];
    int age;
}LL_ELEM_TYPE;

struct ll_node {
    LL_ELEM_TYPE data;
    struct ll_node* next;
};

struct ll_node* llNewNode (LL_ELEM_TYPE data);

struct ll_node* llNewHead ();

bool llDestoryList (struct ll_node* head);

bool llInsertAfter (struct ll_node* node,LL_ELEM_TYPE data);

bool llInsertAtTail (struct ll_node* node,LL_ELEM_TYPE data);

bool llDeleteByVal (struct ll_node* head,LL_ELEM_TYPE data,int (* llCmp)(LL_ELEM_TYPE a,LL_ELEM_TYPE b));

bool llReverse (struct ll_node* head);

void llPrint (struct ll_node* head,void (* print) (LL_ELEM_TYPE data));

#endif //_LINKED_LIST_H