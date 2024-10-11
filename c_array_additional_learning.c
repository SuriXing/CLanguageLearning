#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#pragma mark -- Macro declaration --

#define LENGTH_OF_1D_ARRAY 20
#define LENGTH_OF_2D_ROW 15
#define LENGTH_OF_2D_COL 15

#pragma mark -- function declaration --

int generateRandom1DArray(int array[], int length);
int generateRandom2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);
int print1DArray(int array[], int length);
int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);
int returnSumOf1DArray(int array[], int length);
int returnSumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);
double returnAverageOf1DArray(int array[], int length);
double returnAverageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);
int returnSmallestNumberInA2DArr(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);
int returnGreatestNumberInA2DArr(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);
int returnSmallestNumberInA1DArr(int array[], int length);
int returnGreatestNumberInA1DArr(int array[], int length);
int swap1DArray(int array[], int length);
int main()
{
    int oneDimensionalArray[LENGTH_OF_1D_ARRAY];
    int twoDimensionalArray[LENGTH_OF_2D_ROW][LENGTH_OF_2D_COL];

    generateRandom1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);
    sleep(1);
    generateRandom2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);

    print1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);
    printf("------------------------------\n");
    print2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    printf("------------------------------\n");

    int res = returnSumOf1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);
    printf("The sum of this random 1D array is %d\n", res);

    int res2 = returnSumOf2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    printf("The sum of this random 2D array is %d\n", res2);

    double res3 = returnAverageOf1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);
    printf("The average of this random 1D array is %lf\n", res3);

    double res4 = returnAverageOf2DArray(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    printf ("The average of this random 2D array is %lf\n", res4);

    int res5 = returnSmallestNumberInA1DArr(oneDimensionalArray, LENGTH_OF_1D_ARRAY);
    printf("The smallest number in this random 1D array is %d\n", res5);

    int res6 = returnGreatestNumberInA1DArr(oneDimensionalArray, LENGTH_OF_1D_ARRAY);
    printf("The greatest number in this random 1D array is %d\n", res6);

    int res7 = returnSmallestNumberInA2DArr(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    printf("The smallest number in this random 2D array is %d\n", res7);

    int res8 = returnGreatestNumberInA2DArr(twoDimensionalArray, LENGTH_OF_2D_ROW, LENGTH_OF_2D_COL);
    printf("The greatest number in this random 2D array is %d\n", res8);

    printf("Swap Array: Before\n");
    print1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);

    swap1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);

    printf("Swap Array: After\n");
    print1DArray(oneDimensionalArray, LENGTH_OF_1D_ARRAY);

    return 0;
}

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

int returnSumOf1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }
    
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum;
}

int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        return -1;
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

int returnSumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        return -1;
    }

    int sum = 0;

    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j < lengthOfC; j++)
        {
            sum += array[i][j];
        }
    }

    return sum;
}

double returnAverageOf1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;      
    }

    return returnSumOf1DArray(array, length)/(double)length;
}

double returnAverageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        return -1;
    }

    return returnSumOf2DArray(array, lengthOfR, lengthOfC)/((double)lengthOfR * lengthOfC);
}

int returnGreatestNumberInA1DArr(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    int greatestNum = 0;

    for (int i = 0; i < length; i++)
    {
        if (greatestNum < array[i])
        {
            greatestNum = array[i];
        }
    }

    return greatestNum;
}

int returnSmallestNumberInA1DArr(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    int smallestNum = 0;

    for (int i= 0; i < length; i++)
    {
        if (smallestNum > length)
        {
            smallestNum = length;
        }
    }

    return smallestNum;
}

int returnGreatestNumberInA2DArr(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        return -1;
    }

    int greatestNum = 0;

    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j < lengthOfC; j++)
        {
            if(greatestNum < array[i][j])
            {
                greatestNum = array[i][j];
            }
        }
    }

    return greatestNum;
}

int returnSmallestNumberInA2DArr(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC)
{
    if ((lengthOfR <= 0) || (lengthOfC <= 0))
    {
        return -1;
    }

    int smallestNum = 0;

    for (int i = 0; i < lengthOfR; i++)
    {
        for(int j= 0; j < lengthOfC; j++)
        {
            if (smallestNum > array[i][j])
            {
                smallestNum = array[i][j];
            }
        }
    }
    
    return smallestNum;
}

int swap1DArray(int array[], int length)
{
    if (length <= 0)
    {
        return -1;
    }

    int temporary = 0;

    for (int i = 0; i < length/2; i++)
    {
        temporary = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = temporary;
    }

    return 0;
}