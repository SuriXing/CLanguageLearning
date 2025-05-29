#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_isb_students.h"
#include <assert.h>

char* reverseArr(char* student, int count)
{
    assert(NULL != student);
    assert(count > 0);

    if (count <= 0)
    {
        return NULL;
    }

    char temp;

    for (int i = 0; i < count/2; i++)
    {
        temp = student[count - i - 1];
        student[count - i - 1] = student[i];
        student[i] = temp;
    }

    return student;
}

IsbStudent* printArr(char* student, int count)
{
    assert(NULL != student);
    assert(count > 0);

    if ((count <= 0) || (NULL == student))
    {
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%c", student[i]);
        if (i < count - 1)
        {    
            printf(",");
        }
    }
    printf("\n");
    
    return 0;
}

int c_array_main()
{   
    char student[4] = {"S" "A" "R"};

    printArr(student, 4);
    return 0;
}