/* Fall 2022 PA4                                                                             
	Benjamin McDonnough
	December 7, 2022
	CPSC 1010 - 001
	PA4

	Is the main function in the code. Is used to call
	all of the other functions and to define variables.
 */

#include "defs.h"

int showMenu(bool menu1, bool menu2, bool menu3){
	// Bools to make sure menu option hasn't been choosen yet
	menu1 = false;
	menu2 = false;
	menu3 = false;

	int menuNum = 0;

	// Shows the menu options
	fprintf(stdout, "Image Manipulation Program\n");
	fprintf(stdout, "1. reduce size of image #1\n");
	fprintf(stdout, "2. superimpose image #2 onto image #1\n");
	fprintf(stdout, "3. reduce size of superimposed image\n");
	fprintf(stdout, "4. quit the program\n");

	fscanf(stdin, "%d", &menuNum);	 

	// Checks if option has been picked already
	if(menu1 == true && menuNum == 1){
		fprintf(stdout, "Menu 1 option already chosen.\n\n");
		showMenu(menu1, menu2, menu3);
	}
	else if(menu2 == true && menuNum == 2){
		fprintf(stdout, "Menu 2 option already chosen.\n\n");
		showMenu(menu1, menu2, menu3);
	}
	else if(menu3 == true && menuNum == 3){
		fprintf(stdout, "Menu 3 option already chosen.\n\n");
		showMenu(menu1, menu2, menu3);
	}

	return menuNum;
} 

int main (int argc, char *argv[]){
	struct pixels *picture = NULL;
	struct imageSize header;
	struct imageSize halfSizeHeader;
	struct imageSize greenHeader;

	bool firstChoice = false;
	bool secondChoice = false;
	bool thirdChoice = false;

	FILE *picIn;
	FILE *pic2In;

	picIn = fopen(argv[1], "r");
	pic2In = fopen(argv[2], "r");

	// Check to make sure that the files allocate
	if(picIn == NULL){
		fprintf(stderr, "error: could not allocate file");
		exit(1);
	}

	if(pic2In == NULL){
		fprintf(stderr, "error: could not allocate file");
		exit(2);
	}

	// Get the header information
	header = getHeader(picIn);
	greenHeader = getHeader(pic2In);

	// Set the header information for the smaller image
	halfSizeHeader = header;      
	halfSizeHeader.width = header.width/2;
	halfSizeHeader.height = header.height/2;

	// Set the variables in order to use calloc
	struct pixels *greenPic = NULL;

	// Make space for original picture
	picture = (struct pixels *)calloc(header.width * header.height, sizeof(struct pixels));
	greenPic = (struct pixels *)calloc(greenHeader.width * greenHeader.height, sizeof(struct pixels));

	// Fill in the first image
	fillImageArray(picture, header.width, header.height, picIn);
	fillImageArray(greenPic, greenHeader.width, greenHeader.height, pic2In);

	//showMenu(firstChoice, secondChoice, thirdChoice);
	int menuOption = showMenu(firstChoice, secondChoice, thirdChoice);
	while(menuOption != 4){
		switch (menuOption)
		{
			case 1:
				if(firstChoice){
					fprintf(stdout, "Menu 1 option already chosen.\n\n");
					//menuOption = showMenu(firstChoice, secondChoice, thirdChoice);
				}
				else if(!firstChoice){
					// Bool for showMenu
					firstChoice = true;

					//Set variable for calloc
					struct pixels *smallerPicture = NULL;

					// Make space for smaller picture
					smallerPicture = (struct pixels *)calloc(halfSizeHeader.width * halfSizeHeader.height, sizeof(struct pixels));
					
					reduceSize(picture, smallerPicture, header.width, header.height);

					// File pointer Output
					FILE *smallPicOut;
					smallPicOut = fopen("smallerImage1.pnm", "w");

					if(smallPicOut == NULL){
						fprintf(stderr, "error: could not allocate file");
						exit(3);
					}

					// Print out the new image
					writeHeader(halfSizeHeader, smallPicOut);
					writePixels(smallerPicture, halfSizeHeader.width, halfSizeHeader.height, smallPicOut);
				}
				break;
			case 2: 
				if(secondChoice){
					fprintf(stdout, "Menu 2 option already chosen.\n\n");
					//menuOption = showMenu(firstChoice, secondChoice, thirdChoice);
				}
				else if(!secondChoice){
					// Bool for showMenu
					secondChoice = true;

					//Set varibale for calloc
					struct pixels *superImpPic = NULL;

					// Make space for the green screen picture
					superImpPic = (struct pixels *)calloc(greenHeader.width * greenHeader.height, sizeof(struct pixels));

					greenScreen(picture, greenPic, superImpPic, greenHeader.width, greenHeader.height);
					
					// File pointer Output
					FILE *greenPicOut;
					greenPicOut = fopen("greenScreen1.pnm", "w");

					if(greenPicOut == NULL){
						fprintf(stderr, "error: could not allocate file");
						exit(3);
					}

					// Superimpose the greenscreen image and print the new image
					writeHeader(greenHeader, greenPicOut);
					writePixels(superImpPic, greenHeader.width, greenHeader.height, greenPicOut);
				}
				break;
			case 3:
				if(thirdChoice){
					fprintf(stdout, "Menu 3 option already chosen.\n\n");
					//menuOption = showMenu(firstChoice, secondChoice, thirdChoice);
				}
				else if(!thirdChoice){
					// Bool for showMenu
					thirdChoice = true;

					//Set variables for calloc
					struct pixels *manipGreen = NULL;
					struct pixels *smallGreen = NULL;

					//Make space for the pictures
					manipGreen = (struct pixels *)calloc(greenHeader.width * greenHeader.height, sizeof(struct pixels));
					smallGreen = (struct pixels *)calloc(halfSizeHeader.width * halfSizeHeader.height, sizeof(struct pixels));

					//Superimpose image then shrink it
					greenScreen(picture, greenPic, manipGreen, greenHeader.width, greenHeader.height);
					reduceSize(manipGreen, smallGreen, halfSizeHeader.width, halfSizeHeader.height);
					
					//File pointer output
					FILE *smallGreenOut;
					smallGreenOut = fopen("smallerImage2.pnm", "w");

					if(smallGreenOut == NULL){
						fprintf(stderr, "error: could not allocate file");
						exit(3);
					}

					//Print the new image
					writeHeader(halfSizeHeader, smallGreenOut);
					writePixels(smallGreen, halfSizeHeader.width, halfSizeHeader.height, smallGreenOut);

				}
				break;
			case 4:
				//Exit if quit is choosen
				exit(4);
				break;

			default:
				break;
		}
		menuOption = showMenu(firstChoice, secondChoice, thirdChoice);
	}
	return 0;
}
