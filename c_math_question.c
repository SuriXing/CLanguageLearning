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

int isPrime2(int num)
{
    for (int n=2; n<=num/2; n=n+1)
    {
        if (num%n == 0)
        {
            return 0;
        }
    }
    return 1;
}

int isPrime3(int Num)
{
    for (int k=2; k<=Num/2; k=k+1)
    {
        if (Num%k == 0)
        {
            return 0;
        }
    }

    /*
    int k=2;
    if (k <= num/2) {
        if (num % k == 0) {
            return 0;
        }
    } else {
        break;
    }
    k=k+1;
    if (k <= num/2) {
        if (num % k == 0) {
            return 0;
        }
    } else {
        break;
    }
    k=k+1;
    if (k <= num/2) {
        if (num % k == 0) {
            return 0;
        }
    } else {
        break;
    }
    ......
     */

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

void printPrimeNum3(int from, int to)
{
    if (from>=to)
    {
        return ;
    }
    
    for (int i=from; i<=to; i=i+1)
    {
        if (isPrime(i) == 1)
        {
            printf("%d\n",i);
        }
    }
}

void printPrimrNum2(int from, int to)
{
    for (int i=from; i<=to; i=i+1)
    {
        int j = 0;
        for (j=2; j<=i/2; j=j+1)
        {
            if (i%j == 0)
            {
                break;
            }
        }

        if (j>i/2)
        {
            printf("%d\n", i);
        }
    }
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

int SumOfArithmeticSequence(int from, int to)
{
    // && : and
    // || : or
    if (from > to || from < 0 || to < 0)
    {
        return -1;
    }
    
    int n = to-from+1;
    int a1 = from;
    int an = to;

    return n*(a1+an)/2;    
}

int SlowVerSum(int from, int to)
{
    if (from > to || from < 0 || to < 0)
    {
        return -1;
    }
    
    int sumOfArth=0;
    
    for (int i=from; i<=to; i=i+1)
    {
        sumOfArth=sumOfArth+i;
    }
    return sumOfArth;
}

void testFunctions()
{
    if (SumOfArithmeticSequence(69,3456) == SlowVerSum(69,3456))
    {
        printf("YES!\n");
    }
    else 
    {
        printf("%s\n", "OhNo!");
    }
}

int main()
{   
    testFunctions();

/*     printPrimeNum(1,234);

    printPrimeNum2(1,234);

    printPrimeNum3(1,765);
   
    int result = isPrime2(23437);
    printf("%d\n", result);
    result3 = fasterCalcFrom1To100();
    printf("%d\n", result3); 
    
    int result = calcFrom1To100();
    printf("%d\n", result);
    printPrimeNum(1, 1000);

    result = Sum(35, 78);

    int result2;
    result2 = Sum(35, 78);
    

	return 0;
*/
}

