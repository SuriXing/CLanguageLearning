#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello\"world\n");
    printf("Hello\'world\n");

    int favNum = 25;
    char favChar = 's';
    char favNumP[] = "favorite number";
    printf("My %s is %d\n", favNumP, favNum);
    
    /*int number = 12;
    double gpa = 4.0;
    char grade = 'A';
    char schoolGrade[] = "mastering";
    
    char characterName[] = "Cookie";
    int characterAge = 15;
    printf("His name is %s.\n", characterName);
    printf("He is %d minutes old.\n", characterAge);
    printf("He really liked his name, %s.\n", characterName);
    printf("But he hates being %d minutes old because it's his unlucky number.\n", characterAge);

    char test[100] = "";

    sprintf(test, "%d minutes", characterAge);

    printf("%s\n", test);*/

    return 0;
}