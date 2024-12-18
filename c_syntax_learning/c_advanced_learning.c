#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_advanced_learning.h"
#include "../utils.h"

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

void cAdvancedLearningTest()
{
    login();
}