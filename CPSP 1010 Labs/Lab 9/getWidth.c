/* Fall 2022 Lab 9
	Benjamin McDonnough
	October 25, 2022
	CPSC 1011 - 001
	Lab 9

	Gets the width of the flag through an input
	or input file.
*/
#include "defs.h"

int getWidth(){
	int w = 0;
	
	fprintf(stderr, "\n\nFlag of Ireland");
	fprintf(stderr, "\n\tWhat width do you want the flag to be? ");
	fscanf(stdin, " %d", &w);

	return w;
}

