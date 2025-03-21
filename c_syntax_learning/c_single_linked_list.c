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
}IsbStudentList;

IsbStudentList* createNode(IsbStudent student)
{
    IsbStudentList* newNode = (IsbStudentList*)malloc(sizeof(IsbStudentList));

    newNode->next = NULL;

    memcpy((void*)&(newNode->student), (void*)&student, sizeof(student));

    return newNode;
}

void printList(IsbStudentList* head)
{
    IsbStudentList* pIndex = head;

    while (NULL != pIndex)
    {
        printf("%s\n", pIndex->student.first_name);

        pIndex = pIndex->next;
    }
}

IsbStudentList* insertNode(IsbStudentList* currentNode, IsbStudentList* newNode)
{
    if ((NULL == currentNode) || (NULL == newNode))
    {
        return currentNode;
    }

    currentNode->next = newNode;

    return currentNode;
}

int main()
{
    IsbStudent Suri;
    IsbStudent Maria;
    IsbStudent Rachel;
    IsbStudent Angelina;
    IsbStudent Alina;
    IsbStudent Xiaoxiao;

    strncpy(Suri.first_name, "Suri", sizeof(Suri.first_name)-1);
    Suri.first_name[sizeof(Suri.first_name)-1] = '\0';

    strncpy(Maria.first_name, "Maria", sizeof(Maria.first_name) - 1);
    Maria.first_name[sizeof(Maria.first_name)-1] = '\0';

    strncpy(Rachel.first_name, "Rachel", sizeof(Rachel.first_name)-1);
    Rachel.first_name[sizeof(Rachel.first_name)-1] = '\0';

    strncpy(Alina.first_name, "Alina", sizeof(Alina.first_name)-1);
    Alina.first_name[sizeof(Alina.first_name)-1] = '\0';

    strncpy(Angelina.first_name, "Angelina", sizeof(Angelina.first_name)-1);
    Angelina.first_name[sizeof(Angelina.first_name)-1] = '\0';

    strncpy(Xiaoxiao.first_name, "Xiaoxiao", sizeof(Xiaoxiao.first_name)-1);
    Xiaoxiao.first_name[sizeof(Xiaoxiao.first_name)-1] = '\0';

    IsbStudentList* pSuri = createNode(Suri);
    IsbStudentList* pMaria = createNode(Maria);
    IsbStudentList* pRachel = createNode(Rachel);
    IsbStudentList* pAlina = createNode(Alina);
    IsbStudentList* pAngelina = createNode(Angelina);
    IsbStudentList* pXiaoxiao = createNode(Xiaoxiao);

    insertNode(pSuri,
        insertNode(pMaria,
            insertNode(pRachel,
                insertNode(pAlina,
                    insertNode(pAngelina, pXiaoxiao)
                )
            )
        )
    );

    printList(pSuri);

    return 0;
}