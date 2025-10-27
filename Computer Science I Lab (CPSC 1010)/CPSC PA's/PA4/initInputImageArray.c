/* Fall 2022 Lab 11
	Benjamin McDonnough
	November 15, 2022
	CPSC 1011 - 001
	Lab 11

	This is the function that fills the array with pixels to make
	the flag.
*/
#include "defs.h"

void fillImageArray(struct pixels pixArr[], int flagWidth, int flagHeight, FILE *inFile){
	for(int i = 0; i < flagWidth*flagHeight; i++){
		fscanf(inFile, "%u", &pixArr[i].r);
		fscanf(inFile, "%u", &pixArr[i].g);
		fscanf(inFile, "%u", &pixArr[i].b);
		
	}
}

