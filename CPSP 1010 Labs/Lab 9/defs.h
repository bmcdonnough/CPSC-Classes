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

