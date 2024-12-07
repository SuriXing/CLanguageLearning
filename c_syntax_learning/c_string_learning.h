#ifndef __C_STRING_LEARNING__H
#define __C_STRING_LEARNING__H

#include <stdlib.h>

#pragma mark -- function declaration --

void printStr(const char *str);
int myLenOfStr(const char *str);
int myStrCmp(const char* str1, const char* str2);
int myStrnCmp(const char* str1, const char* str2, size_t n);
char* myStrcat(char* dest, const char* src);
char *myStrcpy(char* dest, const char* src);
void testMyStrCatAndCpy();

#pragma mark -- test function --
void cStringLearningTest();

#endif // __C_STRING_LEARNING__H