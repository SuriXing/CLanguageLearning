#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_isb_students.h"
#include "c_single_linked_list.h"

IsbStudentSingleList* SLCreateNode(IsbStudent student)
{
    IsbStudentSingleList* newNode = (IsbStudentSingleList*)malloc(sizeof(IsbStudentSingleList));

    newNode->next = NULL;

    memcpy((void*)&(newNode->student), (void*)&student, sizeof(student));

    return newNode;
}

void SLFreeNode(IsbStudentSingleList* node)
{
    if (NULL == node)
    {
        return;
    }

    free(node);
}

void SLPrintList(IsbStudentSingleList* head)
{
    IsbStudentSingleList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s %d\n", pIndex->student.first_name, pIndex->student.math_score);

        pIndex = pIndex->next;
    }
}

void SLPrintList2(IsbStudentSingleList* head)
{
    IsbStudentSingleList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s %d\n", pIndex->student.first_name, pIndex->student.math_score);

        pIndex = pIndex->next;
    }
}

IsbStudentSingleList* SLInsertNode(IsbStudentSingleList* currentNode, IsbStudentSingleList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
    return currentNode;
}

IsbStudentSingleList* SLInsertNode2(IsbStudentSingleList* currentNode, IsbStudentSingleList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
    return currentNode;
}

IsbStudentSingleList* SLCopyNode(IsbStudentSingleList* copyNode)
{
    if (NULL == copyNode)
    {
        return NULL;
    }

    return SLCreateNode(copyNode->student);
}

IsbStudentSingleList* SLCopyList(IsbStudentSingleList* copyList)
{
    if (NULL == copyList)
    {
        return NULL;
    }

    IsbStudentSingleList dummyHead;
    dummyHead.next = NULL;

    IsbStudentSingleList* newList = &dummyHead;
    while (copyList != NULL)
    {
        SLInsertNode(newList, SLCopyNode(copyList));

        copyList = copyList->next;
        newList = newList->next;
    }

    return dummyHead.next;
}

IsbStudentSingleList* SLCopyList2(IsbStudentSingleList* copyList)
{
    if (NULL == copyList)
    {
        return NULL;
    }

    IsbStudentSingleList dummyHead;
    dummyHead.next = NULL;

    IsbStudentSingleList* newList = &dummyHead;
    while (copyList != NULL)
    {
        SLInsertNode(newList, SLCopyNode(copyList));

        copyList = copyList->next;
        newList = newList->next;
    }

    return dummyHead.next;
}

IsbStudentSingleList* SLDeleteNode(IsbStudentSingleList* head, const char* first_name)
{
    if (NULL == head)
    {
        return NULL;
    }

    IsbStudentSingleList* curr = head;
    IsbStudentSingleList* prev = curr;

    while (curr != NULL)
    {
        if (strcmp(curr->student.first_name, first_name) == 0)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // no match
    if (curr == NULL)
    {
        return head;
    }

    // match first
    if (prev == curr)
    {
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    SLFreeNode(curr);

    return head;
}

IsbStudentSingleList* SLDeleteNode2(IsbStudentSingleList* head, const char* first_name)
{
    if ((NULL == head) || (NULL == first_name)) 
    {
        return NULL;
    }
    
    IsbStudentSingleList dummyHead;
    dummyHead.next = head;

    IsbStudentSingleList *prev = head;
    IsbStudentSingleList *curr = head;

    while (curr != NULL)
    {
        if (strcmp(curr->student.first_name, first_name) == 0)
        {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if (NULL != curr)
    {
        prev->next = curr->next;
    }

    return dummyHead.next;
}

IsbStudentSingleList* SLDeleteNode2ndVersion(IsbStudentSingleList* head, const char* first_name)
{
    if ((NULL == head) || (NULL == first_name)) 
    {
        return NULL;
    }

    IsbStudentSingleList dummyHead;
    dummyHead.next = head;

    IsbStudentSingleList *prev = head;
    IsbStudentSingleList *curr = head;

    while (curr != NULL)
    {
        if (strcmp(curr->student.first_name, first_name) == 0)
        {
            break;
            printf("Is this thingy working?\n");
        }

        prev = &dummyHead;
        curr = curr->next;
    }

    if (NULL != curr)
    {
        prev->next = curr->next;
        SLFreeNode(curr);
    }

    return dummyHead.next;
}

IsbStudentSingleList* SLDeleteNode2ndVersion2(IsbStudentSingleList* head, const char* first_name)
{
    if ((NULL == head) || (NULL == first_name)) 
    {
        return NULL;
    }

    IsbStudentSingleList dummyHead;
    dummyHead.next = head;

    IsbStudentSingleList *prev = head;
    IsbStudentSingleList *curr = head;

    while (curr != NULL)
    {
        if (strcmp(curr->student.first_name, first_name) == 0)
        {
            break;
            printf("Is this thingy working?\n");
        }

        prev = &dummyHead;
        curr = curr->next;
    }

    if (NULL != curr)
    {
        prev->next = curr->next;
        SLFreeNode(curr);
    }

    return dummyHead.next;
}

IsbStudentSingleList* SLListNode(IsbStudentSingleList* head, IsbStudentSingleList* student)
{
    if ((NULL == head) || (NULL == student))
    {
        return NULL;
    }

    IsbStudentSingleList* copy = head;

    while (copy->next != NULL)
    {
        if (student->student.math_score > copy->next->student.math_score)
        {
            /*
            head->next = student;
            student->next = head->next->next;
            */
           SLInsertNode(copy, student);
           break;
        }
        
        copy = copy->next;
    }

    return head;
}

IsbStudentSingleList* SLListNode2(IsbStudentSingleList* head, IsbStudentSingleList* student)
{
    if ((NULL == head) || (NULL == student))
    {
        return NULL;
    }

    IsbStudentSingleList* copy = head;

    while (copy->next != NULL)
    {
        if (student->student.math_score > copy->next->student.math_score)
        {
            /*
            head->next = student;
            student->next = head->next->next;
            */
           SLInsertNode(copy, student);
           break;
        }
        
        copy = copy->next;
    }

    return head;
}

int c_single_linked_list_main()
{
    IsbStudent Suri;
    IsbStudent Maria;
    IsbStudent Rachel;
    IsbStudent Angelina;
    IsbStudent Alina;
    IsbStudent Xiaoxiao;
    
    //IsbStudent Jenny;

    strncpy(Suri.first_name, "Suri", sizeof(Suri.first_name)-1);
    Suri.first_name[sizeof(Suri.first_name)-1] = '\0';
    Suri.math_score = 100;

    strncpy(Maria.first_name, "Maria", sizeof(Maria.first_name) - 1);
    Maria.first_name[sizeof(Maria.first_name)-1] = '\0';
    Maria.math_score = 99;

    strncpy(Rachel.first_name, "Rachel", sizeof(Rachel.first_name)-1);
    Rachel.first_name[sizeof(Rachel.first_name)-1] = '\0';
    Rachel.math_score = 98;

    strncpy(Alina.first_name, "Alina", sizeof(Alina.first_name)-1);
    Alina.first_name[sizeof(Alina.first_name)-1] = '\0';
    Alina.math_score = 97;

    strncpy(Angelina.first_name, "Angelina", sizeof(Angelina.first_name)-1);
    Angelina.first_name[sizeof(Angelina.first_name)-1] = '\0';
    Angelina.math_score = 96;

    strncpy(Xiaoxiao.first_name, "Xiaoxiao", sizeof(Xiaoxiao.first_name)-1);
    Xiaoxiao.first_name[sizeof(Xiaoxiao.first_name)-1] = '\0';
    Xiaoxiao.math_score = 95;

    /*
    strncpy(Jenny.first_name, "Jenny", sizeof(Jenny.first_name)-1);
    Jenny.first_name[sizeof(Jenny.first_name)-1] = '\0';
    Jenny.math_score = 96;
    */

    IsbStudentSingleList* pSuri = SLCreateNode(Suri);
    IsbStudentSingleList* pMaria = SLCreateNode(Maria);
    IsbStudentSingleList* pRachel = SLCreateNode(Rachel);
    IsbStudentSingleList* pAlina = SLCreateNode(Alina);
    IsbStudentSingleList* pAngelina = SLCreateNode(Angelina);
    IsbStudentSingleList* pXiaoxiao = SLCreateNode(Xiaoxiao);
    
    //IsbStudentSingleList* pJenny = SLCreateNode(Jenny);

    SLInsertNode(
        SLInsertNode(
            SLInsertNode(
                SLInsertNode(
                    SLInsertNode(pAngelina, pXiaoxiao), pAlina
                ), pRachel
            ), pMaria
        ),pSuri
    );

    SLPrintList(pSuri);

    IsbStudentSingleList* copiedList = SLCopyList(pSuri);

    printf("\n");
    SLPrintList(copiedList);

    return 0;
}