#include <stdio.h>
#include <string.h>

#pragma mark -- function declaration --
int myLenOfStr(const char* str);


int main()
{
    const char* kDemoStr = "I am a demo string";    // a string
    char demoCharArray[] = "I am a demo character array";    // a character array
    demoCharArray[0] = 'Y';

    int arr[11] = {0};
    arr[0] = 1;

    const char* kTest = kDemoStr;
    while (*kTest != '\0')
    {
        printf("%c", *kTest);

        kTest++;
    }
    printf("\n");

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