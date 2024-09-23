#include <stdio.h>

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

void swapArray(int array[], int count)
{
    if (count <= 0)
    {
        return;
    }

	int temp = 0;
	for (int i=0; i<count/2; i++)
	{
		int array[i];

		array[i] = array[count-1-i];

		array[count-1-i] = array[i];
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

int printOddNumber() {
    for (int i=1; i<100; i+=2)
    {
        printf("%d\n", i);
    }
    
    return 0;
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

void printPrimeNumFrom1To100()
{
    int myArray[50] = {0};
    int myArrayIndex = 0;

    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i) == 1)
        {
            myArray[myArrayIndex++] = i;
//          printArray(myArray, 50);
        }
    }
    
    for (int k = 0; k < myArrayIndex; k++)
    {
        printf("%d\n", myArray[k]);
    }

    printf("there is %d prime numbers in total\n", myArrayIndex);

    printSumOfArray(myArray, myArrayIndex);

    float result = findAverageNumInArray(myArray, myArrayIndex);
    printf("The average number of the array is %0.2f\n", result);
}

int main()
{
//  printPrimeNumFrom1To100();

    twoDimensionArrayLearning();

	return 0;
}
