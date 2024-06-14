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

    while (current!=NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return true;
}

void llInsertBetween (struct ll_node* prev,struct ll_node* node,struct ll_node* next){
    if(prev==NULL||node==NULL) return;
    prev->next = node;
    node->next = next;
}

bool llInsertAfter (struct ll_node* node,LL_ELEM_TYPE data) {
    if (node==NULL) return false;

    struct ll_node* new_node = llNewNode(data);
    if(new_node==NULL) return false;

    llInsertBetween(node,new_node,node->next);

    return true;
}

bool llInsertAtTail (struct ll_node* node,LL_ELEM_TYPE data) {
    if (node==NULL) return false;

    struct ll_node* p = node;
    while(p->next!=NULL) p=p->next;

    return llInsertAfter(p,data);
}

void llDeleteNode (struct ll_node* prev, struct ll_node* node,struct ll_node* next) {
    if(prev==NULL) return;
    prev->next = next;
    free(node);
}

bool llDeleteByVal (struct ll_node* head,LL_ELEM_TYPE data,int (* llCmp)(LL_ELEM_TYPE a,LL_ELEM_TYPE b)) {
    if(head == NULL||head->next==NULL) return false;

    struct ll_node* p = head;
    while (llCmp(p->next->data,data)!=0) {
        p=p->next;
        if(p->next==NULL) return false;
    }

    llDeleteNode(p,p->next,p->next->next);
    return true;
}

bool llReverse (struct ll_node* head) {
    if(head==NULL) return false;
    if(head->next==NULL||head->next->next==NULL) return true;

    struct ll_node* prev = head->next;
    struct ll_node* current = prev->next;
    prev->next = NULL;
    while(1){
        struct ll_node* next = current->next;
        current->next = prev;
        if(next==NULL) break;
        prev=current;
        current=next;
    };

    head->next = current;
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

void llSort (struct ll_node* head,int (* llCmp)(LL_ELEM_TYPE a,LL_ELEM_TYPE b),struct ll_node* end) {
    if(head==NULL||head==end) return;
    if(head->next==end||head->next->next==end) return;

    //init 2 pointers
    struct ll_node* p = head->next;
    struct ll_node* q = p->next;
    struct ll_node* r = q->next;
    p->next = end;

    //go throuch all effective data after the first
    while (1) {
        if(llCmp(p->data,q->data)<0) llInsertBetween(p,q,p->next);
        else llInsertBetween(head,q,head->next);
        if(r==end) break;
        q = r;
        r = r->next;
    }

    llSort(head,llCmp,p->next);
    llSort(p,llCmp,end);
}

void llSortedMerge(struct ll_node* head0,struct ll_node* head1,int (* llCmp)(LL_ELEM_TYPE a,LL_ELEM_TYPE b)) {
    struct ll_node* p0 = head0;
    struct ll_node* p1 = head1;

    while (1) {
        while (llCmp(p1->next->data,p0->next->data)<=0){
            llInsertAfter(p0,p1->next->data);
            p1=p1->next;
            if(p1->next==NULL) return;
        }
        while (p0->next!=NULL&&llCmp(p1->next->data,p0->next->data)>0)
            p0=p0->next;

        if(p0->next==NULL&&p1->next!=NULL){
            do {
                llInsertAfter(p0,p1->next->data);
                p1=p1->next;
            }while (p1->next!=NULL);
            return;
        }
    }
}