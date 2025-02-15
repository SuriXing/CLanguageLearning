#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_advanced_learning.h"
#include "../utils.h"
#include <stdlib.h>

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

// Function to find two sum indices
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int *result = (int *)malloc(2 * sizeof(int));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    free(result);
    return NULL;
}

int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow before updating the result
        if (reversed > (2147483647 / 10) || (reversed == (2147483647 / 10) && pop > 7)) return 0;
        if (reversed < (-2147483648 / 10) || (reversed == (-2147483648 / 10) && pop < -8)) return 0;

        reversed = reversed * 10 + pop;
    }
    return reversed;
}


int  main()
{
    //int i = 15;
    //printf("%d 的阶乘为 %f\n", i, factorial(i));
    //return 0;
    /*int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }*/

    int num1 = 123;
    int num2 = -123;
    int num3 = 120;

    printf("Reversed of %d is %d\n", num1, reverse(num1));
    printf("Reversed of %d is %d\n", num2, reverse(num2));
    printf("Reversed of %d is %d\n", num3, reverse(num3));

    return 0;
}