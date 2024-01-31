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


int main (void){
	int width, height, i, j, k = 0;  // k is used for the array

	fprintf(stderr, "\n\nFlag of Ireland");
	fprintf(stderr, "\n\tWhat width do you want the flag to be? ");
	// 1. get the user's input for width
	fscanf(stdin, " %d", &width);

	// 2. calculate the height based on the proportion stated on Wikipedia
	height = width/2;

	fprintf(stderr, "\n\nMaking the flag with width %d & height %d ...",
		width, height);
	fprintf(stderr, "\n\n");

	int actualWidth = width * 3;
	int size = actualWidth * height;
	// 3. declare an array of type:  unsigned int
	// * it will need to be big enough to hold all the color values:
	// * each pixel is made up of red, green, and blue values
	//   so each pixel has 3 things in it
	// * therefore (HINT):  the width is actually 3 times bigger
	unsigned int flag[size];	


	// write to stdout the ppm header values 
	// * with redirection, these outputs will be written to the file
	fprintf(stdout, "P3\n");
	fprintf(stdout, "%d %d %d\n", width, height, 255);


	// 4. nested for loops for writing the pixel data:
	// 	a.  outer for loop is for each row
	// 	b.  because the flag of Irelad has 3 equal vertical parts,
	//        there will be 3 equal inner for loops, each one going
	//        1/3 of the way across the row (i.e. 1/3 of the columns)
	// pseudocode:
	for (i=0;i<height;i++) {
	   for (j=0; j<(width)/3; j++){
			flag[k] = 0;
			flag[k+1] = 128;
			flag[k+2] = 0;
			k += 3;
		}
		for (j=(width)/3; j<(width * 2)/3; j++){
			flag[k] = 255;
			flag[k+1] = 255;
			flag[k+2] = 255;
			k += 3; 
		}
		for (j=(width * 2)/3; j<width; j++){
			flag[k] = 255;
			flag[k+1] = 165;
			flag[k+2] = 0;
			k += 3;
		}
	}
		

	// 5. print the contents of the array to stdout, so with redirection,
	//    the pixels will be written to the .ppm file
	//    * with P3, the unsigned int values must be written so that
	//      the values are 3 to a line (see lab write-up)
	// pseudocode:
	for (k=0; k<size; k+=3) {
		fprintf(stdout, "%d %d %d\n", flag[k], flag[k+1], flag[k+2]);
	}

	return 0;
}
