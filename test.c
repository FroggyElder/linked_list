#include "linked_list.h"
#include <string.h>

void studentPrint (struct student stu) {
    printf("[%s:%d] ",stu.name,stu.age);
}

int studentFullCmp (struct student a,struct student b) {
    if(a.age-b.age==0) return strcmp(a.name,b.name);
    else return a.age-b.age;
}

int studentAgeCmp (struct student a,struct student b) {
    return a.age-b.age;
}

int main () {
    struct ll_node* list0 = llNewHead();

    for (int i=5;i>=0;--i) {
        struct student temp;
        temp.age = 20+i;
        sprintf(temp.name,"clone%d",i);
        llInsertAfter(list0,temp);
    }

    llPrint(list0,studentPrint);

    struct student temp_student;
    temp_student.age = 23;
    strcpy(temp_student.name,"clone3");
    llDeleteByVal(list0,temp_student,studentFullCmp);
    llPrint(list0,studentPrint);

    temp_student.age = 25;
    llDeleteByVal(list0,temp_student,studentAgeCmp);

    llPrint(list0,studentPrint);
}