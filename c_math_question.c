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

int main()
{
    printPrimeNum(1, 1000);

	return 0;
}
