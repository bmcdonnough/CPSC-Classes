/**************************/
/*Benjamin McDonnough *
*CPSC2310 Fall 2023 *
*UserName: mcdonn7 *
*Instructor: Dr. Yvon Feaster */
/*************************/

#include<stdio.h>
#include<stdlib.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);

#endif