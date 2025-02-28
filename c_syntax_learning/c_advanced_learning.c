#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_advanced_learning.h"
#include "../utils.h"
#include <stdlib.h>

int reverseBinaryNum(int num)
{
    unsigned int unum = (unsigned int)num;

    int count = 0;

    for (int i = 0; i < sizeof(unum)*8; i++)
    {
        count <<= 1;
        count |= (unum & 0x1);
        unum >>= 1;
    }

    return count;
}

int numOf1sInABinaryNum(int num)
{
    unsigned int unum = (unsigned int)num;
    int count = 0;

    for (int i = 0; i < sizeof(num) * 8; i++)
    {
        count += (unum & 0x1);

        unum = unum >> 1;
    }
    return count;
}

int absValue(int num)
{
    if (num >= 0)
    {
        return num;
    }

    int absValOfNum = (~num + 1);

    return absValOfNum;
}

void isOdd()
{
    int num = 0;
    printf ("Enter an integer\n");
    scanf ("%d", &num);

    if ((num & 1) == 0)
    {
        printf("%d is an even number\n", num);
    }
    else
    {
        printf("%d is an odd number\n", num);
    }
}

void swap(int a, int b)
{
    printf("a: %d, b: %d\n", a, b);
    int temp = a ^ b;
    a = temp ^ a;
    b = temp ^ b;
    printf("a: %d, b: %d\n", a, b);
}

int isPowerOfTwo(int num)
{
    int nonZeroCount = 0;
    unsigned int unum = (unsigned int)num;
    for (int i=0; i<sizeof(num)*8 && unum > 0; i++)
    {
        nonZeroCount += (unum & 0x1);
        unum = unum >> 1;

        if (nonZeroCount > 1)
        {
            break;
        }
    }

    return nonZeroCount == 1;
}

int isPowerOfTwo_Fast(int num)
{
    return num > 0 && (num & (num - 1)) == 0;
}

void testPowerOf2()
{
    assert((isPowerOfTwo(32)) == (isPowerOfTwo_Fast(32)));
    assert((isPowerOfTwo(33)) == (isPowerOfTwo_Fast(33)));
    assert((isPowerOfTwo(64)) == (isPowerOfTwo_Fast(64)));
}

void hexadecimal()
{
    printf("0x3333 & 0xCCCC: %x\n", 0x3333 & 0xCCCC);
    assert((0x3333 & 0xCCCC) == 0);

    printf("0xFF00 & 0x00FF: %x\n", 0xFF00 & 0x00FF);
    assert((0xFF00 & 0x00FF) == 0);

    printf("0xAAAA & 0x5555: %x\n", 0xAAAA & 0x5555);
    assert((0xAAAA & 0x5555) == 0);

    printf("0x1234 & 0xABCD: %x\n", 0x1234 & 0xABCD);
    assert((0x1234 & 0xABCD) == 0x0204);

    printf("0x8888 & 0x7777: %x\n", 0x8888 & 0x7777);
    assert((0x8888 & 0x7777) == 0);

    printf("0x3333 | 0xCCCC: %x\n", 0x3333 | 0xCCCC);
    assert((0x3333 | 0xCCCC) == 0xFFFF);

    printf("0xFF00 | 0x00FF: %x\n", 0xFF00 | 0x00FF);
    assert((0xFF00 | 0x00FF) == 0xFFFF);

    printf("0xAAAA | 0x5555: %x\n", 0xAAAA | 0x5555);
    assert((0xAAAA | 0x5555) == 0xFFFF);

    printf("0x1234 | 0xABCD: %x\n", 0x1234 | 0xABCD);
    assert((0x1234 | 0xABCD) == 0xBBFD);

    printf("0x8888 | 0x7777: %x\n", 0x8888 | 0x7777);
    assert((0x8888 | 0x7777) == 0xFFFF);

    printf("0x3333 ^ 0xCCCC: %x\n", 0x3333 ^ 0xCCCC);
    assert((0x3333 ^ 0xCCCC) == 0xFFFF);

    printf("0xFF00 ^ 0x00FF: %x\n", 0xFF00 ^ 0x00FF);
    assert((0xFF00 ^ 0x00FF) == 0xFFFF);

    printf("0xAAAA ^ 0x5555: %x\n", 0xAAAA ^ 0x5555);
    assert((0xAAAA ^ 0x5555) == 0xFFFF);

    printf("0x1234 ^ 0xABCD: %x\n", 0x1234 ^ 0xABCD);
    assert((0x1234 ^ 0xABCD) == 0xB9F9);

    printf("0x1234 | 0xABCD: %x\n", 0x1234 | 0xABCD);
    assert((0x1234 | 0xABCD) == 0xBBFD);

    printf("0x8888 | 0x7777: %x\n", 0x8888 | 0x7777);
    assert((0x8888 | 0x7777) == 0xFFFF);

    printf("0x3333 ^ 0xCCCC: %x\n", 0x3333 ^ 0xCCCC);
    assert((0x3333 ^ 0xCCCC) == 0xFFFF);

    printf("0xFF00 ^ 0x00FF: %x\n", 0xFF00 ^ 0x00FF);
    assert((0xFF00 ^ 0x00FF) == 0xFFFF);

    printf("0xAAAA ^ 0x5555: %x\n", 0xAAAA ^ 0x5555);
    assert((0xAAAA ^ 0x5555) == 0xFFFF);

    printf("0x1234 ^ 0xABCD: %x\n", 0x1234 ^ 0xABCD);
    assert((0x1234 ^ 0xABCD) == 0xB9F9);

    printf("0x8888 ^ 0x7777: %x\n", 0x8888 ^ 0x7777);
    assert((0x8888 ^ 0x7777) == 0xFFFF);

    printf("~0x1234: %x\n", ~0x1234);
    assert((~0x1234) == 0xFFFFEDCB);

    printf("~0xABCD: %x\n", ~0xABCD);
    assert((~0xABCD) == 0xFFFF5432);

    printf("~0x0000: %x\n", ~0x0000);
    assert((~0x0000) == 0xFFFFFFFF);

    printf("~0xFFFF: %x\n", ~0xFFFF);
    assert((~0xFFFF) == 0xFFFF0000);

    printf("~0x8000: %x\n", ~0x8000);
    assert((~0x00008000) == 0xFFFF7FFF);

}

typedef enum _Gender
{
	MALE,
	FEMALE,
} Gender;

typedef struct _IsbStudent
{
	char first_name[32];
	char *p_first_name;
	char last_name[32];
	Gender gender;
	unsigned int math_score;
	unsigned int language_usage_score;
	unsigned int reading_score;
} IsbStudent;

void meanMedianAndRange()
{
    double arr[5];
    double temp;
    printf("Enter 5 numbers that you want to find the mean, median, and range of.\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &arr[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    double mean = (arr[0] + arr[1] + arr[2] + arr[3] + arr[4]) / 5;
    double range = arr[4] - arr[0];
    double median = arr[2];

    printf("Mean: %f\nMedian: %f\nRange: %f\n", mean, median, range);
}

void surveyResult()
{
    int deepseek = 0;
    int CiCi = 0;
    int chatGpt = 0;

    int num = 0;

    printf ("Which of the following AI chat boxes do you think is the best?\n1.Deepseek\n2.CiCi\n3.ChatGpt\n");
    scanf ("%d", &num);
    if (num == 1)
    {
        deepseek++;
    }
    else if (num == 2)
    {
        CiCi++;
    }
    else
    {
        chatGpt++;
    }
}

int strChallenge(const char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }

    printf ("%d\n", count-1);
    return count;
}

void reverseStr(const char* str)
{
    int count = 0;
    count = strChallenge(str);

    for (int i = 0; i < count/2; i++)
    {
        printf("%d", str[i]);
    }

    printf("\n");
}

void str()
{
    char arr[100] = {'H', 'E', 'L', 'L', 'O', '!'};

    for (int i = 0; i < 100; i++)
    {
        printf ("%c\n", arr[i]);
    }
}

int ticTacToe()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int moves = 0;
    char player = 'X';
    int position;
    int win = 0;

    int wins[8][3] = 
    {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}
    };

    while (moves < 9 &&!win)
    {
        for (int i = 0; i < 9; i++)
        {
            printf(" %c ", board[i]);
            if ((i + 1) % 3 != 0) printf("|");
            if ((i + 1) % 3 == 0) printf("\n");
            if ((i + 1) % 3 == 0 && i < 8) printf("---+---+---\n");
        }

        printf("Player %c, enter position (1 - 9): ", player);
        scanf("%d", &position);

        if (position < 1 || position > 9 || board[position - 1] != ' ')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[position - 1] = player;
        moves++;

        for (int i = 0; i < 8; i++)
        {
            if (board[wins[i][0]] == player && board[wins[i][1]] == player && board[wins[i][2]] == player)
            {
                win = 1;
                break;
            }
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    for (int i = 0; i < 9; i++)
    {
        printf(" %c ", board[i]);
        if ((i + 1) % 3 != 0) printf("|");
        if ((i + 1) % 3 == 0) printf("\n");
        if ((i + 1) % 3 == 0 && i < 8) printf("---+---+---\n");
    }

    if (win)
    {
        printf("Player %c wins!\n", (player == 'X') ? 'O' : 'X');
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}

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
    }

    int num1 = 123;
    int num2 = -123;
    int num3 = 120;

    printf("Reversed of %d is %d\n", num1, reverse(num1));
    printf("Reversed of %d is %d\n", num2, reverse(num2));
    printf("Reversed of %d is %d\n", num3, reverse(num3));
    */
    /*
    IsbStudent suri_class[20] = {0};

	suri_class[0].gender = FEMALE;
	suri_class[0].math_score = 99;
	suri_class[0].language_usage_score = 94;
	suri_class[0].reading_score = 92;

	strncpy(suri_class[0].first_name, "suri", sizeof(suri_class[0].first_name)-1);
	suri_class[0].first_name[sizeof(suri_class[0].first_name)-1] = '\0';

	strncpy(suri_class[0].last_name, "xing", sizeof(suri_class[0].last_name)-1);
	suri_class[0].last_name[sizeof(suri_class[0].last_name)-1] = '\0';

	IsbStudent* pCurrent = &suri_class[0];

	// pCurrent->first_name
	// pCurrent++;
	// pCurrent->last_name

	int num = 0;

	num = 1+1;
    printf("%d\n", !num);
    num = -1;
    printf("%d\n", !num);
    num = 0;
    printf("%d\n", !num);

	num = 0xffffffff;
    printf("%x\n", ~num);

    printf("%x\n", num<<1);

	num = 0x55555555;
    printf("%x\n", ~num);

    printf("%x\n", num<<1);
    printf("%x\n", num<<2);
    printf("%x\n", num<<3);

    printf("%x\n", num>>1);
    printf("%x\n", num>>2);
    printf("%x\n", num>>3);

	unsigned int unum = 0x55555555;
    printf("%x\n", unum>>1);
    printf("%x\n", unum>>2);
    printf("%x\n", unum>>3);

	printf("%x\n", 0x5555 & 0xAAAA);
	printf("%x\n", 0x5555 | 0xAAAA);
	printf("%x\n", 0x5555 ^ 0xAAAA);
	printf("%x\n", 0x5555 ^ 0x5555);
	printf("%x\n", 0xAAAA ^ 0xAAAA);

	int *p = &num;
	num=1;
	*p=2;
    */

    // hexadecimal();


    assert(numOf1sInABinaryNum(0x1) == 1);
    assert(numOf1sInABinaryNum(0xF) == 4);
    assert(numOf1sInABinaryNum(0xF0) == 4);
    assert(numOf1sInABinaryNum(0xF00) == 4);
    assert(numOf1sInABinaryNum(0xF000) == 4);
    assert(numOf1sInABinaryNum(0xFF00) == 8);
    assert(numOf1sInABinaryNum(0xFFF0) == 12);
    assert(numOf1sInABinaryNum(0xFFFFFFFF) == 32);
    assert(numOf1sInABinaryNum(0xFFFF) == 16);

    assert(reverseBinaryNum(0xFFFFFFFF) == 0xFFFFFFFF);
    assert(reverseBinaryNum(0xFFFF0000) == 0xFFFF);
    assert(reverseBinaryNum(0xFFFF) == 0xFFFF0000);
    assert(reverseBinaryNum(0X55555555) == 0XAAAAAAAA);
    assert(reverseBinaryNum(0XAAAAAAAA) == 0X55555555);

    return 0;
}