#ifndef __C_ARRAY_LEARNING_H__
#define __C_ARRAY_LEARNING_H__

#pragma mark -- function declaration --

#pragma mark -- macro declaration --
#define LEN_OF_ONE_D_ARR 20
#define LENGTH_OF_2D_ROW 20
#define LENGTH_OF_2D_COL 20

#pragma mark -- function declaration --
void smallest_number_in_1D_array(int array[], int lengthOf1DArr);
void greatest_number_in_1D_array(int array[], int lengthOf1DArr);
void smallest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);
void greatest_number_in_2D_array(int array[][LENGTH_OF_2D_COL], int len2DArrR, int len2DArrC);

int print1DArray(int array[], int length);
int print2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int sumOf1DArray(int array[], int length);
int sumOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int averageOf1DArray(int array[], int length);
int averageOf2DArray(int array[][LENGTH_OF_2D_COL], int lengthOfR, int lengthOfC);

int swap1DArray(int array[], int length);


#pragma mark -- test function --
void c_array_learning_test();

#endif // __C_ARRAY_LEARNING_H__