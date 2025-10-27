/* Fall 2022 Lab 9
	Benjamin McDonnough
	October 25, 2022
	CPSC 1011 - 001
	Lab 9

	Is the main function in the code. Is used to call
	all of the other functions and to define variables.
*/

#include "defs.h"

int getWidth();
void fillFlagArray(struct pixels *pixArr, int flagWidth, int flagHeight);
void writeHeader(struct flagSize header);
void writePixels(struct pixels *pixArr, int flagWidth, int flagHeight);

int main (void){

	struct flagSize flagPar;

	flagPar.maxColor = 255;
	
	flagPar.width = getWidth();
	

	// 2. calculate the height based on the proportion stated on Wikipedia
	flagPar.height = flagPar.width/2;
	struct pixels flag[flagPar.width * flagPar.height];
	
	fprintf(stderr, "\n\nMaking the flag with width %d & height %d ...",
		flagPar.width, flagPar.height);
	fprintf(stderr, "\n\n");

	// 3. declare an array of type:  unsigned int
	// * it will need to be big enough to hold all the color values:
	// * each pixel is made up of red, green, and blue values
	//   so each pixel has 3 things in it
	// * therefore (HINT):  the width is actually 3 times bigger
	

	// write to stdout the ppm header values 
	// * with redirection, these outputs will be written to the file
	writeHeader(flagPar);

	// 4. nested for loops for writing the pixel data:
	// 	a.  outer for loop is for each row
	// 	b.  because the flag of Irelad has 3 equal vertical parts,
	//        there will be 3 equal inner for loops, each one going
	//        1/3 of the way across the row (i.e. 1/3 of the columns)
	// pseudocode:
	fillFlagArray(flag, flagPar.width, flagPar.height);
		

	// 5. print the contents of the array to stdout, so with redirection,
	//    the pixels will be written to the .ppm file
	//    * with P3, the unsigned int values must be written so that
	//      the values are 3 to a line (see lab write-up)
	// pseudocode:
	writePixels(flag, flagPar.width, flagPar.height);

	return 0;
}

