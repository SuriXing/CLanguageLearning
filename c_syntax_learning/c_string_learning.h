#ifndef __C_STRING_LEARNING__H
#define __C_STRING_LEARNING__H

#include <stdlib.h>

#pragma mark -- function declaration --

void printStr(const char *str);
int myLenOfStr(const char *str);
int myStrCmp(const char* str1, const char* str2);
int myStrnCmp(const char* str1, const char* str2, size_t n);
char* myStrcat(char* dest, const char* src);
char* myStrcpy(char* dest, const char* src);
void testMyStrCatAndCpy();
char* myStrncat(char* dest, const char* src, size_t n);
char* myStrncpy(char* dest, const char* src, size_t n);
void testMyStrncatAndncpy();
char* myStrstr(const char* str1, const char* str2);
void testMyStrstr();
size_t myStrspn(const char *str1, const char *str2);
char* myStrChar(const char* str, char c);
size_t myStrcspn_fast(const char *str1, const char *str2);

#pragma mark -- test function --
void cStringLearningTest();

#endif // __C_STRING_LEARNING__H