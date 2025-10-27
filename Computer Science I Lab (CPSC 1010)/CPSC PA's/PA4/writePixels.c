/* Fall 2022 Lab 11
	Benjamin McDonnough
	November 15, 2022
	CPSC 1011 - 001
	Lab 11

	This function writes out the array to actualy create a visible 
	flag.
*/
#include "defs.h"

void writePixels(struct pixels pixArr[], int flagWidth, int flagHeight, FILE *outFile){
	for (int k=0; k<((flagWidth) * (flagHeight)); k++) {
		fprintf(outFile, "%d %d %d\n", pixArr[k].r, pixArr[k].g, pixArr[k].b);
	}
}
void halfSizeWritePixels(struct pixels pixArr[], int flagWidth, int flagHeight, FILE *outFile){
	for (int k=0; k<(((flagWidth) * (flagHeight))); k+=2) {
		if ((k % flagWidth) == 0 && k != 0){
			k += flagWidth;
		}
		if (k != (flagWidth * flagHeight)){
			fprintf(outFile, "%d %d %d\n", (pixArr[k].r + pixArr[k+1].r + pixArr[k+flagWidth].r + pixArr[k+flagWidth+1].r)/4, 
													(pixArr[k].g + pixArr[k+1].g + pixArr[k+flagWidth].g + pixArr[k+flagWidth+1].g)/4,
													(pixArr[k].b + pixArr[k+1].b + pixArr[k+flagWidth].b + pixArr[k+flagWidth+1].b)/4);
		}
	}
}
