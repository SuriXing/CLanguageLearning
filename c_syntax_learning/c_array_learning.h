#ifndef __C_ARRAY_LEARNING_H__
#define __C_ARRAY_LEARNING_H__

#pragma mark -- function declaration --

#pragma mark -- macro declaration --
#define LENGTH_OF_1D_ARR 20
#define LENGTH_OF_2D_ROW 20
#define LENGTH_OF_2D_COL 20

#pragma mark -- function declaration --
int findSmallestNumberIn1DArray(int array[], int lengthOf1DArr);
int findSmallestIndexIn1DArray(int array[], int lengthOf1DArr);

int findGreatestNumberIn1DArray(int array[], int lengthOf1DArr);
int findGreatestIndexIn1DArray(int array[], int lengthOf1DArr);

int findSmallestNumberIn2DArray(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);
int findGreatestNumberIn2DArray(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);

int print1DArray(int array[], int length);
int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int getSumOf1DArray(int array[], int length);
int getSumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int getAverageOf1DArray(int array[], int length);
int getAverageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int generateRandom1DArray(int array[], int length);
int generateRandom2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int swap1DArray(int array[], int length);

#pragma mark -- Sorting function --
int doBubbleSortInInvertedOrder(int array[], int length);
int doBubbleSortInReversedOrder(int array[], int length);

int doBubbleSortInInvertedOrder2(int array[], int length);
int doBubbleSortInReversedOrder2(int array[], int length);

#pragma mark -- test function --
void cArrayLearningTest();
void doArraySortTesting();

#endif // __C_ARRAY_LEARNING_H__