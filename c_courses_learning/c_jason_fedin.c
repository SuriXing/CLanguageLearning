#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

/*
void simpleGame()
{
    int gamesOver;

    if ( gamesOver == 0 )
    {
        if ( playerToMove == YOU )
        {
            printf("Your Move\n");
        }
        else
        {
            printf("My Move\n");
        }
    }
    else
    {
        printf("The game is over\n");
    }
}
*/

void aaa()
{
    int number, sign;
    
    printf("Please type in a number: ");
    scanf("%i", &number);
    
    if (number < 0)
    {
        sign = -1;
    }
    else if (number == 0)
    {
        sign = 0;
    }
    else
    {
        sign = 1;
    }   
    
    printf("Sign = %i\n", sign);
}

void ifNumIsEvenOrOdd()
{
    int num = 0;
    printf("Enter an integer:\n");
    
    while (1)
    {
        int res = scanf ("%d", &num);

        while (getchar() != '\n')
        {
            ;
        }

        if (res <= 0)
        {
            printf ("Invalid input, please enter an integer.\n");
            continue;
        }

        if (num % 2 == 0)
        {
            printf ("%d is even.\n", num);
        }
        else
        {
           printf ("%d is odd.\n", num);
        }
        break;
    }
}

void guessNum()
{
    srand(time(NULL));
    int num = rand() % 20 + 1;

    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n");

    for (int i = 5; i > 0; i--)
    {
        int userGuess = -1;
        printf ("You have %d tries left.\n", i);
        printf("Enter a guess:\n", i);
        //scanf("%d", &userGuess);
        
        int a = scanf("%d", &userGuess);

        while (getchar() != '\n')
        {
            ;
        }
        if (a <= 0)
        {
            printf("Invalid input. Please enter a number between 0 and 20.\n");
            continue;
        }
        

        if (userGuess == num)
        {
            printf("Congratulations. You guessed the number.\n");
            break;
        }
        else if (userGuess < 0 || userGuess > 20)
        {
            printf("Sorry, %d is invalid. My number is between 0 and 20.\n", userGuess);
        }
        else if (userGuess < num)
        {
            printf("Sorry, %d is wrong. My number is greater than that.\n", userGuess);
        }
        else
        {
            printf("Sorry, %d is wrong. My number is less than that.\n", userGuess);
        }
    }
}

#define SIZEOF(array) (sizeof(array)/sizeof(array[0]))

void printSizeOfTypes(int pointerOfArray[])
{
    printf("Size of char: %zd bytes\n", sizeof(char));
    printf("Size of short: %zd bytes\n", sizeof(short));
    printf("Size of int: %zd bytes\n", sizeof(int));
    printf("Size of long: %zd bytes\n", sizeof(long));
    printf("Size of long long: %zd bytes\n", sizeof(long long));
    printf("Size of float: %zd bytes\n", sizeof(float));
    printf("Size of double: %zd bytes\n", sizeof(double));
    printf("Size of long double: %zd bytes\n", sizeof(long double));

    int intArray[12];
    printf("Length of integer array: %zd bytes\n", SIZEOF(intArray));
    int charArray[12];
    printf("Length of character array: %zd bytes\n", SIZEOF(charArray));
    printf("Size of Pointer: %zd bytes\n", sizeof(pointerOfArray));

    int *ptr = NULL;
    printf("Size of Pointer: %zd bytes\n", sizeof(ptr));
}

typedef struct _Month {
    const char monthStr[16];
    const int daysPerMonth;
} Month;

int minConvert()
{
    const int kMinutesPerHour = 60;
    const int kHoursPerDay = 24;
    const int kDaysPerYear = 365;
    const int kMinutesPerDay = kMinutesPerHour * kHoursPerDay;
    const int kMinutesPerYear = kMinutesPerDay * kDaysPerYear;
    const Month kMonths[12] = {
        {"January", 31},
        {"February", 28},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31}
    };

    int minutes = 0;
    printf ("Enter the number of minutes:\n");
    scanf("%d", &minutes);

    int year = minutes / kMinutesPerYear;
    int day = (minutes % kMinutesPerYear) / kMinutesPerDay;
    int hour = ((minutes % kMinutesPerYear) % kMinutesPerDay) / kMinutesPerHour;
    int minute = ((minutes % kMinutesPerYear) % kMinutesPerDay) % kMinutesPerHour;
    int month = 0;
    
    for (int i = 0; i < 12; i++)
    {
        if (day > kMonths[i].daysPerMonth)
        {
            day -= kMonths[i].daysPerMonth;
        }
        else
        {
            month = i + 1;
            break;
        }
    }

    printf("%d minutes is approximately %d years and %s and %d days and %d hours and %d minutes.\n", 
        minutes, year, kMonths[month].monthStr, day, hour, minute);

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

    //guessNum();
    ifNumIsEvenOrOdd();

    return 0;
}