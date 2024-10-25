#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Only array and string need to add a andpersand in a scanf.

void sayHiAndAge(char name[], int age)
{
    printf("Hi %s and your currently %d years old.\n", name, age);
}

double cube(double num)
{
    double result = num * num * num;
    return result;
}

int main()
{
    char grade = 'A';
    switch(grade)
    {
        case 'A': printf("You did a great job!\n");
        break;
        case 'B': printf("You did fine.");
        break;
        case 'C': printf("You'll need more practice.");
        break;
        case 'F': printf("You trash.");
        break;
        default:printf("Invalid grade.");
    }
    
    
    /*double num1;
    double num2;
    char operator;

    printf("Enter a number:");
    scanf("%lf\n", &num1);
    printf("Enter an operator(+ or - or * or/)");
    scanf("%c\n", &operator);
    printf("Enter another number:");
    scanf("%lf\n", &num2);

    if(operator == '+')
    {
        printf("%f\n", num1 + num2);
    }
    else if(operator == '-')
    {
        printf("%f\n", num1 - num2);
    }
    else if(operator == '*')
    {
        printf("%f\n", num1 * num2);
    }
    else if(operator == '/')
    {
        printf("%f\n", num1/num2);
    }
    else
    {
        printf("invalid operator\n");
    }
    //                           ^^
    //improved calculator making ||
   
    double number = 0.0;
    double number = 0.0;
    printf("Enter a random number:");
    scanf("%lf", &number);
    double result2 = cube(number);
    printf("The cube of %lf is %lf\n", number, result2);
    
    
    sayHiAndAge("Jennie", 15);
    sayHiAndAge("Taylor", 38);
    sayHiAndAge("Lisa", 23);
    sayHiAndAge("Minnie", 22);
    
    int luckynumbers[] = {2, 6, 8, 5, 10};
    printf("My fifth lucky number is %d\n",luckynumbers[4]);
    char phrase[50] = "My fifth lucky number is";
    printf("%s %d\n", phrase, luckynumbers[4]);

    char color[100];
    char color[100];
    char pluralNoun[100];
    char celebrity[100];
    printf("Enter the name of a color:");
    scanf("%s", color);
    printf("Enter the name of a plural noun:");
    scanf("%s", pluralNoun);
    printf("Enter the name of your faverite celebrity:");
    scanf("%s", celebrity);
    //实行中：
    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("And I love %s\n", celebrity);
    //                    ^^
    //mad lib game making ||
    
    double num1;
    double num2;
    printf("Enter your first number:");
    scanf("%lf", &num1);
    printf("Enter your second number:");
    scanf("%lf", &num2);
    printf("The answer is %f", num1 + num2);
    //                           ^ ^
    //2 number calculator making | |    
    
    double gpa = 0;
    printf("Enter your gpa score :");
    scanf("%lf", &gpa);
    printf("Your gpa score is %lf\n", gpa);

    char name[20];
    printf("Enter your name:");
    scanf("%s", name);
    printf("Your name is %s\n",name);

    //&name[0] == name;
    const int Num = 25;
    printf("%d\n", Num);
    const int Number = 26;
    printf("This number can't be changed; %d\n", Number);
    
    printf("%lf\n", pow(2,3));//2 to the third power
    printf("%lf\n", sqrt(225));//225's square root
    printf("%lf\n", ceil(37.13245));//37.13245 向上取整
    printf("%lf\n", floor(26.897));//26.897 向下取整
    printf("%lf\n", 25/4.0);//is 4.0 because else it'll return back an integer since it's two integers and computer will assume that the answer is also an integer
    printf("%d\n",475+75);
    
    
    printf("Hello\"world\n");
    printf("Hello\'world\n");
    int favNum = 25;
    char favChar = 's';
    char favNumP[] = "favorite number";
    printf("My %s is %d\n", favNumP, favNum);
    
    int number = 12;
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