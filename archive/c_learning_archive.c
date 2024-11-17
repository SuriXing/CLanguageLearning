#include <stdio.h>
#include "../utils.h"

void findNewArrAndSum()
{
    int target[5][5] = {0};
    int src1[5][5], src2[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            src1[i][j] = i * j;
            src2[i][j] = i * j + 1;
        }
    } 

    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            target[i][j] = src1[i][j] * src2[i][j];
        }
    } 

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += target[i][j];
        }
    } 

    printf("%d\n",sum);

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

int printOddNumber() {
    for (int i=1; i<100; i+=2)
    {
        printf("%d\n", i);
    }
    
    return 0;
}

void printTimesTable()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int k = 1; k <= 9; k++)
        {
            printf("%02d * %02d = %02d\t", i, k, i * k);
        }    
        printf("\n");
    }
}

// 1. Fibonacci
// 2. gcd + lcm
// 3. !

void printFibonacci(int count)
{
    if (count <= 2)
    {
        return;
    }

    int a1 = 1;
    int a2 = 1;
    int a3 = a1 + a2;
    
    for (int i = 1; i <= count; i += 1)
    {
        printf("%d + %d = %d\n", a1, a2, a3);
    
    a1 = a2;
    a2 = a3;
    a3 = a1 + a2;
    }
}

int f(int x)
{
    int a = 3; // variable
    int b = 1;
    int c;  // random number
    
    printf("a=%d\n", a);
    a = 5;
    printf("a=%d\n", a);
    printf("c=%d\n", c);
    
    if (a == 5)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
	return a*x+b;
}

// void means no return value
void g()
{
    int myNum = 15; // Define an integer variable and initialize
    
    int myNum2; // Define an integer variable (random number)
    myNum2 = 15; // assign a value
    
    char myLetter = 'a'; // define a character variable and initialize
    char myLetter2; // define a character variable (random number)
    myLetter2 = 'b'; // assign a value 'b';
    
    float myFloatNum = 5.1;
    
    double myDoubleNum = 6.1;
    
    printf("%d\n", myNum);
    printf("%c\n", myLetter);
    printf("%f\n", myFloatNum);
    printf("%lf\n", myDoubleNum);
}


void practiceprinting()
{
    int myNum=21;//defining an integer
    float myFloat=21.99;//definning decimal
    char myLetter='A';
    
    printf("%d\n",myNum);
    printf("%f\n",myFloat);
    printf("%c\n",myLetter);
    
}


int findSmallestValue2(int array[], int count)
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

int findSmallestIndex2(int array[], int count)
{
     if (count <= 0)
    {
        return -1;
    }

    int smallestIndex = 0;

    for (int i = 0; i < count; i++)
    {
        if (array[i] < array[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    return array[smallestIndex];
}

int findGreatestNumInArray2(int array[], int count)
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

int printEvenNumber() {
    for (int i=2; i<100; i=i+2)
    {
        printf("%d\n", i);
    }
    return 0;
}

int printFiveXNumber() {
    for (int i=5; i<=100; i+=5)
    {
        printf("%d\n", i);
    }
    
    return 0;
}

int printFiveXNotSevenNumber() {
    for (int i=5; i<=100; i+=5)
    {
        if (i % 7 != 0) 
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

int printFiveXNotTenNumber() {
    for (int i=5; i<=100; i+=5) {
        if (i % 10 != 0) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}


int findGreatestNumInArray3(int array[], int count)
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


void learnArray()
{
    int myArray[5] = {0, 25, 50, 75, 100};

    for (int i=0; i<5; i++)
    {
        printf("%d\n", myArray[i]);
    }

    printf("---------------------\n");
    printf("%d\n", myArray[0]);    
    printf("%d\n", myArray[1]);
    printf("%d\n", myArray[2]);
    printf("%d\n", myArray[3]);            
    printf("%d\n", myArray[4]);   

    printf("---------------------\n");
    
    int temp;

    temp = myArray[0];
    myArray[0] = myArray[4];
    myArray[4] = temp;
    temp = myArray[1];
    myArray[1] = myArray[3];
    myArray[3] = temp;
    // swap array 

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", myArray[i]);
    }

    printf("---------------------\n");
    
    for (int i = 0; i <= 5/2; i++)
    {
        int temp = myArray[i];
        myArray[i] = myArray[5-i-1];
        myArray[5-i-1] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", myArray[i]);
    }

    printf("---------------------\n");    

    for (int i = 4; i >= 5/2; i--)
    {
        int temp = myArray[i];
        myArray[i] = myArray[5-i-1];
        myArray[5-i-1] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", myArray[i]);
    }

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

void swapInt(int a, int b)
{
    int temp = 0;
    printf("%d, %d\n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("%d, %d\n", a, b);
}

int factorialFormula(int num)
{
    if (num <= 1)
    {
        return -1;
    }
    
    for(int i = num -1; i >= 1; i -= 1 )
    {
        num = num * i;
    }
    
    return num;
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
    int result = factorialFormula(5);
    printf("%d\n", result);
//   swapInt(23, 543);
//    printFibonacci(9);
//printTimesTable();
}