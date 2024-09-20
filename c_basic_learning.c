#include <stdio.h>

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
    int test[3][3] = {0};

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            test[i][j] = i+j;
        }
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf("%d ", test[i][j]);
        }
        printf("\n");
    }
}

void swapArray(int array[], int count)
{
    if (count <= 0)
    {
        return -1;
    }

	int temp = 0;
	for (int i=0; i<count/2; i++)
	{
		temp array[i];

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

void printOddOrEven()
{
    for (int i=1; i<=100; i=i+1)
    {
        if (i%2 == 1)
        {
            printf("odd\n");
        }
        else if (i%2 == 0)
        {
            printf("even\n");
        }
    }
}

// AbsoluteSum(-1, -1, -1) == AbsoluteSum(1, 1, 1);
// AbsoluteSum(1, 2, 3) === AbsoluteSum(1, 2, 3);
int AbsoluteSum(int a,int b,int c)
{
    if (a < 0) {
        a = -a;
    }
    
    if (b < 0) {
        b = -b;
    }
    
    if (c < 0) {
        c = -c;
    }

    return (a+b+c);
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

void practicePlusAndMinus()
{
    int i = 0;
    printf("%d\n", i);
    printf("%d\n", i++);
    printf("%d\n", i);
    printf("%d\n", ++i);
    printf("%d\n", i);
    printf("%d\n", --i);
    printf("%d\n", i);
    printf("%d\n", i--);
    printf("%d\n", i);
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

void printArraySum2(int array[], int count)
{
    if (count <= 0)
    {
        return;
    }

    int sum = 0;

    for (int i = 0; i <= count; i++)
    {
        sum += array[i];
    }
    
    printf("sum of array is%d\n", sum);
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

    printArraySum2(myArray, myArrayIndex);

    float result = findAverageNumInArray(myArray, myArrayIndex);
    printf("The average number of the array is %0.2f\n", result);
}

int main()
{
//  printPrimeNumFrom1To100();

    twoDimensionArrayLearning();

	return 0;
}
