#include<stdio.h>
#include<stdbool.h>

/*
Benjamin McDonnough
mcdonn7
September 28, 2022
CPSC 1010-001
FruitJars
Program assorts different fruits into mislabeled jars
and gets the user to go through a guess which fruit 
is in which jar given a different label combination
each time.
*/

int main(void){
	char arr1[4] = {'a', 'A', 'o', 'O'};
	char arr2[2] = {'a', 'A'};
	char arr3[2] = {'o', 'O'};

	int userJar;
	char userGuess;

	int i = 0;
	int j = 0;

	bool jar1 = false, jar2 = false, jar3 = false;

	fprintf(stdout, "There are 3 jars containing fruit. ");
	fprintf(stdout, "Each jar is labeled incorrectly.\n");
	fprintf(stdout, "See if you can determine the correct labels!\n");
	fprintf(stdout, "1. oranges\n");
	fprintf(stdout, "2. both\n");
	fprintf(stdout, "3. apples\n");

	while(i<2){
		jar1 = false;
		jar2 = false;
		jar3 = false;

		j = 0;
	
		fprintf(stdout, "Which one would you like to look in first? ");
		fprintf(stdout, "(choose 1, 2, or 3): ");
		fscanf(stdin, " %d", &userJar);

		while(j<3){
			switch(userJar){
				case 1:	
					if(jar1){
						fprintf(stdout, "You already correctly guessed this jar!\n");
						fprintf(stdout, "Which one would you like to look in next? ");
						fprintf(stdout, "(1, 2, or 3): ");
						fscanf(stdin, " %d", &userJar);
					}
					else{
						while(!jar1){
							fprintf(stdout, "The first fruit in jar %d is: ", userJar);
							fprintf(stdout, "%c\n", arr1[0]);
							fprintf(stdout, "What do you think this jar really contains? ");
							fprintf(stdout, "(a, o, or b): ");
							fscanf(stdin, " %c", &userGuess);
							if(userGuess=='b' || userGuess=='B'){
								fprintf(stdout, "That's correct! Good job!\n");
								j++;
								jar1 = true;
								if(j<3){
									fprintf(stdout, "Which one would you like to look in next? ");
									fprintf(stdout, "(1, 2, or 3): ");
									fscanf(stdin, " %d", &userJar);
								}
								else if(j>=3){
									i++;
									if(i < 2){
										fprintf(stdout, "Let's try again!\n");
										fprintf(stdout, "1. apples\n");
										fprintf(stdout, "2. oranges\n");
										fprintf(stdout, "3. both\n");
									}
								}
							}	
							else{
								fprintf(stdout, "Sorry, that is incorrect.\n");
								fprintf(stdout, "Which one would you like to look in next? ");
								fprintf(stdout, "(1, 2, or 3): ");
								fscanf(stdin, " %d", &userJar);
							}
						}
					}
					break;
				case 2:	
					if(jar2){
						fprintf(stdout, "You already correctly guessed this jar!\n");
						fprintf(stdout, "Which one would you like to look in next? ");
						fprintf(stdout, "(1, 2, or 3): ");
						fscanf(stdin, " %d", &userJar);
					}
					else{
						while(!jar2){
							fprintf(stdout, "The first fruit in jar %d is: ", userJar);
							fprintf(stdout, "%c\n", arr2[0]);
							fprintf(stdout, "What do you think this jar really contains? ");
							fprintf(stdout, "(a, o, or b): ");
							fscanf(stdin, " %c", &userGuess);
							if(userGuess=='a' || userGuess=='A'){
								fprintf(stdout, "That's correct! Good job!\n");
								j++;
								jar2 = true;
								if(j<3){
									fprintf(stdout, "Which one would you like to look in next? ");
									fprintf(stdout, "(1, 2, or 3): ");
									fscanf(stdin, " %d", &userJar);
								}
								else if(j>=3){
									i++;
									if(i < 2){
										fprintf(stdout, "Let's try again!\n");
										fprintf(stdout, "1. apples\n");
										fprintf(stdout, "2. oranges\n");
										fprintf(stdout, "3. both\n");
									}
								}
							}	
							else{
								fprintf(stdout, "Sorry, that is incorrect.\n");
								fprintf(stdout, "Which one would you like to look in next? ");
								fprintf(stdout, "(1, 2, or 3): ");
								fscanf(stdin, " %d", &userJar);
							}
						}
					}
					break;
				case 3:
					if(jar3){
						fprintf(stdout, "You already correctly guessed this jar!\n");
						fprintf(stdout, "Which one would you like to look in next? ");
						fprintf(stdout, "(1, 2, or 3): ");
						fscanf(stdin, " %d", &userJar);
					}
					else{
						while(!jar3){
							fprintf(stdout, "The first fruit in jar %d is: ", userJar);
							fprintf(stdout, "%c\n", arr3[0]);
							fprintf(stdout, "What do you think this jar really contains? ");
							fprintf(stdout, "(a, o, or b): ");
							fscanf(stdin, " %c", &userGuess);
							if(userGuess=='o' || userGuess=='O'){
								fprintf(stdout, "That's correct! Good job!\n");
								j++;
								jar3 = true;
								if(j<3){
									fprintf(stdout, "Which one would you like to look in next? ");
									fprintf(stdout, "(1, 2, or 3): ");
									fscanf(stdin, " %d", &userJar);
								}
								else if(j >= 3){
									i++;
									if(i < 2){
										fprintf(stdout, "Let's try again!\n");
										fprintf(stdout, "1. apples\n");
										fprintf(stdout, "2. oranges\n");
										fprintf(stdout, "3. both\n");
									}
								}
							}	
							else{
								fprintf(stdout, "Sorry, that is incorrect.\n");
								fprintf(stdout, "Which one would you like to look in next? ");
								fprintf(stdout, "(1, 2, or 3): ");
								fscanf(stdin, " %d", &userJar);
							}
						}
					}
					break;
				default:
					break;
			}
		}
	}
	return 0;
}
