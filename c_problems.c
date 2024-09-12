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

int main()
{
    printTimesTable();
}