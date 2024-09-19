#include <stdio.h>

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

int main()
{
    int result = factorialFormula(5);
    printf("%d\n", result);
//   swapInt(23, 543);
//    printFibonacci(9);
//printTimesTable();
}