#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_isb_students.h"

typedef struct _IsbStudentSingleList
{
    struct _IsbStudentSingleList* next;

    IsbStudent student;
} IsbStudentSingleList;

IsbStudentSingleList* createNode(IsbStudent student)
{
    IsbStudentSingleList* newNode = (IsbStudentSingleList*)malloc(sizeof(IsbStudentSingleList));

    newNode->next = NULL;

    memcpy((void*)&(newNode->student), (void*)&student, sizeof(student));

    return newNode;
}

void freeNode(IsbStudentSingleList* node)
{
    if (NULL == node)
    {
        return;
    }

    free(node);
}

void printList(IsbStudentSingleList* head)
{
    IsbStudentSingleList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s %d\n", pIndex->student.first_name, pIndex->student.math_score);

        pIndex = pIndex->next;
    }
}

void printList2(IsbStudentSingleList* head)
{
    IsbStudentSingleList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s %d\n", pIndex->student.first_name, pIndex->student.math_score);

        pIndex = pIndex->next;
    }
}

IsbStudentSingleList* insertNode(IsbStudentSingleList* currentNode, IsbStudentSingleList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
    return currentNode;
}

IsbStudentSingleList* insertNode2(IsbStudentSingleList* currentNode, IsbStudentSingleList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
    return currentNode;
}

IsbStudentSingleList* copyNode(IsbStudentSingleList* copyNode)
{
    if (NULL == copyNode)
    {
        return NULL;
    }

    return createNode(copyNode->student);
}

IsbStudentSingleList* copyList(IsbStudentSingleList* copyList)
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
        insertNode(newList, copyNode(copyList));

        copyList = copyList->next;
        newList = newList->next;
    }

    return dummyHead.next;
}

IsbStudentSingleList* copyList2(IsbStudentSingleList* copyList)
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
        insertNode(newList, copyNode(copyList));

        copyList = copyList->next;
        newList = newList->next;
    }

    return dummyHead.next;
}

IsbStudentSingleList* deleteNode(IsbStudentSingleList* head, const char* first_name)
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

    freeNode(curr);

    return head;
}

IsbStudentSingleList* deleteNode2(IsbStudentSingleList* head, const char* first_name)
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

IsbStudentSingleList* deleteNode2ndVersion(IsbStudentSingleList* head, const char* first_name)
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
        freeNode(curr);
    }

    return dummyHead.next;
}

IsbStudentSingleList* deleteNode2ndVersion2(IsbStudentSingleList* head, const char* first_name)
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
        freeNode(curr);
    }

    return dummyHead.next;
}

IsbStudentSingleList* listNode(IsbStudentSingleList* head, IsbStudentSingleList* student)
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
           insertNode(copy, student);
           break;
        }
        
        copy = copy->next;
    }

    return head;
}

IsbStudentSingleList* listNode2(IsbStudentSingleList* head, IsbStudentSingleList* student)
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
           insertNode(copy, student);
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

    IsbStudentSingleList* pSuri = createNode(Suri);
    IsbStudentSingleList* pMaria = createNode(Maria);
    IsbStudentSingleList* pRachel = createNode(Rachel);
    IsbStudentSingleList* pAlina = createNode(Alina);
    IsbStudentSingleList* pAngelina = createNode(Angelina);
    IsbStudentSingleList* pXiaoxiao = createNode(Xiaoxiao);
    
    //IsbStudentSingleList* pJenny = createNode(Jenny);

    insertNode(
        insertNode(
            insertNode(
                insertNode(
                    insertNode(pAngelina, pXiaoxiao), pAlina
                ), pRachel
            ), pMaria
        ),pSuri
    );

    printList(pSuri);

    IsbStudentSingleList* copiedList = copyList(pSuri);

    printf("\n");
    printList(copiedList);

    return 0;
}