#include <stdio.h>

void practiceprinting()
{
    int myNum=21;//defining an integer
    float myFloat=21.99;//definning decimal
    char myLetter='A';
    
    printf("%d\n",myNum);
    printf("%f\n",myFloat);
    printf("%c\n",myLetter);
    
}

int Sum(int a, int b)
{
    return a+b;
}

int difference(int a, int b)
{
    return a-b;
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

int printOddNumber() {
    for (int i=1; i<100; i+=2)
    {
        printf("%d\n", i);
    }
    
    return 0;
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

int main()
{
    printPrimeNumFrom1To100();

/*
    learnArray();
 
    practicePlusAndMinus();

    printPrimeNum(1, 100);
   
    for (int i=2; i<=100; i=i+1)
    {
        int result = isPrime(i);

        if (result == 1)
        {
            printf("%d\n", i);
        }
    } 

    practiceprinting();
    
    int result = Sum(3, 4);
    printf("%d\n", result);
    
    result = AbsoluteSum(-45, -23, -37);
    printf("%d\n", result);

    result = difference(5,8);
    printf("%d\n",result);

    printOddOrEven();

    g();
    f(3);

    printFiveXNumber();

    printf("hhhhhhhhhhhh\n");
    
    printFiveXNotTenNumber();

	for (int x=1; x<10; ++x) {
		printf("Suri is smart!\t%d:%d\n", x, f(x));
	}
*/
	return 0;
}
