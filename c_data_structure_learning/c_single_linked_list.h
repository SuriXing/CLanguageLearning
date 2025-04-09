#ifndef __C_SINGLE_LINKED_LIST_H__
#define __C_SINGLE_LINKED_LIST_H__
#include "c_isb_students.h"

typedef struct _IsbStudentSingleList
{
    struct _IsbStudentSingleList* next;

    IsbStudent student;
} IsbStudentSingleList;

int c_single_linked_list_main();

void SLFreeNode(IsbStudentSingleList* node);
void SLPrintList(IsbStudentSingleList* head);
void SLPrintList2(IsbStudentSingleList* head);

IsbStudentSingleList* SLInsertNode(IsbStudentSingleList* currentNode, IsbStudentSingleList* newNode);
IsbStudentSingleList* SLInsertNode2(IsbStudentSingleList* currentNode, IsbStudentSingleList* newNode);

IsbStudentSingleList* SLCopyNode(IsbStudentSingleList* copyNode);

IsbStudentSingleList* SLCopyList(IsbStudentSingleList* copyList);
IsbStudentSingleList* SLCopyList2(IsbStudentSingleList* copyList);

IsbStudentSingleList* SLDeleteNode(IsbStudentSingleList* head, const char* first_name);
IsbStudentSingleList* SLDeleteNode2(IsbStudentSingleList* head, const char* first_name);

IsbStudentSingleList* SLDeleteNode2ndVersion(IsbStudentSingleList* head, const char* first_name);
IsbStudentSingleList* SLDeleteNode2ndVersion2(IsbStudentSingleList* head, const char* first_name);

IsbStudentSingleList* SLListNode(IsbStudentSingleList* head, IsbStudentSingleList* student);
IsbStudentSingleList* SLListNode2(IsbStudentSingleList* head, IsbStudentSingleList* student);

#endif // __C_SINGLE_LINKED_LIST_H__