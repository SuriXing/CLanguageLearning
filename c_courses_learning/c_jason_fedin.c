#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int minConvertToDayAndYear()
{
    const int MinutesPerHour = 60;
    const int HoursPerDay = 24;
    const int DaysPerYear = 365;
    const int MinutesPerDay = MinutesPerHour * HoursPerDay;
    const int MinutesPerYear = MinutesPerDay * DaysPerYear;

    int minutes = 0;
    printf ("Enter the number of minutes:\n");
    scanf("%d", &minutes);

    int year = minutes / MinutesPerYear;
    int day = (minutes % MinutesPerYear) / MinutesPerDay;
    int hour = ((minutes % MinutesPerYear) % MinutesPerDay) / MinutesPerHour;
    int minute = ((minutes % MinutesPerYear) % MinutesPerDay) % MinutesPerHour;

    printf("%d minutes is approximately %d years and %d days.\n", minutes, year, day);

    return 0;
}

int operators()
{
    unsigned int a = 50; // 二进制: 0011 0010
    unsigned int b = 25; // 二进制: 0001 1001
    unsigned int result; // 用于存储每次运算的结果

    result = a & b;
    printf("a & b = %u\n", result);

    result = a | b;
    printf("a | b = %u\n", result); 

    result = a ^ b;
    printf("a ^ b = %u\n", result); 

    result = ~a;
    printf("~a = %u\n", result);

    result = a << 2;
    printf("a << 2 = %u\n", result); 

    result = a >> 2;
    printf("a >> 2 = %u\n", result); 

    return 0;
}

void math()
{
    printf("Enter a number:\n");
    int a = 0;
    scanf("%d", &a);
    printf("Enter another number:\n");
    int b = 0;
    scanf("%d", &b);

    int sum = a+b;
    printf("Sum = %d\n", sum);

    int product = a * b;
    printf("product = %d\n", product);
}

enum Company 
{
    GOOGLE,
    FACEBOOK,
    XEROX,
    YAHOO,
    EBAY,
    MICROSOFT
};

void perimeterAndAreaOfRectangles(int width, int length)
{
    int perimeter = 2 * (width + length);
    int area = width * length;

    printf ("The area of this %d * %d rectangle is %d\n", width, length, area);
    printf ("The perimeter of this %d * %d rectangle is %d\n", width, length, perimeter);
}

void argumentLearning(int argc, char* argv[])
{
    printf("Number of arguments: %d\n", argc);
    printf("Argument 1 is the program name: %s\n", argv[0]);

    for (int i = 1; i < argc; i++)
    {
        printf("Argument %d is the command line argument: %s\n", i+1, argv[i]);
    }
}

void formatSpecifiers()
{
    int intNum = 100;
    char letter = 'a';
    float floatNum = 2.545;
    double doubleNum = 8.44e+11;

    printf("integer: %d\n", intNum);
    printf("char: %c\n", letter);
    printf("float: %f\n", floatNum);
    printf("double1(e): %e\n", doubleNum);
    printf("double2(g): %g\n", doubleNum);
    printf("double3(lf): %lf\n", doubleNum);
}

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

int main(int argc, char* argv[])
{
    /*
    formatSpecifiers();

    printf("\n\n\n");

    int jason = jasonFedin1stLesson();
    printf("%d\n", jason);

    printf("%d\n", ONE);
    printf("%d\n", TWO);
    printf("%d\n", THREE);
    printf("%d\n", THOUSAND);

    argumentLearning(argc, argv);

    perimeterAndAreaOfRectangles(15, 20); 

    enum Company company1 = XEROX;
    enum Company company2 = GOOGLE;
    enum Company company3 = EBAY;

    printf("%d\n", company1);
    printf("%d\n", company2);
    printf("%d\n", company3);
    */

    minConvertToDayAndYear();

    return 0;
}