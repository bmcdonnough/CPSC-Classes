/* Fall 2022 Lab 6
	Benjamin McDonnough
	October 4, 2022
	CPSC 1011 - 001
	Lab 6

	This is the function that fills the array with pixels to make
	the flag.
*/
#include "defs.h"

void fillFlagArray(struct pixels *pixArr, int flagWidth, int flagHeight){
	int k = 0;
	for (int i=0;i<flagHeight;i++) {
	   for (int j=0; j<(flagWidth)/3; j++){
			pixArr[k].r = 0;
			pixArr[k].g = 128;
			pixArr[k].b = 0;
			k++;
		}
		for (int j=(flagWidth)/3; j<(flagWidth * 2)/3; j++){
			pixArr[k].r = 255;
			pixArr[k].g = 255;
			pixArr[k].b = 255;
			k++; 
		}
		for (int j=(flagWidth * 2)/3; j<flagWidth; j++){
			pixArr[k].r = 255;
			pixArr[k].g = 165;
			pixArr[k].b = 0;
			k++;
		}
	}

}

