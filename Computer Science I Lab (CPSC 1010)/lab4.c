#include<stdio.h>
#include<math.h>

/*
Benjamin McDonnough
September 22, 2022
CSPC 1011-001
The code takes several user inputs and shows
decimal, octal, and hex values based off of
the ASCII table.
*/

int main(void){
	char capLetter;
	int toLow;

	char lowLetter;
	int toCap;

	int tableInt;
	int sqInt;

	fprintf(stderr,"Enter a capital letter: ");
	fscanf(stdin," %c", &capLetter);
	toLow = capLetter + 32;

	fprintf(stderr,"Enter a lowercase letter: ");
	fscanf(stdin," %c", &lowLetter);
	toCap = lowLetter - 32;

	fprintf(stderr,"Enter an integer (33 - 126): ");
	fscanf(stdin," %d", &tableInt);

	fprintf(stderr,"Enter an integer: ");
	fscanf(stdin," %d", &sqInt);
	float cubeInt = pow(sqInt, 3);

	fprintf(stdout,"The lowercase of %c is: %c\n", capLetter, toLow);
	fprintf(stdout,"The ASCII values for %c are:\n", toLow);
	fprintf(stdout,"%-16s%-16s%-s\n", "DECIMAL", "OCTAL", "HEX");
	fprintf(stdout,"%-16d%-#16o%-#x\n", toLow, toLow, toLow);
  
	fprintf(stdout,"The uppercase of %c is: %c\n", lowLetter, toCap);
	fprintf(stdout,"The ASCII values for %c are:\n", toCap);
	fprintf(stdout,"%-16s%-16s%-s\n", "DECIMAL", "OCTAL", "HEX");
	fprintf(stdout,"%-16d%-#16o%-#x\n", toCap, toCap, toCap);

	fprintf(stdout,"The ASCII character of %d is: %c\n", tableInt, tableInt);

	fprintf(stdout,"%d cubed is %.1f\n", sqInt, cubeInt);

	return 0;

}

  

  
  
  
  
  
  
