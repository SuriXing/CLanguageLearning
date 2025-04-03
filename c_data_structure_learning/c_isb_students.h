#ifndef __C_ISB_STUDENT_H__
#define __C_ISB_STUDENT_H__

typedef enum _Gender
{
	MALE,
	FEMALE,
} Gender;

typedef struct _IsbStudent
{
	char first_name[32];
	char last_name[32];
	Gender gender;
	unsigned int math_score;
	unsigned int language_usage_score;
	unsigned int reading_score;
} IsbStudent;



#pragma mark -- data structure declaration --

#endif // __C_ISB_STUDENT_H__