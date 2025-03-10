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
/*
// 在链表头部插入节点
LinkedList* insertAtHead(LinkedList* head, IsbStudent student);

// 在链表尾部插入节点
LinkedList* insertAtTail(LinkedList* head, IsbStudent student);

// 删除指定学生信息的节点
LinkedList* deleteNode(LinkedList* head, IsbStudent student);

// 查找具有特定名字的学生节点
LinkedList* findNode(LinkedList* head, const char* first_name, const char* last_name);

// 释放链表占用的内存

*/

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


int main(void)
{
    IsbStudent Suri;
    IsbStudent Maria;
    IsbStudent Rachel;

    strncpy(Suri.first_name, "Suri", sizeof(Suri.first_name)-1);
    Suri.first_name[sizeof(Suri.first_name)-1] = '\0';

    strncpy(Maria.first_name, "Maria", sizeof(Maria.first_name) - 1);
    Maria.first_name[sizeof(Maria.first_name)-1] = '\0';

    strncpy(Rachel.first_name, "Rachel", sizeof(Rachel.first_name)-1);
    Rachel.first_name[sizeof(Rachel.first_name)-1] = '\0';

    IsbStudentList* pSuri = createNode(Suri);
    IsbStudentList* pMaria = createNode(Maria);
    IsbStudentList* pRachel = createNode(Rachel);

    insertNode(pSuri, pMaria);
    insertNode(pMaria, pRachel);

    printList(pSuri);
    
    //printList(insertNode(pSuri, insertNode(pMaria, pRachel)));
    return 0;
}