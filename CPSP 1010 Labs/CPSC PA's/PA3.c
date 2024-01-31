/*
	Benjamin McDonnough mcdonn7
	10/24/2022
	CPSC 1010 10
	PA3
	Program gets pizzas and ingredients from an input file and then
	prints them out.
*/



#include<stdio.h>
#include<string.h>

struct pizza{
	char pizzaName[31];
	char ingredients[71];
};

//Prints the pizzas and ingredients
void printPizzas(struct pizza allPizzas[], int numPizzas){
	printf("\n\nPizza\t\tIngredients\n");
	printf("----------------------------------------------------\n\n"); 
	for (int i = 0; i < numPizzas; i++) { 
		printf("%s\t%s\n", allPizzas[i].pizzaName, 
								 allPizzas[i].ingredients); 
	} 
	printf("\n\n");
}

//Gets the info of the pizzas from the input file
void getPizzas(struct pizza allPizzas[], int numPizzas){
	int pizzaLen;
	int toppersLen;

	for (int i = 0; i < numPizzas; i++) {

		//Gets the type of pizza
		fgets(allPizzas[i].pizzaName, 30, stdin);
		pizzaLen = strlen(allPizzas[i].pizzaName);
		if(allPizzas[i].pizzaName[pizzaLen - 1] == '\n'){
			allPizzas[i].pizzaName[pizzaLen - 1] = '\0';
		}

		//Gets the ingredients for the pizza
		fgets(allPizzas[i].ingredients, 70, stdin);
		toppersLen = strlen(allPizzas[i].ingredients);
		if(allPizzas[i].ingredients[toppersLen - 1] == '\n'){
			allPizzas[i].ingredients[toppersLen - 1] = '\0';
		}
	}
}




int main(){
	int amountPizzas;

	fscanf(stdin, "%d", &amountPizzas);
	fscanf(stdin, "\n");

	struct pizza pizzaMenu[amountPizzas];

	getPizzas(pizzaMenu, amountPizzas);

	printPizzas(pizzaMenu, amountPizzas);

	return 0;
}
