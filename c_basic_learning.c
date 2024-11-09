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

int example5()
{
    int max = 0;
    int mid = 0;
    int min = 0;
    int num = 0;
    printf("Please enter the three numbers:\n");
    scanf("%d,%d,%d", &max, &mid, &min);

    if (mid < min)
    {
        num = min;
        min = mid;
        mid = num;
    }
    num = 0;
    if (max < min)
    {
        num = min;
        min = max;
        max = num;
    }
    num = 0;
    if (max < mid)
    {
        num = mid;
        mid = max;
        max = num;
    }

    printf("From the greatest to smallest: %d, %d, %d\n", max, mid, min);
    return 0;
}

 
#define ARRAY_LENGTH 5

int new_example5()
{
    int nums[ARRAY_LENGTH];

    printf("Please enter the three numbers:\n");
    scanf("%d,%d,%d,%d,%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

    for (int i=0; i<ARRAY_LENGTH-1; i++)
    {
        for (int j=i+1; j<ARRAY_LENGTH-1; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    
    printf("From the greatest to smallest: %d, %d, %d\n", nums[4], nums[3], nums[2]);
    return 0;
}

int main()
{
    new_example5();
    return 0;
}   