/*Benjamin McDonnough
  September 6, 2022
  CSPS 1011-001
  Lab 2
  Program checks for an input, either a(A) or o(O) which 
  is apples or oranges respectively. The program will then 
  print out the result. All other inputs will return an error
  */

#include<stdio.h>

int main(void){

	char userInput;

	printf("\nEnter an a for apples or o for orange:");
	scanf("%c", &userInput);
	
	if (userInput == 'a' || userInput == 'A') {
		printf("You chose apples!\n\n");
	}
	else if (userInput == 'o' || userInput == 'O') {
		printf("You chose oranges!\n\n");
	}
	else {
		printf("You entered an invalid letter.\n\n");
	}

	return 0;

}
