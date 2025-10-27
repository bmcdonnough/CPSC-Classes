/* Fall 2022 Lab 6
	Benjamin McDonnough
	October 4, 2022
	CPSC 1011 - 001
	Lab 6

   * intro to PPM with creating a flag of Ireland
			green|white|orange
	* reinforces loops and arrays

	PPM images have 2 parts:
		header information
		pixel information

	An image is height (rows) X width (columns).
	So, a 300 X 600 image is 300 rows high and 600 columns wide.

	All of the image contents (header and pixel info) will be written
	to stdout so when we run the program with redirection, those items
	being sent to stdout will be redirected to a file

	For example, to run this program, you will type:
		./a.out > flag.ppm
	and everything that was sent to stdout will be written to the file
	called  flag.ppm

	All the other statements that you want to go to the screen and not 
	the image will be written to stderr.

*/

#include <stdio.h>


struct flagSize{
	char type[4];
	int width;
	int height;
	int maxColor;
};

struct pixels{
	unsigned int r;
	unsigned int g;
	unsigned int b;
};

int getWidth(){
	int w = 0;
	
	fprintf(stderr, "\n\nFlag of Ireland");
	fprintf(stderr, "\n\tWhat width do you want the flag to be? ");
	fscanf(stdin, " %d", &w);

	return w;
}

void writeHeader(struct flagSize header){
	fprintf(stdout, "P3\n");
	fprintf(stdout, "%d %d %d\n", header.width, header.height, header.maxColor);

}

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

void writePixels(struct pixels *pixArr, int flagWidth, int flagHeight){
	for (int k=0; k<(flagWidth * flagHeight); k++) {
		fprintf(stdout, "%d %d %d\n", pixArr[k].r, pixArr[k].g, pixArr[k].b);
	}

}


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

