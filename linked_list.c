#include "linked_list.h"

struct ll_node* llNewNode (LL_ELEM_TYPE data) {
    struct ll_node* new_node = (struct ll_node*)malloc(sizeof(struct ll_node));
    if (new_node==NULL) {
        perror ("error when mallocing for new node");
        return NULL;
    }

    new_node->data = data;

    return new_node;
}

struct ll_node* llNewHead () {
    LL_ELEM_TYPE empty;
    struct ll_node* new_node = llNewNode(empty);
    if (new_node==NULL) return NULL;

    new_node->next = NULL;
    return new_node;
}

bool llDestoryList (struct ll_node* head) {
    if (head==NULL) return false;

    struct ll_node* current = head;
    struct ll_node* next = head->next;

    while (1) {
        next = current->next;
        free(current);
        current = next;
    }

    return true;
}

bool llInsertAfter (struct ll_node* node,LL_ELEM_TYPE data) {
    if (node==NULL) return false;

    struct ll_node* new_node = llNewNode(data);
    if(new_node==NULL) return false;

    new_node->next = node->next;
    node->next = new_node;

    return true;
}

bool llInsertAtTail (struct ll_node* node,LL_ELEM_TYPE data) {
    if (node==NULL) return false;

    struct ll_node* p = node;
    while(p->next!=NULL) p=p->next;

    return llInsertAfter(p,data);
}

bool llDeleteByVal (struct ll_node* head,LL_ELEM_TYPE data,int (* llCmp)(LL_ELEM_TYPE a,LL_ELEM_TYPE b)) {
    if(head == NULL||head->next==NULL) return false;

    struct ll_node* p = head->next;
    while (llCmp(p->next->data,data)!=0) {
        p=p->next;
        if(p->next==NULL) return false;
    }

    struct ll_node* q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

void llPrint (struct ll_node* head,void (* print) (LL_ELEM_TYPE data)){
    if (head==NULL) return;

    struct ll_node* p = head->next;
    while (p!=NULL) {
        print(p->data);
        p=p->next;
    }

    printf("\n");
}