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

int doBubbleSort(int array[], int length)
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

int doCountingSort(int array[], int length, RangesOfArrays range)
{
    return 0;   
}


int _doCountingSort(int array[], int length, RangesOfArrays range)
{
    int countingArray[range.max - range.min];
    for (int i=0; i<range.max - range.min; i++)
    {
        countingArray[i] = 0;
    }

    for (int i=0; i<length; i++)
    {
        countingArray[array[i] - range.min] += 1;
    }

    int index = 0;
    for (int i=range.min; i<range.max; i++)
    {
        for (int j=0; j<countingArray[i]; j++)
        {
            array[index++] = i;
        }
    }
    assert(index == length);

    return 0;
}

void doBuddleSortTesting()
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
}

void doSelectionSortTesting()
{
    int array[64] = {};
    int length = 64;

    // Selection Sort
    printf("\nStart Selection Sort\n");
    generateRandom1DArray(array, length);    
    print1DArray(array, length);
    doSelectionSortInInvertedOrder(array, length);
    print1DArray(array, length);
    printf("End Selection Sort\n");
}

void doArraySortTesting()
{
    doBuddleSortTesting();
    doSelectionSortTesting();

    int array[16] = {0};
    int length = 16;
    generateRandom1DArray(array, length);    
    print1DArray(array, length);
    RangesOfArrays range = {0, 100};
    _doCountingSort(array, length, range);
    print1DArray(array, length);
}