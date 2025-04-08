#ifndef __C_DOUBLE_LINKED_LIST_H__
#define __C_DOUBLE_LINKED_LIST_H__

#include "c_isb_students.h"
typedef struct _IsbStudentDoubleList
{
    struct _IsbStudentDoubleList* prev;
    struct _IsbStudentDoubleList* next;

    IsbStudent student;
} IsbStudentDoubleList;


int c_double_linked_list_main();

IsbStudentDoubleList* DLCreateNode(IsbStudent student);
IsbStudentDoubleList* DLInsertNode(IsbStudentDoubleList* currentNode, IsbStudentDoubleList* new);
IsbStudentDoubleList* DLcopyNode(IsbStudentDoubleList* cpyNode);
IsbStudentDoubleList* DLreverseNode(IsbStudentDoubleList* currentNode, IsbStudentDoubleList* reverseList);

IsbStudentDoubleList* DLFindNode(IsbStudentDoubleList* head, const char* first_name);
IsbStudentDoubleList* DLdeleteNode(IsbStudentDoubleList* head, const char* first_name);

void DLprintList(IsbStudentDoubleList* head);
void DLFreeList(IsbStudentDoubleList* head);

#endif // __C_SINGLE_LINKED_LIST_H__