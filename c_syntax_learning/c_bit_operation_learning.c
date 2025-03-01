#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "c_advanced_learning.h"
#include "../utils.h"
#include <stdlib.h>


int reverseBinaryNum(int num)
{
    unsigned int unum = (unsigned int) num;

    int count = 0;

    for (int i = 0; i < sizeof(unum) * 8; i++)
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

int numOf1sInABinaryNum2(int num)
{
    unsigned int unum = (unsigned int)num;

    int count = 0;

    for (int i = 0; i < sizeof(num) * 8; i++)
    {
        count += ((unum & 0x80000000) >> 31);
        unum = unum << 1;
    }

    return count;
}


int absValue(int num)
{
    if (num >= 0)
    {
        return num;
    }

    int absvalueOfNum = ~num + 1;

    return absvalueOfNum;
}

int isOdd(int num)
{
    return (num & 0x1);
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
    int count = 0;
    unsigned int unum = (unsigned int)num;
    for (int i=0; i<sizeof(num)*8; i++)
    {
        count += (unum & 0x1);
        unum = unum >> 1;

        if (count > 1)
        {
            break;
        }
    }

    return count == 1;
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

int main()
{
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

    assert(numOf1sInABinaryNum2(0x1) == 1);
    assert(numOf1sInABinaryNum2(0xF) == 4);
    assert(numOf1sInABinaryNum2(0xF0) == 4);
    assert(numOf1sInABinaryNum2(0xF00) == 4);
    assert(numOf1sInABinaryNum2(0xF000) == 4);
    assert(numOf1sInABinaryNum2(0xFF00) == 8);
    assert(numOf1sInABinaryNum2(0xFFF0) == 12);
    assert(numOf1sInABinaryNum2(0xFFFFFFFF) == 32);
    assert(numOf1sInABinaryNum2(0xFFFF) == 16);

    return 0;
}