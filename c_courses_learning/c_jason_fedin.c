#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int pointerLearning()
{
    int count = 10, x;
    int *int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i, x = %i\n", count, x);
    return 0;
}

void gcdOf2Nums(int a, int b)
{
    int gcd = 1;

    int smaller = (a < b) ? a : b;
    for (int i = 1; i <= smaller; i++) 
    {
        if (a % i == 0 && b % i == 0) 
        {
            gcd = i;
        }
    }

    printf("The gcd of %d and %d is %d", a, b, gcd);
}

void weather()
{
    float arr[5][12] = {
        {7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.3, 0.5, 1.7, 3.6, 6.7},
        {7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.3, 0.5, 1.7, 3.6, 6.7},
        {7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.3, 0.5, 1.7, 3.6, 6.7},
        {7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.3, 0.5, 1.7, 3.6, 6.7},
        {7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.3, 0.5, 1.7, 3.6, 6.7}
    };

    int sum = 0;
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            sum += arr[i][j];
            count++;
        }
    }

    printf("Sum = %d\nAverage = %d\n", sum, sum/count);
}

void findAllPrimeFrom3To100()
{
    int j;

    for (int i = 3; i <= 100; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0) {
                break;
            }
        }
        if (i == j)
        {
            printf("%d ", i);
        }
    }
}

//豆包写的：
#include <math.h>
// Function to print a pentagram
void printPentagram(int size) {
    // Outer loop for rows
    for (int y = size; y >= -size; y--) {
        // Inner loop for columns
        for (int x = -size; x <= size; x++) {
            // The following angles are used to calculate the position of the pentagram
            double angles[5] = {0, 2 * M_PI / 5, 4 * M_PI / 5, 6 * M_PI / 5, 8 * M_PI / 5};
            int isStar = 0;
            for (int i = 0; i < 5; i++) {
                int j = (i + 2) % 5;
                // Calculate the start and end points of each line segment of the pentagram
                double x1 = size * cos(angles[i]);
                double y1 = size * sin(angles[i]);
                double x2 = size * cos(angles[j]);
                double y2 = size * sin(angles[j]);
                // Use the line - equation formula to check if the current point is on the line segment
                double left = (y - y1) * (x2 - x1);
                double right = (y2 - y1) * (x - x1);
                if (fabs(left - right) < 1.0) {
                    isStar = 1;
                    break;
                }
            }
            if (isStar) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void findTreasure() {
    srand(time(NULL));
    int treasureX = rand() % 5;
    int treasureY = rand() % 5;
    printf ("%d %d\n", treasureX, treasureY);
    int guessX, guessY;
    printf("Welcome to the treasure - finding game! The treasure is hidden in a 5x5 map.\n");
    printf("You can enter coordinates (0 - 4) to find the treasure. The format is: row column.\n");
    while (1) {
        printf("Please enter the coordinates you guessed: ");

        if (scanf("%d %d", &guessX, &guessY) != 2) {
            printf("Invalid input. Please enter two integers separated by a space.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (guessX < 0 || guessX > 4 || guessY < 0 || guessY > 4) {
            printf("The entered coordinates are out of range. Please enter numbers between 0 and 4.\n");
            continue;
        }
        if (guessX == treasureX && guessY == treasureY) {
            printf("Congratulations! You've found the treasure!\n");
            printPentagram(10);
            break;
        } else {
            printf("Sorry, there's no treasure here. Try again.\n");
        }
    }
}

int months()
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for (int i = 0; i < 12; i++)
    {
        printf("Month %d has %d days.\n", i+1, days[i]);
    }

    return 0;
}

void findAverageGrade()
{
    int grades[10];
    int count = 10;
    long sum = 0;
    float average = 0.0f;

    printf("\nEnter the 10 grades:\n");

    for(int i = 0; i < count; ++i)
    {
      printf("%2u> ",i + 1);
      scanf("%d", &grades[i]);
      sum += grades[i];
    }

    average = sum/count;
    printf("The average of the ten grades is %f\n", average);
}

void sum()
{
    int num = 0;
    printf("Enter an INTEGER\n");
    scanf("%d", &num);
    
    int sum = 0;

    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    printf("sum: %d\n", sum);
}

void randomNumDisplay()
{
    int num = 0;
    scanf("%d", &num);

    while (num < 35)
    {
        printf("%d\n", num);
        scanf("%d", &num);
        while (getchar() != '\n');
    }
}

void twoDimArray()
{
	int arr[2][3] = {[0][0] = 12, [0][1] = 24, [1][0] = 36, [1][1] = 48, [1][2] = 60};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d", arr[i][j]);
			if (j %3 == 0)
			{
				printf("\n");
			}
		}
	}
}


void sizeofTypes()
{
    char a = 127;
    a++;
    assert(a == -128);
    

    unsigned char b = 0;
    b--;
    assert(b == 255);

    unsigned char bb = (0xFF);
    ++b;
    assert(b == 0);

    int c = 2147483647;
    c++;
    assert(c == -2147483648);
    c-=2;
    assert(c == 2147483646);

    int c2 = -2147483647;
    c2++;
    assert(c2 == -2147483646);

    unsigned int d = 0U;
    d--;
    assert(d == 4294967295);
}

void sumOfFirstNIntegers()
{
    unsigned num = 0;
    unsigned long long sum = 0;

    printf("Enter the number of intergers you want to sum:\n");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    printf ("The sum of the first %d integers is %llu.\n", num, sum);
}

int today()
{
    enum weekday {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    enum weekday today = Friday;

    switch (today)
    {
        case Monday:
        printf("Today is Monday:(\n");
        break;

        case Wednesday:
        printf("Today is Wednesday:|\n");
        break;

        case Friday:
        printf("Today is Friday!!!\n");
        break;

        default:
       printf("Whatever *sideeye\n");
       break;
    }

    return 0;
}

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

void ifNumIsEvenOrOdd2()
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
        printf("Enter a guess:\n");
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

void printSizeOfTypes(int* pointerOfArray)
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
    

    //guessNum();
    //ifNumIsEvenOrOdd();

    gcdOf2Nums(123, 234);
    twoDimArray();
    */
   
    pointerLearning();

    return 0;
}
