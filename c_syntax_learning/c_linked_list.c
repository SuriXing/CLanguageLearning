#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum _Gender
{
	MALE,
	FEMALE,
} Gender;

typedef struct _IsbStudent
{
	char first_name[32];
	char last_name[32];
	Gender gender;
	unsigned int math_score;
	unsigned int language_usage_score;
	unsigned int reading_score;
} IsbStudent;

typedef struct _IsbStudentList
{
    struct _IsbStudentList* prev;
    struct _IsbStudentList* next;

    IsbStudent student;
} IsbStudentList;

IsbStudentList* createNode(IsbStudent student)
{
    IsbStudentList* newNode = (IsbStudentList*)malloc(sizeof(IsbStudentList));

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

IsbStudentList* createNode2(IsbStudent student)
{
    IsbStudentList* newNode = (IsbStudentList*)malloc(sizeof(IsbStudent));

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

IsbStudentList* insertNode(IsbStudentList* currentNode, IsbStudentList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    return currentNode;
}

IsbStudentList* insertNode2(IsbStudentList* currentNode, IsbStudentList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    return currentNode;
}

IsbStudentList* copyNode(IsbStudentList* cpyNode)
{
    if (NULL == cpyNode)
    {
        return NULL;
    }

    return createNode(cpyNode->student);
}

IsbStudentList* reverseNode(IsbStudentList* currentNode, IsbStudentList* reverseList)
{
    IsbStudentList* temp = NULL;

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
void printList(IsbStudentList* head)
{
    IsbStudentList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s\n", pIndex->student.first_name);

        pIndex = pIndex->next;
    }

}

void printReverseList(IsbStudentList* head)
{
    IsbStudentList* pIndex = head;

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

/*
// 在链表头部插入节点
LinkedList* insertAtHead(LinkedList* head, IsbStudent student);

// 在链表尾部插入节点
LinkedList* insertAtTail(LinkedList* head, IsbStudent student);

// 查找具有特定名字的学生节点
LinkedList* findNode(LinkedList* head, const char* first_name, const char* last_name);

// 释放链表占用的内存

*/

IsbStudentList* findNode(IsbStudentList* head, const char* first_name)
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

void freeList(IsbStudentList* head)
{
    if (NULL == head)
    {
        return ;
    }
    
    IsbStudentList* curr = head;
    while (NULL != curr)
    {   
        IsbStudentList* temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void freeList2(IsbStudentList* head)
{
    if (NULL == head)
    {
        return ;
    }
    
    IsbStudentList* curr = head;
    while (NULL != curr)
    {   
        IsbStudentList* temp = curr->next;
        free(curr);
        curr = temp;
    }
}

IsbStudentList* deleteNode(IsbStudentList* head, const char* first_name)
{
    //maria.next = rachel.next;
    //rachel.next.prev = maria;
    //freeList(rachel);

    if (NULL == head)
    {
        return NULL;
    }
    
    IsbStudentList* student = findNode(head, first_name);
    IsbStudentList* newhead = head;

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
    freeList(student);

    return newhead;
}

IsbStudentList* deleteNode2(IsbStudentList* head, const char* first_name)
{
    if (NULL == head)
    {
        return NULL;
    }
    
    IsbStudentList* student = findNode(head, first_name);
    IsbStudentList* newhead = head;

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
    freeList(student);

    return newhead;
}

int main(void)
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

    IsbStudentList* pSuri = createNode(Suri);
    IsbStudentList* pMaria = createNode(Maria);
    IsbStudentList* pRachel = createNode(Rachel);
    IsbStudentList* pNeinei = createNode(Neinei);
    IsbStudentList* pAngelina = createNode(Angelina);

    insertNode(pSuri, pMaria);
    insertNode(pMaria, pRachel);
    insertNode(pRachel, pNeinei);
    insertNode(pNeinei, pAngelina);

    findNode(pSuri, "Jenny");
    /*
    printf("\n");

    printList(pSuri);

    deleteNode(pSuri, "Maria");

    printf("\n");

    printList(pSuri);

    copyNode(pSuri);

    printf("\n");
    */
    printList(pSuri);
    printReverseList(pSuri);
    
    //printList(insertNode(pSuri, insertNode(pMaria, pRachel)));
    return 0;
}