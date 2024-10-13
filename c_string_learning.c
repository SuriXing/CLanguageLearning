#include <stdio.h>
#include <string.h>

#pragma mark -- function declaration --
int myLenOfStr(const char* str);
void printString(const char* str);

int main()
{
    const char* kDemoStr = "I am a demo string";    // a string
    char demoCharArray[] = "I am a demo character array";    // a character array
    demoCharArray[0] = 'Y';

    int arr[11] = {0};
    arr[0] = 1;

    for (int i = 0; i < 256; i++)
    {
        printf("%c\n", (char)i);
    }
    printf("%c\n", (char)47);
    printf("%d\n", (int)'1');
    printf("%d\n", (int)'9');
    printf("%d\n", (int)'a');
    printf("%d\n", '\0');

    int lenOfStr = strlen(kDemoStr);
    printf("Length of String: %d\n", lenOfStr);

    int res = myLenOfStr(kDemoStr);
    printf("My length of String: %d\n", res);

    if (res == strlen(kDemoStr))
    {
        printf("OH YESS\n");
    }
    else
    {
        printf("WHAT\n");
    }

    return 0;
}

#pragma mark -- function implementation --

void printString(const char* str)
{
    const char* kTest = str;
    while (*kTest != '\0')
    {
        printf("%c", *kTest);

        kTest++;
    }
    printf("\n");
}

int myLenOfStr(const char* str)
{
    int length = 0;

    // All the strings end with '\0'
    // *str mean the current character
    while (*str++ != '\0')
    {
        length += 1;
    }

    return length;
}