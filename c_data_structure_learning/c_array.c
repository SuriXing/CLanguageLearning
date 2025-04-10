#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_isb_students.h"

IsbStudent* createStudentArray(IsbStudent* student)
{
    char arr[265];

    for (int i = 0; ; i++)
    {
        arr += student[i];
    }

    return arr;
}

int array_main()
{
    return 0;
}