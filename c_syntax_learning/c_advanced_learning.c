#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_advanced_learning.h"
#include "../utils.h"

int perimeterAndAreaOfRectangle(int width, int length)
{
    int perimeter = 2 * (width + length);
    int area = width * length;

    printf("The area of this rectangle with width %d; length %d, has area %d, and lastlly perimeter %d\n", width, length, area, perimeter);

    return perimeter && area;
}

int isAccountInSystem(const Account* kAccountArray, const int kAccountArrayLength, Account account)
{
    assert(kAccountArray != NULL);
    assert(kAccountArrayLength > 0);

    for (int i=0; i<kAccountArrayLength; i++)
    {
        if (strcmp(kAccountArray[i].account_name, account.account_name) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int doesPasswordMatchAccount(const Account* kAccountArray, const int kAccountArrayLength, Account account)
{
    assert(kAccountArray != NULL);
    assert(kAccountArrayLength > 0);

    for (int i = 0; i < kAccountArrayLength; i++)
    {
        if ((strcmp(kAccountArray[i].account_name, account.account_name) == 0) && (strcmp(kAccountArray[i].password, account.password) == 0))
        {
            return 1;
        }
    }

    return 0;
}

int login()
{
    static const Account kAccounts[] = 
    {
        {"admin", "password"},
        {"suri.x", "bleah"}, 
        {"jingxia.x", "abc"},
        {"q.z", "xixi"},
        {"happy_squirrel", "pear"}
    };

    int retryCount =0;

    while (retryCount++ < RETRY_TIMES)
    {
        Account account;
        printf("Enter account name:\n");
        scanf("%255s", account.account_name);
        printf("Enter password(ONLY letters):\n");
        scanf("%255s", account.password);

        if (isAccountInSystem(kAccounts, STRING_LENGTH, account) == 0)
        {
            printf("Invalid user name\n");
        } 
        else if (doesPasswordMatchAccount(kAccounts, STRING_LENGTH, account) == 0)
        {
            printf("Wrong password\n");
        }
        else
        {
            printf("Welcome back, %s!\n", account.account_name);
            break;
        }
    }

    return (retryCount < RETRY_TIMES);
}


 
double factorial(unsigned int i)
{
   if(i <= 1)
   {
      return 1;
   }
   return i * factorial(i - 1);
}


int  main()
{
    int i = 15;
    printf("%d 的阶乘为 %f\n", i, factorial(i));
    return 0;
}