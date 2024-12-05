#ifndef __C_ARRAY_LEARNING_H__
#define __C_ARRAY_LEARNING_H__

#pragma mark -- function declaration --

#pragma mark -- macro declaration --
#define LEN_OF_1D_ARR 20
#define LENGTH_OF_2D_ROW 20
#define LENGTH_OF_2D_COL 20

#pragma mark -- function declaration --
void smallestNumberIn1DArray(int array[], int lengthOf1DArr);
void greatestNumberIn1DArray(int array[], int lengthOf1DArr);
void smallestNumberIn2DArray(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);
void greatestNumberIn2DArray(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);

int print1DArray(int array[], int length);
int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int sumOf1DArray(int array[], int length);
int sumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int averageOf1DArray(int array[], int length);
int averageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int swap1DArray(int array[], int length);


#pragma mark -- test function --
void cArrayLearningTest();

#endif // __C_ARRAY_LEARNING_H__