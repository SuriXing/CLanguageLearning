#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_isb_students.h"
#include "c_double_linked_list.h"

IsbStudentDoubleList* DLCreateNode(IsbStudent student)
{
    IsbStudentDoubleList* newNode = (IsbStudentDoubleList*)malloc(sizeof(IsbStudentDoubleList));

    newNode->prev = NULL;
    newNode->next = NULL;
    strncpy(newNode->student.first_name, student.first_name, sizeof(newNode->student.first_name)-1);
    newNode->student.first_name[sizeof(newNode->student.first_name)-1] = '\0';

    strncpy(newNode->student.last_name, student.last_name, sizeof(newNode->student.last_name)-1);
    newNode->student.last_name[sizeof(newNode->student.last_name)-1] = '\0';

    newNode->student.gender = student.gender;
    newNode->student.math_score = student.math_score;
    newNode->student.language_usage_score = student.language_usage_score;
    newNode->student.reading_score = student.reading_score;

    // memcpy((void*)&(newNode->student), (void*)&student, sizeof(Student));
    return newNode;
}

IsbStudentDoubleList* DLCreateNode2(IsbStudent student)
{
    IsbStudentDoubleList* newNode = (IsbStudentDoubleList*)malloc(sizeof(IsbStudent));

    newNode->prev = NULL;
    newNode->next = NULL;

    strncpy(newNode->student.first_name, student.last_name, sizeof(newNode->student.first_name)-1);
    newNode->student.first_name[sizeof(newNode->student.first_name)-1] = '\0';

    strncpy(newNode->student.last_name, student.last_name, sizeof(newNode->student.last_name)-1);
    newNode->student.last_name[sizeof(newNode->student.last_name)-1] = '\0';

    newNode->student.gender = student.gender;
    newNode->student.math_score = student.math_score;
    newNode->student.language_usage_score = student.language_usage_score;
    newNode->student.reading_score = student.reading_score;

    //memcpy((void*)&(newNode->student), (void*)&student, sizeof(student));

    return newNode;
}

IsbStudentDoubleList* DLInsertNode(IsbStudentDoubleList* currentNode, IsbStudentDoubleList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    return currentNode;
}

IsbStudentDoubleList* DLInsertNode2(IsbStudentDoubleList* currentNode, IsbStudentDoubleList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    //newNode->prev = currentnode;

    return currentNode;
}

IsbStudentDoubleList* DLcopyNode(IsbStudentDoubleList* cpyNode)
{
    if (NULL == cpyNode)
    {
        return NULL;
    }

    return DLCreateNode(cpyNode->student);
}

IsbStudentDoubleList* DLreverseNode(IsbStudentDoubleList* currentNode, IsbStudentDoubleList* reverseList)
{
    IsbStudentDoubleList* temp = NULL;

    if ((NULL == currentNode) || (NULL == reverseList))
    {
        return currentNode;
    }

    reverseList = currentNode;

    while (currentNode != NULL)
    { 
        currentNode = currentNode->next;
        reverseList->prev = currentNode;
        reverseList->next = temp;
        temp = currentNode->next;
    }

    return reverseList;
}

IsbStudentDoubleList* DLreverseNode2(IsbStudentDoubleList* currentNode, IsbStudentDoubleList* reverseList)
{
    IsbStudentDoubleList* temp = NULL;

    if ((NULL == currentNode) || (NULL == reverseList))
    {
        return currentNode;
    }

    reverseList = currentNode;

    while (currentNode != NULL)
    { 
        currentNode = currentNode->next;
        reverseList->prev = currentNode;
        reverseList->next = temp;
        temp = currentNode->next;
    }

    return reverseList;
}

// 打印链表中的所有学生信息
void DLprintList(IsbStudentDoubleList* head)
{
    IsbStudentDoubleList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s\n", pIndex->student.first_name);

        pIndex = pIndex->next;
    }

}

void printReverseList(IsbStudentDoubleList* head)
{
    IsbStudentDoubleList* pIndex = head;

    while (NULL != pIndex->next)
    {
        pIndex = pIndex -> next;
    }

    while (NULL != pIndex)
    {
        printf("%s\n", pIndex->student.first_name);
        pIndex = pIndex->prev;
    }
}

IsbStudentDoubleList* createReverseList(IsbStudentDoubleList* head)
{
    DLprintList(head);

    IsbStudentDoubleList* pIndex = head;

    while (NULL != pIndex->next)
    {
        pIndex = pIndex -> next;
    }

    IsbStudentDoubleList* pIndent = DLCreateNode(pIndex->student);
    IsbStudentDoubleList* newHead = pIndent;

    while (NULL != pIndex->prev)
    {
        IsbStudentDoubleList* node = DLCreateNode(pIndex->prev->student);
        DLInsertNode(pIndent, node);
        pIndent = pIndent->next;
        pIndex = pIndex->prev;
    }

    DLprintList(newHead);

    return newHead;
}

IsbStudentDoubleList* DLFindNode(IsbStudentDoubleList* head, const char* first_name)
{
    while (head != NULL)
    {
        if ((strcmp(head->student.first_name, first_name)) == 0)
        {
            return head;
        }

        head = head->next;
    }

    printf("not found\n");
    return NULL;
}

void DLFreeList(IsbStudentDoubleList* head)
{
    if (NULL == head)
    {
        return ;
    }
    
    IsbStudentDoubleList* curr = head;
    while (NULL != curr)
    {   
        IsbStudentDoubleList* temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void freeList2(IsbStudentDoubleList* head)
{
    if (NULL == head)
    {
        return ;
    }
    
    IsbStudentDoubleList* curr = head;
    while (NULL != curr)
    {   
        IsbStudentDoubleList* temp = curr->next;
        free(curr);
        curr = temp;
    }
}

IsbStudentDoubleList* DLdeleteNode(IsbStudentDoubleList* head, const char* first_name)
{
    //maria.next = rachel.next;
    //rachel.next.prev = maria;
    //(rachel);

    if (NULL == head)
    {
        return NULL;
    }
    
    IsbStudentDoubleList* student = DLFindNode(head, first_name);
    IsbStudentDoubleList* newhead = head;

    if (student->next != NULL)
    {
        if (student->prev != NULL)
        {
            student->prev->next = student->next;
            student->next->prev = student->prev;
        }
        else
        {
            student->next->prev = NULL;
            newhead = student->next;
        }
    }
    else
    {
        student->prev->next = NULL;
    }

    student->next = NULL;
    student->prev = NULL;

    return newhead;
}

IsbStudentDoubleList* DLdeleteNode2(IsbStudentDoubleList* head, const char* first_name)
{
    if (NULL == head)
    {
        return NULL;
    }
    
    IsbStudentDoubleList* student = DLFindNode(head, first_name);
    IsbStudentDoubleList* newhead = head;

    if (student->next != NULL)
    {
        if (student->prev != NULL)
        {
            student->prev->next = student->next;
            student->next->prev = student->prev;
        }
        else
        {
            student->next->prev = NULL;
            newhead = student->next;
        }
    }
    else
    {
        student->prev->next = NULL;
    }

    student->next = NULL;
    student->prev = NULL;

    return newhead;
}

IsbStudentDoubleList* connectTwoLists(IsbStudentDoubleList* dest, IsbStudentDoubleList* src)
{
    IsbStudentDoubleList* copy = dest;

    if ((NULL == dest) || (NULL == src))
    {
        return NULL;
    }

    while (NULL != dest->next)
    {
        dest = dest->next;
    }

    dest->next = src;
    src->prev = dest;
 
    while (NULL != src->next)
    {
        src = src->next;
    }

    DLprintList(copy);
    return dest;
}

int c_double_linked_list_main()
{
    IsbStudent Suri;
    IsbStudent Maria;
    IsbStudent Rachel;
    IsbStudent Neinei;
    IsbStudent Angelina;

    strncpy(Suri.first_name, "Suri", sizeof(Suri.first_name)-1);
    Suri.first_name[sizeof(Suri.first_name)-1] = '\0';

    strncpy(Maria.first_name, "Maria", sizeof(Maria.first_name) - 1);
    Maria.first_name[sizeof(Maria.first_name)-1] = '\0';

    strncpy(Rachel.first_name, "Rachel", sizeof(Rachel.first_name)-1);
    Rachel.first_name[sizeof(Rachel.first_name)-1] = '\0';

    strncpy(Neinei.first_name, "Neinei", sizeof(Neinei.first_name)-1);
    Neinei.first_name[sizeof(Neinei.first_name)-1] = '\0';

    strncpy(Angelina.first_name, "Angelina", sizeof(Angelina.first_name)-1);
    Angelina.first_name[sizeof(Angelina.first_name)-1] = '\0';

    IsbStudentDoubleList* pSuri = DLCreateNode(Suri);
    IsbStudentDoubleList* pMaria = DLCreateNode(Maria);
    IsbStudentDoubleList* pRachel = DLCreateNode(Rachel);
    IsbStudentDoubleList* pNeinei = DLCreateNode(Neinei);
    IsbStudentDoubleList* pAngelina = DLCreateNode(Angelina);

    DLInsertNode(pSuri, pMaria);
    DLInsertNode(pMaria, pRachel);
    DLInsertNode(pRachel, pNeinei);
    DLInsertNode(pNeinei, pAngelina);

    IsbStudent Alina;
    IsbStudent Xiao;

    strncpy(Alina.first_name, "Alina", sizeof(Alina.first_name)-1);
    Alina.first_name[sizeof(Alina.first_name)-1] = '\0';

    strncpy(Xiao.first_name, "Xiao", sizeof(Xiao.first_name) - 1);
    Xiao.first_name[sizeof(Xiao.first_name)-1] = '\0';

    IsbStudentDoubleList* pAlina = DLCreateNode(Alina);
    IsbStudentDoubleList* pXiao = DLCreateNode(Xiao);

    DLInsertNode(pAlina, pXiao);

    /*
    DLFindNode(pSuri, "Jenny");
    
    printf("\n");

    DLprintList(pSuri);

    DLdeleteNode(pSuri, "Maria");

    printf("\n");

    DLprintList(pSuri);

    DLcopyNode(pSuri);

    printf("\n");

    DLprintList(pSuri);
    printReverseList(pSuri);

    createReverseList(pSuri);
    */

    connectTwoLists(pSuri, pAlina);
    
    //DLprintList(DLInsertNode(pSuri, DLInsertNode(pMaria, pRachel)));
    return 0;
}