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