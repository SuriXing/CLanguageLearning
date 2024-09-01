#include <stdio.h>

int Sum(int a, int b)
{
    return a+b;
}

int difference(int a, int b)
{
    return a-b;
}

int isPrime(int num)
{
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

void printPrimeNum(int from, int to)
{
    int countOfPrimeNum=0;

    for (int i=from; i<=to; i=i+1)
    {
        if (isPrime(i) == 1)
        {
            printf("%d\n",i); 
            countOfPrimeNum=countOfPrimeNum+1;
        }
    }
    printf("%d\n",countOfPrimeNum);
}

void printPrimeNum2(int from, int to)
{
    for (int i=from; i<=to; i=i+1)
    {
        if (isPrime(i) == 1)
        {
            printf("%d\n", i);
        }
    }
}

 int calcFrom1To100()
 {
    int sumOfOddNumber = 0;
    int sumOfEvenNumber = 0;

    for (int i=1; i<=99; i=i+2)
    {
        sumOfOddNumber = sumOfOddNumber + i;
    }

    for (int i=2; i<=100;i=i+2)
    {
        sumOfEvenNumber = sumOfEvenNumber + i;
    }

    return sumOfOddNumber - sumOfEvenNumber;
 }

int fasterCalcFrom1To100()
{
    int sumOfOddNumber = 0;
    int sumOfEvenNumber = 0;

    // Formula : n*(a1+an)/2
    int n = 50;
    int a1 = 1;
    int an = 99;
    int a2 = 2;
    int an2 = 100;

    return n*(a1+an)/2 - n*(a2+an2)/2;
}

int main()
{
    int result3 = fasterCalcFrom1To100();
    printf("%d\n", result3); 
    
    int result = calcFrom1To100();
    printf("%d\n", result);
//    printPrimeNum(1, 1000);

    result = Sum(35, 78);

    int result2;
    result2 = Sum(35, 78);
    
	return 0;
}

