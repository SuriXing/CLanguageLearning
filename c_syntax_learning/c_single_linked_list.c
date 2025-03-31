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
    struct _IsbStudentList* next;

    IsbStudent student;
} IsbStudentList;

IsbStudentList* createNode(IsbStudent student)
{
    IsbStudentList* newNode = (IsbStudentList*)malloc(sizeof(IsbStudentList));

    newNode->next = NULL;

    memcpy((void*)&(newNode->student), (void*)&student, sizeof(student));

    return newNode;
}

void freeNode(IsbStudentList* node)
{
    if (NULL == node)
    {
        return;
    }

    free(node);
}

void printList(IsbStudentList* head)
{
    IsbStudentList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s %d\n", pIndex->student.first_name, pIndex->student.math_score);

        pIndex = pIndex->next;
    }
}

IsbStudentList* insertNode(IsbStudentList* currentNode, IsbStudentList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
    return currentNode;
}

IsbStudentList* copyNode(IsbStudentList* copyNode)
{
    if (NULL == copyNode)
    {
        return NULL;
    }

    return createNode(copyNode->student);
}

IsbStudentList* copyList(IsbStudentList* copyList)
{
    if (NULL == copyList)
    {
        return NULL;
    }

    IsbStudentList dummyHead;
    dummyHead.next = NULL;

    IsbStudentList* newList = &dummyHead;
    while (copyList != NULL)
    {
        insertNode(newList, copyNode(copyList));

        copyList = copyList->next;
        newList = newList->next;
    }

    return dummyHead.next;
}

IsbStudentList* copyList2(IsbStudentList* copyList)
{
    if (NULL == copyList)
    {
        return NULL;
    }

    IsbStudentList dummyHead;
    dummyHead.next = NULL;

    IsbStudentList* newList = &dummyHead;
    while (copyList != NULL)
    {
        insertNode(newList, copyNode(copyList));

        copyList = copyList->next;
        newList = newList->next;
    }

    return dummyHead.next;
}

IsbStudentList* deleteNode(IsbStudentList* head, const char* first_name)
{
    if (NULL == head)
    {
        return NULL;
    }

    IsbStudentList* curr = head;
    IsbStudentList* prev = curr;

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

IsbStudentList* deleteNode2(IsbStudentList* head, const char* first_name)
{
    if ((NULL == head) || (NULL == first_name)) 
    {
        return NULL;
    }
    
    IsbStudentList dummyHead;
    dummyHead.next = head;

    IsbStudentList *prev = head;
    IsbStudentList *curr = head;

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

IsbStudentList* deleteNode2ndVersion(IsbStudentList* head, const char* first_name)
{
    if ((NULL == head) || (NULL == first_name)) 
    {
        return NULL;
    }

    IsbStudentList dummyHead;
    dummyHead.next = head;

    IsbStudentList *prev = head;
    IsbStudentList *curr = head;

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

IsbStudentList* deleteNode2ndVersion2(IsbStudentList* head, const char* first_name)
{
    if ((NULL == head) || (NULL == first_name)) 
    {
        return NULL;
    }

    IsbStudentList dummyHead;
    dummyHead.next = head;

    IsbStudentList *prev = head;
    IsbStudentList *curr = head;

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

IsbStudentList* listNode(IsbStudentList* head, IsbStudentList* student)
{
    if ((NULL == head) || (NULL == student))
    {
        return NULL;
    }

    IsbStudentList* copy = head;

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

IsbStudentList* listNode2(IsbStudentList* head, IsbStudentList* student)
{
    if ((NULL == head) || (NULL == student))
    {
        return NULL;
    }

    IsbStudentList* copy = head;

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

int main()
{
    IsbStudent Suri;
    IsbStudent Maria;
    IsbStudent Rachel;
    IsbStudent Angelina;
    IsbStudent Alina;
    IsbStudent Xiaoxiao;
    
    IsbStudent Jenny;

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

    strncpy(Jenny.first_name, "Jenny", sizeof(Jenny.first_name)-1);
    Jenny.first_name[sizeof(Jenny.first_name)-1] = '\0';
    Jenny.math_score = 96;

    IsbStudentList* pSuri = createNode(Suri);
    IsbStudentList* pMaria = createNode(Maria);
    IsbStudentList* pRachel = createNode(Rachel);
    IsbStudentList* pAlina = createNode(Alina);
    IsbStudentList* pAngelina = createNode(Angelina);
    IsbStudentList* pXiaoxiao = createNode(Xiaoxiao);
    
    IsbStudentList* pJenny = createNode(Jenny);

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

    IsbStudentList* copiedList = copyList(pSuri);

    printf("\n");
    printList(copiedList);

    return 0;
}