#include <stdio.h>

int example4()
{
    int year = 0;
    int month = 0;
    int date = 0;
    int num = 0;
    int num2 = 0;
    int month_in_a_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter your year:");
    scanf("%d", &year);
    printf("Enter your month (numeral):");
    scanf("%d", &month);
    printf("Enter your date:");
    scanf("%d", &date);

    if ((month >= 13) || (month <= 0) || (year <= 0))
    {
        printf("invalid input\n");
        return 0;
    }

    if (year % 4 == 0)
    {
        month_in_a_year[1] += 1;
    }

    if ((date <= 0) || (date > month_in_a_year[month-1]))
    {
        printf("invalid input\n");
        return 0;
    }

    for (int i = 0 ; i < month-1; i++)
    {
        num2 += month_in_a_year[i];
    }

    num = num2 + date;

    printf("%d/%d is the %dst day in %d.\n", month, date, num, year);
    return 0;
}

int numberOfAscend3Digit()
{
    int count = 0;
    for (int i1=1; i1<=9; i1++)
    {
        for (int i2=i1+1; i2<=9; i2++)
        {
            for (int i3=i2+1; i3<=9; i3++)
            {
                int num = (100*i1)+(10*i2)+(i3);
                printf("%d\n",num);
                count++;
            }
        }
    }
    return count;
}

int numberOfAscend5Digit()
{
    int count = 0;
    for (int i1=1; i1<=9; i1++)
    {
        for (int i2=i1+1; i2<=9; i2++)    
        {
            for (int i3=i2+1; i3<=9; i3++)
            {
                for (int i4=i3+1; i4<=9; i4++)
                {
                    for (int i5=i4+1; i5<=9; i5++)
                    {
                        printf("%d%d%d%d%d\n", i1, i2, i3, i4, i5);
                        
                        count += 1;
                    }
                }
            }
        }
    }

    return count;
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

/*
    1*1=1
    1*2=2
    ..
    9*9=81
 */

void printTimesTable()
{
    for (int i=1; i<10; i+=1)
    {
        for(int j=1; j<10; j+=1)
        {
            printf("%d*%d=%d\n", i, j, i*j);
        }
    }
}

void printLine(int i)
{
    for(int j=1; j<10; j+=1)
    {
        printf("%d*%d=%d\n", i, j, i*j);
    }
}
 
void printTimesTable2()
{
    for(int i=1; i<10; i+=1)
    {
        printLine(i);
    }
}

void swapInteger2(int a, int b)
{
    printf("a=%d,b=%d\n",a,b);
    int c = a;
    a = b;
    b = c;
    printf("a=%d,b=%d\n", a, b);
}

int Sum(int a, int b)
{
    return a+b;
}

int difference(int a, int b)
{
    return a-b;
}

// 1, 1, 2, 3, 5, 8..
void printFibonacci(int count)
{
    if (count<3)
    {
        return;
    } 

    int start1 = 1;
    int start2 = 1;
    int tmp = 0;
    
    for (int i=3; i<=count; i+=1)
    {
        printf("%d+%d=%d\n", start1, start2, start1+start2);

        tmp = start1;
        start1 = start2;
        start2 = tmp + start2;
    }
}

void printFibonacci2(int count)
{
    if (count<3)
    {
        return;
    }

    int start1 = 1;
    int start2 = 1;
    int temp = 0;

    for (int i=3; i<=count; i+=1)
    {
        printf("%d+%d=%d\n", start1, start2, start1+start2);

        temp = start1;
        start1 = start2;
        start2 = start1 + temp;
    }

}

int factorialFormula(int num)
{
    if (num<0)
    {
        return -1;
    }
    
    int factorialOfNum = 1;
    
    for (int i=num; i>=1; i-=1)
    {
        factorialOfNum = factorialOfNum*i;
    }
    
    return factorialOfNum;
}

int factorialFormula2(int num)
{
    if (num<0)
    {
        return -1;
    }
    
    int factorialOfNum = 1;

    while (num>=1)
    {
        factorialOfNum *= num;
        num -= 1;
    }

    return factorialOfNum;
}

int factorialFormula3(int num)
{
    if (num<0)
    {
        return -1;
    }
    
    int factorialOfNum = 1;

    do
    {
        factorialOfNum *= num;
    } while (num-- >= 1);

    return factorialOfNum;
}

void printPAndC(int m, int n)
{
    if ( m<=0 || n<=0 || n>m)
    {
        return ;
    }
    
    int combination = factorialFormula(m)/(factorialFormula(n)*factorialFormula(m-n));
    int permutation = factorialFormula(m)/factorialFormula(m-n);

    printf("combination==%d, permutaion==%d\n", combination, permutation);
}


int geometricSequenceSum(int from, int to, int q)
{
    if (q == 0)
    {
        return 0;
    }

    int sum = 0;

    for (int i = from; i <= to; i *= q)
    {
        sum += i;
    }
    
    return sum;
}

int geometricSequenceSum2(int from, int to, int q)
{
    if (q == 0)
    {
        return 0;
    }
    
    int qn = 1;
    
    for(int n = from; n <= to; n *= q)
    {
        qn *= q;//qn = qn * q
    }

    // a1 * (1 - q(n)) / (1-q)

    return from * (1-qn)/(1-q);
}

int sumOfConsequtiveNum(int from, int to)
{
    int n = to - from + 1;
    
    return n * ( from + to )/2;
}

void testFunction()
{
    if ((factorialFormula(66) == factorialFormula2(66)) && (factorialFormula2(66) == factorialFormula3(66)))
    {
        printf("%s\n", "OH YESSSSSS :)");
    }
    else
    {
        printf("%s\n","Oh No :(");
    }    

    int result = geometricSequenceSum(3,243,3);
    printf("%d\n",result);
   int tmp = 0;
    printf("Give me an integer:");
    scanf("%d", &tmp);
    while (tmp > 0)
    {
        printf("Give me an integer:");
        scanf("%d", &tmp);
        printf("%d\n", tmp);
    }
}

int numOfAscendAndDescend()
{
    int count = 0;
    const int midNumber = 8;
    for (int i=1; i<midNumber; ++i)
    {
        for (int j=i+1; j<midNumber; ++j)
        {
            for (int k=midNumber-1; k>=0; --k)
            {
                for (int m=k-1; m>=0; --m)
                {
                    if ((i<j) && (m<k) && (i!=k) && (i!=m) && (j!=k) && (j!=m))
                    {
                        count += 1;
                    }
                }
            }
        }
    }

    return count;
}

int permutation(int m, int n)
{
    if (m < n)
    {
        return 0;
    }
    return factorialFormula2(m)/factorialFormula2(m-n);
}

int permutationProblem1()
{
    int count = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if ((i != j) && (j != k) && (k != i))
                {
                    int num = 100*i + 10*j + k;
                    printf("%d\n", num);
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);

    int fastCount = permutation(4,3);
    printf("%d\n", fastCount);

    int dict[10] = {0};
    int count2 = 0;
    // 1,3,4,9
    dict[1] = dict[3] = dict[4] = dict[9] = 1;

    for (int i = 0; i < 10; i++)
    {
        if (dict[i] == 0)
            continue;

        for (int j = 0; j < 10; j++)
        {
            if (dict[j] == 0)
                continue;
            
            for (int k = 0; k < 10; k++)
            {
                if (dict[k] == 0)
                    continue;

                if ((i != j) && (j != k) && (k != i))
                {
                    int num = 100*i + 10*j + k;

                    count2++;
                }
            }
        }
    }
    
    printf("%d\n", count2);

    return 0;
}

int permutationProb2()
{
    int dict[10] = {0};
    //1,3,8,9
    dict[1] = dict[3] = dict[8] = dict[9] = 1;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (dict[i] == 0)
        {
            continue;
        }
        
        for (int k = 0; k < 10; k++)
        {
            if (dict[k] == 0)
            {
                continue;
            }

            for(int j = 0; j < 10; j++)
            {
                if (dict[j] == 0)
                {
                    continue;
                }

                if ((i != j) && (j != k) && (i != k))
                {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);

    int fastCount = permutation(4,3);
    printf("%d\n", fastCount);

    return 0;
}

int main()
{
    //printf("%d\n", numberOfAscend5Digit());
    
    /*int number = numberOfAscend3Digit();
    printf("%d\n", number);

	return 0;*/

    //permutationProblem1();

    //permutationProb2();

    example4();
}

int slowSumOfConsecutiveNum(int from, int to)
{
    int sum = 0;
    
    for (int i = from; i <= to; i +=1)
    {
        sum += i;
    }

    return sum;
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