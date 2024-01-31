/*Benjamin McDonnough
  September 13, 2022
  CSPS 1011-001
  Lab 2
  Program loops through checkinf for an input, either a(A) or o(O) which 
  is apples or oranges respectively. The program will then 
  print out the result. All other inputs will return an error.
  An input of q will quit the program
  */

#include<stdio.h>

int main(void){

	char userInput;

	printf("\nEnter an a for apples or o for orange, or q to quit:");
	scanf(" %c", &userInput);
	
	while(userInput != 'q'){	
		if (userInput == 'a' || userInput == 'A') {
			printf("You chose apples!");
		   printf("\nEnter an a for apples or o for orange, or q to quit:");
			scanf(" %c", &userInput);
		}
		else if (userInput == 'o' || userInput == 'O') {
			printf("You chose oranges!");
			printf("\nEnter an a for apples or o for orange, or q to quit:");
			scanf(" %c", &userInput);
		}
		else{
			printf("You entered an invalid letter.");
		   printf("\nEnter an a for apples or o for orange, or q to quit:");
			scanf(" %c", &userInput);
		}
	}

	if (userInput == 'q' || userInput == 'Q') {
		printf("Good bye!\n\n");
	}
	return 0;

}
