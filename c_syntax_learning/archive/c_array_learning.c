#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findGreatestNumInArray(int array[], int count)
{
     if (count <= 0)
    {
        return -1;
    }

    int greatestValue = array[0];

    for (int i = 0; i <= count; i++)
    {
        if (array[i] > greatestValue)
        {
            greatestValue = array[i];
        }
    }
    return greatestValue;
}


int find2ndGreatestIndexInArray(int array[], int count)
{
    if (count <= 0)
    {
        return -1;
    }

    int greatestIndex = 0;
    int secondGreatestIndex = 0;

    for (int i = 0; i <= count; i++)
    {
        if (array[i] > array[greatestIndex])
        {
            secondGreatestIndex = greatestIndex;
            greatestIndex = i;
        }
    }

    return array[secondGreatestIndex];
}

int findGreatestIndexInArray(int array[], int count)
{
    if (count <= 0)
    {
        return -1;
    }

    int greatestIndex = 0;

    for (int i = 0; i <= count; i++)
    {
        if (array[i] > array[greatestIndex])
        {
            greatestIndex = i;
        }
    }

    return array[greatestIndex];
}

int findSmallestValue(int array[], int count)
{
     if (count <= 0)
    {
        return -1;
    }

    int smallestValue = array[0];

    for (int i = 0; i <= count; i++)
    {
        if (array[i] < array[smallestValue])
        {
            smallestValue = i;
        }
    }
    return smallestValue;
}

int findSmallestIndex(int array[], int count)
{
     if (count <= 0)
    {
        return -1;
    }

    int smallestIndex = 0;

    for (int i = 0; i <= count; i++)
    {
        if (array[i] < array[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    return array[smallestIndex];
}

int findGreatestValIn2DArr(int array[][100], int lengthOfRow, int lengthOfColumn)
{
    if ((lengthOfRow <= 0) || (lengthOfColumn <= 0))
    {
        return -1;
    }

    int greatestValue = array[0][0];

    for (int i=0; i<lengthOfRow; i++)
    {
        for(int j=0; j<lengthOfColumn; j++)
        {
            if (array[i][j]>greatestValue)
            {
                greatestValue = array[i][j];
            }
        }
    }

    return greatestValue;
}

int findSmallestValueIn2DArr(int array[][100], int lengthOfR, int lengthOfC)
{
    if ((lengthOfC <= 0) || (lengthOfR <= 0))
    {
        return -1;
    }

    int smallestValue = array[0][0];

    for (int i = 0; i < lengthOfR; i++)
    {
        for (int j = 0; j <= lengthOfC; j++)
        {
            if (array[i][j] < smallestValue)
            {
                smallestValue = array[i][j];
            }
        }
    }

    return smallestValue;

}


void ascendSortArray(int array[], int length)
{
    if (length <= 0)
    {
        return;
    }

    for (int i=0; i<length; i++)
    {
        int smallestIndex = 0;
        for (int j=i; j<length; j++)
        {
            if (array[j] < array[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[smallestIndex];
        array[smallestIndex] = array[i];
    }
}


void descendSortArray(int array[], int length)
{
    if (length <= 0)
    {
        return;
    }

    for (int i=0; i<length; i++)
    {
        int largestIndex = 0;
        for (int j=i; j<length; j++)
        {
            if (array[j] > array[largestIndex])
            {
                largestIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[largestIndex];
        array[largestIndex] = array[i];
    }
}


void swapArray(int array[], int count)
{
    if (count <= 0)
    {
        return;
    }

	for (int i=0; i<count/2; i++)
	{
        int temp = 0;
		temp = array[i];
		array[i] = array[count-1-i];
		array[count-1-i] = temp;
	}

	return;
}

int sumOf2DArray(int array[][100], int lengthOfR, int lengthOfC)
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

void printSumOfArray(int array[], int count)
{
    if (count <= 0)
    {
        return;
    }

    int sum = 0;

    for (int i=0; i<count; i++)
    {
        sum += array[i];
    }

    printf("sum of the array is %d\n", sum);
}

int sumOfArray(int array[], int count)
{
    if (count <= 0)
    {
        return -1;
    }

    int sum = 0;
    
    for (int i = 0; i < count; i++)
    {
        sum += array[i];
    }

  return sum;
}

float findAverageNumInArray(int array[], int count)
{
    if (count <= 0)
    {
        return -1;
    }

    int sum = 0;
    
    for (int i = 0; i < count; i++)
    {
        sum += array[i];
    }

  return 1.0*sum/count; // implicit type casting    
//    return (float)sum/count;    // explicit type casting
}

void printArray(int array[], int count)
{
    for (int i=0; i<count; i++)
    {
        printf("%d", array[i]);

        if (i < count-1)
        {
            printf(",");
        }
    }
    printf("\n");
}

void print2DArray(int array[][100], int lengthOfr, int lengthOfc)
{
    if ((lengthOfr <= 0) || (lengthOfc <= 0))
    {
        printf("%d", -1);
    }

    for (int i = 0; i < lengthOfr; i++)
    {
        for (int j = 0; j < lengthOfc; j++)
        {
            printf("%d", array[i][j]);
            
            if (j < lengthOfc - 1)
            {
                printf(",");
            }
        }
    }

}

void generateRandomArray(int randomArray[], int length)
{
    if (length <= 0)
    {
        return;
    }
    
    srand(time(NULL));
    const int kMinValue = 1;
    const int kMaxValue = 1000;

    for (int i=0; i<length; i++)
    {
        randomArray[i] = rand() % (kMaxValue - kMinValue) + kMinValue;
    }
}

void generateRandom2DArray(int randomArray[][100], int lengthOfRow, int lengthOfColumn)
{
    if ((lengthOfRow <= 0) || (lengthOfColumn <= 0))
    {
        return;
    }

    srand(time(NULL));
    const int kMinValue = 1;
    const int kMaxValue = 1000;

    for (int i=0; i<lengthOfRow; i++)
    {
        for (int j=0; j<lengthOfColumn; j++)
        {
            randomArray[i][j] = rand() % (kMaxValue - kMinValue) + kMinValue;
        }
    }
}

int main()
{
    int oneDimensionArray[100];
    int twoDimensionArray[100][100];

    generateRandomArray(oneDimensionArray, 100);
    generateRandom2DArray(twoDimensionArray, 100, 100);

    int res4 = findSmallestValueIn2DArr(twoDimensionArray, 100, 100);
    printf("smallest number in this array is %d\n", res4);

    int res3 = findGreatestValIn2DArr(twoDimensionArray, 100, 100);
    printf("findGreatestValIn2DArr = %d\n",  res3);
    
    int res = sumOf2DArray(twoDimensionArray, 100, 100);
    printf("sumOf2DArray == %d\n", res);

    int res2 = sumOfArray(oneDimensionArray, 100);
    printf("sumOfArray = %d\n", res2);

    printArray(oneDimensionArray, 100);
    
    print2DArray(twoDimensionArray, 100, 100);

    return 0;
}    