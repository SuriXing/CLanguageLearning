#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"
#include <time.h>

#pragma mark -- macro declaration --
#define LEN_OF_ONE_D_ARR 20
#define LENGTH_OF_2D_ROW 20
#define LENGTH_OF_2D_COL 20

#pragma mark -- function declaration --
void smallest_number_in_1D_array(int array[], int lengthOf1DArr);
void greatest_number_in_1D_array(int array[], int lengthOf1DArr);
void smallest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);
void greatest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);

int print1DArray(int array[], int length);
int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int sumOf1DArray(int array[], int length);
int sumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int averageOf1DArray(int array[], int length);
int averageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

#pragma mark -- function implementation --

int generateRandom1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    srand(time(NULL));
    const int kMaxValue = 1000;
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
    const int kMaxValue = 1000;
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

void smallest_number_in_1D_array(int array[], int lengthOf1DArr)
{
    int smallestNum = array[0];

    for (int i = 0; i < 20; i++)
    {
        if (array[i] < smallestNum)
        {
            smallestNum = array[i];
        }
    }
    
    printf("%d\n", smallestNum);
}

void greatest_number_in_1D_array(int array[], int lengthOf1DArr)
{
    int greatestNum = array[0];

    for (int i = 0; i < 20; i++)
    {
        if (array[i] > greatestNum)
        {
            greatestNum = array[i];
        }
    }
    
    printf("%d\n", greatestNum);
}

void smallest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC)
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

    printf("%d\n", smallestNum);
}

void greatest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC)
{
    int greatestNum = array[0][0];

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (greatestNum > array[i][j])
            {
                greatestNum = array[i][j];
            }
        }
    }

    printf("%d\n", greatestNum);
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

int sumOf1DArray(int array[], int length)
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

int sumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
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

int averageOf1DArray(int array[], int length)
{
    if (length <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int mean = sumOf1DArray(array, length)/length;

    printf("%s: %d\n", __FUNCTION__, mean);

    return mean;
}

int averageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        printf("Invalid input\n");
        return 0;
    }

    int mean = sumOf2DArray(array, lengthOfR, lengthOfC)/(lengthOfR * lengthOfC);

    printf("%s: %d\n", __FUNCTION__, mean);
    return mean;
}

int main()
{
    int oneDimensionalArray[LEN_OF_ONE_D_ARR];
    int twoDimensionalArray[LENGTH_OF_2D_ROW][LENGTH_OF_2D_COL];
    
    generateRandom1DArray(oneDimensionalArray, LEN_OF_ONE_D_ARR);
    generateRandom2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    /*
    smallest_number_in_1D_array(oneDimensionalArray,LEN_OF_ONE_D_ARR);
    greatest_number_in_1D_array(oneDimensionalArray,LEN_OF_ONE_D_ARR);
    smallest_number_in_2D_array(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    greatest_number_in_2D_array(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    print2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    */
   
    sumOf1DArray(oneDimensionalArray, LEN_OF_ONE_D_ARR);
    sumOf2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    averageOf1DArray(oneDimensionalArray, LENGTH_OF_2D_ROW);
    averageOf2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    return 0;
}