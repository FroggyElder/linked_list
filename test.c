#include "linked_list.h"
#include <string.h>

void studentPrint (struct student stu) {
    printf("[%s:%d] ",stu.name,stu.age);
}

int studentFullCmp (struct student a,struct student b) {
    if (a.age==b.age) return strcmp(a.name,b.name);
    else return a.age-b.age;
}

int studentAgeCmp (struct student a,struct student b) {
    return a.age-b.age;
}

int studentAgeRCmp (struct student a,struct student b) {
    return b.age-a.age;
}

int main () {
    struct ll_node* list0 = llNewHead();

    struct student temp_student;
    strcpy(temp_student.name,"Whatever"); temp_student.age = 22; llInsertAfter(list0,temp_student);
    strcpy(temp_student.name,"Mary"); temp_student.age = 34; llInsertAfter(list0,temp_student);
    strcpy(temp_student.name,"Josh"); temp_student.age = 45; llInsertAfter(list0,temp_student);
    strcpy(temp_student.name,"Walta"); temp_student.age = 55; llInsertAfter(list0,temp_student);
    strcpy(temp_student.name,"Jessie"); temp_student.age = 24; llInsertAfter(list0,temp_student);
    llPrint(list0,studentPrint);

    llSort(list0,studentAgeCmp,NULL);
    llPrint(list0,studentPrint);

    // temp_student.age = 55;
    // strcpy(temp_student.name,"Walta");
    // llDeleteByVal(list0,temp_student,studentFullCmp);
    // llPrint(list0,studentPrint);

    // temp_student.age = 24;
    // llDeleteByVal(list0,temp_student,studentAgeCmp);
    // llPrint(list0,studentPrint);

    // llReverse(list0);
    // llPrint(list0,studentPrint);

    struct ll_node* list1 = llNewHead();

    strcpy(temp_student.name,"Tony"); temp_student.age = 78; llInsertAfter(list1,temp_student);
    strcpy(temp_student.name,"Mike"); temp_student.age = 34; llInsertAfter(list1,temp_student);
    strcpy(temp_student.name,"Kim"); temp_student.age = 14; llInsertAfter(list1,temp_student);
    llPrint(list1,studentPrint);

    llSortedMerge(list0,list1,studentAgeCmp);
    llPrint(list0,studentPrint);

    llDestoryList(list0);
}