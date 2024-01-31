/* Fall 2022 Lab 11
	Benjamin McDonnough
	November 15, 2022
	CPSC 1011 - 001
	Lab 11

	Gets the width of the flag through an input
	or input file.
*/
#include "defs.h"

struct imageSize getHeader(FILE *inFile){
	struct imageSize image;
	fscanf(inFile, "%s\n", image.type);
	fscanf(inFile, "%d", &image.width);
	fscanf(inFile, "%d", &image.height);
	fscanf(inFile, "%d", &image.maxColor);
	
	return image;
}

