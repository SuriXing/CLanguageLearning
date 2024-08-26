#include <stdio.h>

int g()
{
	return 3;
}

int f(int x)
{
    int a = 3; // variable
    int b = 1;
    int c;  // random number
    
    printf("a=%d\n", a);
    a = 5;
    printf("a=%d\n", a);
    printf("c=%d\n", c);
    
    if (a == 5)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
	return a*x+b;
}

int printOddNumber() {
    for (int i=1; i<100; i+=2)
    {
        printf("%d\n", i);
    }
    
    return 0;
}

int printEvenNumber() {
    for (int i=2; i<100; i=i+2)
    {
        printf("%d\n", i);
    }
    return 0;
}

int printFiveXNumber() {
    for (int i=5; i<=100; i+=5)
    {
        printf("%d\n", i);
    }
    
    return 0;
}

int printFiveXNotSevenNumber() {
    for (int i=5; i<=100; i+=5)
    {
        if (i % 7 != 0) 
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

int printFiveXNotTenNumber() {
    for (int i=5; i<=100; i+=5) {
        if (i % 10 != 0) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

int main()
{
    f(3);
/*
    printFiveXNumber();

    printf("hhhhhhhhhhhh\n");
    
    printFiveXNotTenNumber();

	for (int x=1; x<10; ++x) {
		printf("Suri is smart!\t%d:%d\n", x, f(x));
	}
*/
	return 0;
}


//	float f = getRandomFloat(3);
//	fprintf(stdout, "Suri is smart!\t%f\n", f);
//	fprintf(stdout, "Suri is smart!\n");

// This is a function
// Function name: get RandomFloat
// Return value: a double
// Input : an integer
float getRandomFloat(int suri)
{
	return suri+1.0;
}

double getRandomDouble()
{
	return 1.0;
}

