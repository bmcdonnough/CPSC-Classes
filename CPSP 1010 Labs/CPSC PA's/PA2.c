#include<stdio.h>
#include<string.h>

struct pizza{
	char pizzaName[31];
	char ingredients[71];
};

void printPizzas(struct pizza allPizzas[], int numPizzas){
	printf("\n\nPizza\t\tIngredients\n");
	printf("----------------------------------------------------\n\n"); 
	for (int i = 0; i < numPizzas; i++) { 
   	 printf("%s\t%s\n", allPizzas[i].pizzaName, 
                       	  allPizzas[i].ingredients); 
	} 
	printf("\n\n");
}

int main(){
	struct pizza pizzaMenu[3];

	strcpy(pizzaMenu[0].pizzaName, "Barbecue");
	strcpy(pizzaMenu[0].ingredients, "Beef, chicken, bacon, barbecue sauce");

	strcpy(pizzaMenu[1].pizzaName, "Carbonara");
	strcpy(pizzaMenu[1].ingredients, "Mushrooms, onion, creamy sauce");

	strcpy(pizzaMenu[2].pizzaName, "Ham & Cheese");
	strcpy(pizzaMenu[2].ingredients, "Ham, cheese, bacon");

	printPizzas(pizzaMenu, 3);

	return 0;
}
