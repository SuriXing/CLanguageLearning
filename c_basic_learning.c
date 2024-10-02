#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void twoDimensionArrayLearning()
{
    int test[3][5] = {0};

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<5; j++)
        {
            test[i][j] = 10*i+j;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d",test[i][j]);
            
            if (j <= 3)
            {
                printf(",");
            }
        }
        printf("\n");
    }

    int greatestValInArr = 0;
    
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (greatestValInArr < test[i][j])
            {
                greatestValInArr = test[i][j];
            }
        }
    }

    printf("The biggest number is%d\n", greatestValInArr);

    int smallestValInArr = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (smallestValInArr > test[i][j])
            {
                smallestValInArr = test[i][j];
            }
        }
    }

    printf("The smallest number is%d\n", smallestValInArr);

    int transpose[5][3] = {0};
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[i][j] = test[j][i];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", transpose[i][j]);
            
            if (j <= 1)
            {
                printf(",");
            }        
        }

        printf("\n");
    }

    printf("%p\n", test);
    printf("%p\n", test[0]);
    printf("%p\n", test[1]);
    printf("%p\n", test[2]);
    printf("%d\n", test[1][0]);

}

void swapArray2(int array[], int count)
{
    if (count <= 0)
    {
        return;
    }
    
    for (int i = 0; i <= count/2; i++)
    {
        int temp = 0;
        temp = array[i];
        array[i] = array[count - i -1];
        array[count - i - 1] = temp;
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

void swapInteger(int a, int b)
{
    printf("a=%d, b=%d\n", a, b);

    int c = b;
    int d = a;
    a = c;
    b = d;

    printf("a=%d, b=%d\n", a, b);

    int temp = a;
    a = b;
    b = temp;

    printf("a=%d, b=%d\n", a, b);
}

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    
    for (int i=2; i<=num/2; i=i+1)
    {
        if (num%i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void printPrimeNum(int from, int to)
{
    if (from <= 1)
    {
        from = 2;
    }
    
    for (int i = from; i <= to; i++)
    {
        if ( isPrime(i) == 1)
        {
            printf("%d\n", i);
        }
    }
}

void printArray(int array[], int count)
{
    for (int i=0; i<count; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
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

void separateArrayIntoOddAndEven(int array[], int length)
{
    if (length <= 0)
    {
        return;
    }

    int oddNumbers[length];
    int evenNumbers[length];

    int lengthOfOddNumbers = 0;
    int lengthOfEvenNumbers = 0;

    for (int i=0; i<length; i++)
    {
        if (array[i] % 2 == 0) // even number
        {
            evenNumbers[lengthOfEvenNumbers++] = array[i];
        }
        else
        {
            oddNumbers[lengthOfOddNumbers++] = array[i];
        }
    }

    printArray(evenNumbers, lengthOfEvenNumbers);
    printArray(oddNumbers, lengthOfOddNumbers);
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

int main()
{
    int oneDimensionArray[100];
    int twoDimensionArray[100][100];

    generateRandomArray(oneDimensionArray, 100);
    generateRandom2DArray(twoDimensionArray, 100, 100);

    int res3 = findGreatestValIn2DArr(twoDimensionArray, 100, 100);
    printf("findGreatestValIn2DArr = %d\n",  res3);
    
    int res = sumOf2DArray(twoDimensionArray, 100, 100);
    printf("sumOf2DArray == %d\n", res);

    int res2 = sumOfArray(oneDimensionArray, 100);
    printf("sumOfArray = %d\n", res2);

    return 0;
}    

//  printArray(test, 100);