#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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

int generateRandom2DArray(int array[][10], int lengthOfR, int lengthOfC)
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



int print2DArray(int array[][10], int lengthOfR, int lengthOfC)
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

int returnSumOf2DArray(int array[][10], int lengthOfRow, int lengthOfColumn)
{
    if ((lengthOfRow <= 0) || (lengthOfColumn <= 0))
    {
        return -1;
    }

    int sum = 0;

    for (int i = 0; i < lengthOfRow; i++)
    {
        for (int j = 0; j < lengthOfColumn; j++)
        {
            sum += array[i][j];
        }
    }

    return sum;
}

double returnAverageOfA1DArr(int array[], int length)
{
    if (length <= 0)
    {
        return -1;      
    }

    return returnSumOf1DArray(array, length)/(double)length;
}

double reutrnAverageOfA2DArr(int array[][10], int lengthOfRow, int lengthOfColumn)
{
    if ((lengthOfRow <= 0) || (lengthOfColumn <= 0))
    {
        return -1;
    }

    return returnSumOf2DArray(array, 10, 10)/((double)lengthOfRow * lengthOfColumn);

}

int main()
{
    int oneDimensionalArray[10];
    int twoDimensionalArray[10][10];

    generateRandom1DArray(oneDimensionalArray, 10);
    sleep(1);
    generateRandom2DArray(twoDimensionalArray, 10, 10);

    print1DArray(oneDimensionalArray, 10);
    printf("------------------------------\n");
    print2DArray(twoDimensionalArray, 10, 10);
    printf("------------------------------\n");

    int res = returnSumOf1DArray(oneDimensionalArray, 10);
    printf("The sum of this random 1D array is %d\n", res);

    int res2 = returnSumOf2DArray(twoDimensionalArray, 10, 10);
    printf("The sum of this random 2D array is %d\n",res2);

    double res3 = returnAverageOfA1DArr(oneDimensionalArray, 10);
    printf("The average of this random 1D array is %lf\n", res3);

    double res4 = reutrnAverageOfA2DArr(twoDimensionalArray, 10, 10);
    printf ("The average of this random 2D array is %lf\n", res4);

    return 0;
}