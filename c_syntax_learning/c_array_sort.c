#include <stdio.h>
#include <assert.h>
#include "c_array_learning.h"
#include "../utils.h"

int doBubbleSortInInvertedOrder(int array[], int length)
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

int doBubbleSortInReversedOrder(int array[], int length)
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

int doBubbleSortInInvertedOrder2(int array[], int length)
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

int doBubbleSortInReversedOrder2(int array[], int length)
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

void doArraySortTesting()
{
    int array[64] = {};
    int length = 64;
    
    // Bubble Sort
    generateRandom1DArray(array, length);    
    print1DArray(array, length);
    doBubbleSortInInvertedOrder2(array, length);
    print1DArray(array, length);

}