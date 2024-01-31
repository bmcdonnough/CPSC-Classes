/* Fall 2022 Lab 11
	Benjamin McDonnough
	November 15, 2022
	CPSC 1011 - 001
	Lab 11
	
	This is the function that prints out the header information.

*/
#include "defs.h"

void writeHeader(struct imageSize theHeader, FILE *outFile){
	fprintf(outFile, "%s\n%d %d %d\n", theHeader.type, theHeader.width, theHeader.height, theHeader.maxColor);

}
	

