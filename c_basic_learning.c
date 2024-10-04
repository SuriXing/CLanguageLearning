#include <stdio.h>











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









int main()
{

    return 0;
}    