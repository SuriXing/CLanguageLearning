#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "c_array_learning.h"
#include "../utils.h"


#pragma mark -- function implementation --

int generateRandom1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    srand(time(NULL));
    const int kMaxValue = 100;
    const int kMinValue = 1;

    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % (kMaxValue - kMinValue) + kMinValue;
    }

    return 0;
}

int generateRandom2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        return -1;
    }

    srand(time(NULL));
    const int kMaxValue = 100;
    const int kMinValue = 1;

    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j < lengthOfC; j++)
        {
            array[i][j] = rand() % (kMaxValue - kMinValue) + kMinValue;
        }
    }

    return 0;
}

int findSmallestNumberIn1DArray(int array[], int lengthOf1DArr)
{
    int smallestNum = array[0];

    for (int i = 0; i < lengthOf1DArr; i++)
    {
        if (array[i] < smallestNum)
        {
            smallestNum = array[i];
        }
    }
    
    printf("%s: %d\n", __FUNCTION__, smallestNum); 
    
    return smallestNum;
}

int findSmallestIndexIn1DArray(int array[], int lengthOf1DArr)
{
    int smallestIndex = 0;

    for (int i = 0; i < lengthOf1DArr; i++)
    {
        if (array[i] < array[smallestIndex])
        {
            smallestIndex = i;
        }
    }
    
    printf("%s: %d\n", __FUNCTION__, smallestIndex); 
    
    return smallestIndex;
}

int findGreatestNumberIn1DArray(int array[], int lengthOf1DArr)
{
    int greatestNum = array[0];

    for (int i = 0; i < lengthOf1DArr; i++)
    {
        if (array[i] > greatestNum)
        {
            greatestNum = array[i];
        }
    }
    
    printf("%s: %d\n", __FUNCTION__, greatestNum);

    return greatestNum;
}

int findGreatestIndexIn1DArray(int array[], int lengthOf1DArr)
{
    int greatestIndex = 0;

    for (int i = 0; i < lengthOf1DArr; i++)
    {
        if (array[i] > array[greatestIndex])
        {
            greatestIndex = i;
        }
    }
    
    printf("%s: %d\n", __FUNCTION__, greatestIndex);

    return greatestIndex;
}

int findSmallestNumberIn2DArray(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC)
{
    int smallestNum = array[0][0];

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (smallestNum > array[i][j])
            {
                smallestNum = array[i][j];
            }
        }
    }

    printf("%s: %d\n", __FUNCTION__, smallestNum);
    
    return smallestNum;
}

int findGreatestNumberIn2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    int greatestNum = array[0][0];

    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j < lengthOfC; j++)
        {
            if (greatestNum < array[i][j])
            {
                greatestNum = array[i][j];
            }
        }
    }

    printf("%s: %d\n", __FUNCTION__, greatestNum);

    return greatestNum;
}

int print1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
        if (i < length - 1)
        {    
            printf(",");
        }
    }
    printf("\n");
    
    return 0;
}

int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        printf("invalid number\n");
        return 0;
    }

    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j < lengthOfC; j++)
        {
            printf("%d", array[i][j]);
            
            if (j < lengthOfC - 1)
            {
                printf(",");
            }

        }

        printf("\n");
    }

    return 0;
}

int getSumOf1DArray(int array[], int length)
{
    if (length <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }
    
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    printf("%s: %d\n", __FUNCTION__, sum);
    return sum;
}

int getSumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        printf("Invalid input\n");
        return 0;
    }
    
    int sum  = 0;
    
    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j < lengthOfC; j++)
        {
            sum += array[i][j];
        }
    }

    printf("%s: %d\n", __FUNCTION__, sum); 
    
    return sum;
}

int getAverageOf1DArray(int array[], int length)
{
    if (length <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int mean = getSumOf1DArray(array, length)/length;

    printf("%s: %d\n", __FUNCTION__, mean);

    return mean;
}

int getAverageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        printf("Invalid input\n");
        return 0;
    }

    int mean = getSumOf2DArray(array, lengthOfR, lengthOfC)/(lengthOfR * lengthOfC);

    printf("%s: %d\n", __FUNCTION__, mean);
    return mean;
}

int swap1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    int temp = 0;

    for (int i = 0; i < length/2; i++)
    {
        temp = array[length - i - 1];
        array[length - i - 1] = array[i];
        array[i] = temp;
    }

    return 0;
}

void cArrayLearningTest()
{
    int oneDimensionalArray[LENGTH_OF_1D_ARR];
    int twoDimensionalArray[LENGTH_OF_2D_ROW][LENGTH_OF_2D_COL];
    
    generateRandom1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);
    generateRandom2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    findSmallestNumberIn1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);
    findGreatestNumberIn1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);
    findSmallestNumberIn2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    findGreatestNumberIn2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    getSumOf1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);
    getSumOf2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    getAverageOf1DArray(oneDimensionalArray, LENGTH_OF_2D_ROW);
    getAverageOf2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    print1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);

    swap1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);

    print1DArray(oneDimensionalArray, LENGTH_OF_1D_ARR);

    print2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    doArraySortTesting();
}