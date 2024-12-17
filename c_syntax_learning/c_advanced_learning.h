#ifndef __C_ADVANCED_LEARNING_H__
#define __C_ADVANCED_LEARNING_H__

#define STRING_LENGTH 256
#define RETRY_TIMES 5

typedef struct _Account 
{
    char account_name[STRING_LENGTH];
    char password[STRING_LENGTH];
} Account;

#pragma mark -- function declaration --
int login();

#endif // __C_ADVANCED_LEARNING_H__