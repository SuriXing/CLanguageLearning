#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum _Roman
{
    I,
    V,
    X,
    L,
    C,
    D,
    M
} Roman;

typedef enum _MyInteger
{
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    TEN = 10,
    HUNDRED = 100,
    THOUSAND = 1000,
} MyInteger;

int intValueOfRoman(Roman romanCharacter)
{
    /*
    罗马数字共有七个，即I (1)，V (5)，X (10)，L (50)，C (100)，D (500)，M (1000)
    */
    switch (romanCharacter)
    {
        case I:
            return 1;
        break;

        case V:
            return 5;
        break;

        case X:
            return 10;
        break;

        case L:
            return 50;
        break;

        case C:
            return 100;
        break;

        case D:
            return 500;
        break;

        case M:
            return 1000;
        break;

        default:
            assert(0);
        break;
    }

    return 0;
}

Roman romanOfIntValue(int value)
{
    switch (value)
    {
        case 1:
            return I;
        break;

        case 5:
            return V;
        break;

        case 10:
            return X;
        break;
    
        case 50:
            return L;
        break;

        case 100:
            return C;
        break;

        case 500:
            return D;
        break;

        case 1000:
            return M;
        break;
        
        default:
            assert(0);
        break;
    }

    return I;
}

int jasonFedin1stLesson()
{
    int jason = 6;

    jason = 8;

    return jason;
}

int jasonFedin2ndLesson()
{
    return 0;
}

int main()
{
    int jason = jasonFedin1stLesson();
    printf("%d\n", jason);

    printf("%d\n", ONE);
    printf("%d\n", TWO);
    printf("%d\n", THREE);
    printf("%d\n", THOUSAND);
    return 0;
}