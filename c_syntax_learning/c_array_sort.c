#include <stdio.h>
#include <assert.h>
#include "c_array_learning.h"
#include "../utils.h"

int doSelectionSortInInvertedOrder(int array[], int length)
{
    if ((NULL == array) || (length <= 0))
    {
        return -1;
    }

    for (int i=0; i<length; i++)
    {
        // start from finding the smallest element
        int smallestIndex = findSmallestIndexIn1DArray(array+i, length-i) + i;
        
        int temp = array[i];
        array[i] = array[smallestIndex];
        array[smallestIndex] = temp;
    }

    return 0;
}

int doSelectionSortInReversedOrder(int array[], int length)
{
    if ((NULL == array) || (length <= 0))
    {
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        int greatestIndex = findGreatestIndexIn1DArray(array, length - i);

        int temp = array[length - i - 1];
        array[length - i - 1] = array[greatestIndex];
        array[greatestIndex] = temp;
    }

    return 0;
}

int doSelectionSortInInvertedOrder2(int array[], int length)
{
    if ((NULL == array) || (length <= 0))
    {
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        int smallestIndex = findSmallestIndexIn1DArray(array+i, length-i) + i;

        int temp = array[i];
        array[i] = array[smallestIndex];
        array[smallestIndex] = temp;
    }

    return 0;

}

int doSelectionSortInReversedOrder2(int array[], int length)
{
    if ((NULL == array) || (length <= 0))
    {
        return -1;
    }

    for(int i = 0; i < length; i++)
    {
        int greatestIndex = findGreatestIndexIn1DArray(array, length-i);

        int temp = array[length-i-1];
        array[length-i-1] = array[greatestIndex];
        array[greatestIndex] = temp;
    }
    return 0;
}

int bubbleSort(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return 0;
}

void doArraySortTesting()
{
    int array[64] = {};
    int length = 64;
    
    // Bubble Sort
    printf("\nStart Bubble Sort\n");
    generateRandom1DArray(array, length);    
    print1DArray(array, length);
    doBubbleSort(array, length);
    print1DArray(array, length);
    printf("End Bubble Sort\n");

    // Selection Sort
    printf("\nStart Selection Sort\n");
    generateRandom1DArray(array, length);    
    print1DArray(array, length);
    doSelectionSortInInvertedOrder(array, length);
    print1DArray(array, length);
    printf("End Selection Sort\n");
}