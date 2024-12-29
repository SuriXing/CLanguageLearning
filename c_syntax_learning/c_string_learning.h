#ifndef __C_STRING_LEARNING_H__
#define __C_STRING_LEARNING_H__

#pragma mark -- function declaration --

void printStr(const char *str);

int myStrlen(const char *str);

int myStrcmp(const char* str1, const char* str2);
int myStrncmp(const char* str1, const char* str2, size_t n);

char* myStrcat(char* dest, const char* src);
char* myStrcpy(char* dest, const char* src);

char* myStrncat(char* dest, const char* src, size_t n);
char* myStrncpy(char* dest, const char* src, size_t n);

char* myStrstr(const char* str1, const char* str2);

char* myStrchr(const char* str, char c);
char* myStrrchr(const char* str, char a);

size_t myStrspn(const char *str1, const char *str2);
size_t myStrcspn_fast(const char *str1, const char *str2);

#endif // __C_STRING_LEARNING_H__