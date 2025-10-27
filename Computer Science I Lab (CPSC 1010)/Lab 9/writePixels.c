/* Fall 2022 Lab 9
	Benjamin McDonnough
	October 25, 2022
	CPSC 1011 - 001
	Lab 9

	This function writes out the array to actualy create a visible 
	flag.
*/
#include "defs.h"

void writePixels(struct pixels *pixArr, int flagWidth, int flagHeight){
	for (int k=0; k<(flagWidth * flagHeight); k++) {
		fprintf(stdout, "%d %d %d\n", pixArr[k].r, pixArr[k].g, pixArr[k].b);
	}

}
