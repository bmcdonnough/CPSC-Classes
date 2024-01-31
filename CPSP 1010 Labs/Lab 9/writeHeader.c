/* Fall 2022 Lab 9
	Benjamin McDonnough
	October 25, 2022
	CPSC 1011 - 001
	Lab 9
	
	This is the function that prints out the header information.

*/
#include "defs.h"

void writeHeader(struct flagSize header){
	fprintf(stdout, "P3\n");
	fprintf(stdout, "%d %d %d\n", header.width, header.height, header.maxColor);

}

