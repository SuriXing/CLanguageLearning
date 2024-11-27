#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

#pragma mark -- macro declaration --
#define LEN_OF_ONE_D_ARR 20
#define LENGTH_OF_2D_ROW 20
#define LENGTH_OF_2D_COL 20

#pragma mark -- function declaration --
void smallest_number_in_1D_array(int array[], int lengthOf1DArr);
void greatest_number_in_1D_array(int array[], int lengthOf1DArr);
void smallest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);
void greatest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);


#pragma mark -- function implementation --

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

int main()
{
    int oneDimensionalArray[LEN_OF_ONE_D_ARR];
    int twoDimensionalArray[LENGTH_OF_2D_ROW][LENGTH_OF_2D_COL];
    
    smallest_number_in_1D_array(oneDimensionalArray,LEN_OF_ONE_D_ARR);
    greatest_number_in_1D_array(oneDimensionalArray,LEN_OF_ONE_D_ARR);
    smallest_number_in_2D_array(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    greatest_number_in_2D_array(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);


    return 0;
}