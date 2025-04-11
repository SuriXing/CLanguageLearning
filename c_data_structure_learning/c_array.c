#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_isb_students.h"

IsbStudent* copyStudentArray(IsbStudent* student)
{
    char arr[265];

    for (int i = 0; ; i++)
    {
        arr += student[i];
    }

    return arr;
}

IsbStudent* reverseArr(IsbStudent* student, int count)
{
    char copyArr[256] = *student;

    for (int i = 0; i < count/2; i++)
    {
        for (int j = count; j > count/2; j++)
        {
            copyArr[i] = student[j];
        }
    }

    return copyArr;
}

int array_main()
{
    return 0;
}