/* ************************
* Benjamin McDonnough
*CPSC 2310 Fall 23 *
*UserName: mcdonn7
*Instructor: Dr. Yvon Feaster *
************************ */

#include "functions.h"
node_t* createList(FILE* input, node_t** head)
{
    *head = NULL;
    //Go through the entire file
    while(feof(input) != 1){
        //Read in the info into a temp node
        node_t *temp = readNodeInfo(input);
        //Add that temp node to the list
        add(&temp, head);
    }

    return *head;
}


node_t* readNodeInfo(FILE* input)
{
    //Allocate the memory for the new node
    node_t* node = (node_t*)malloc(sizeof(node_t));

    //Read in the info for the new node
    fscanf(input, "%[^,], %[^,], %[^,], %d, %d, %[^,], %[^,], %[^\n]\n", 
           node->student.lastName, node->student.firstName,
           node->bday.month, &node->bday.day, &node->bday.year,
           node->student.degree, node->student.classStanding, 
           node->student.favoriteBookType);
    return node;
}

void printList(FILE* out, node_t *head)
{
    node_t *temp = head;
    //If the temp node (which is equal to head), then print the error and exit
    if(temp == NULL){
        fprintf(stderr, "The list is empty");
        exit(-1);
    }
    //If not, print the info in each node to the output file
    else{
        printBorder(out);
        fprintf(out, "\n");
        fprintf(out, "LIST INFO: \n");
        //Loop through the linked list
        while(temp != NULL){
            fprintf(out, "Name: %s %s\n", temp->student.firstName, 
                    temp->student.lastName);
            fprintf(out, "Date of Birth: %s %d, %d\n", temp->bday.month, 
                    temp->bday.day, temp->bday.year);
            fprintf(out, "Degree: %s\n", temp->student.degree);
            fprintf(out, "Class Standing: %s\n", temp->student.classStanding);
            fprintf(out, "Preferred Reading: %s\n", 
                    temp->student.favoriteBookType);
            fprintf(out, "\n");
            
            //Set the temp node equal to the next node
            temp = temp->next;
        }
        printBorder(out);
    }
}

void add(node_t **node, node_t **head)
{
    node_t *temp = (*head);

    //If there is stuff in the list, go to the last node and
    //and a new node behind it
    if(temp != NULL){
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = *node;
        (*node)->next = NULL;
    }
    //If there is not a head, then make the node being added
    //the head
    else{
        *head = *node;
        (*head)->next = NULL;
    }
    
}

/*This function prints all node information. */


void printBorder(FILE* out)
{
   for(int i = 0; i < 80; ++i){
    fprintf(out, "*");
   }
   fprintf(out,"\n");
}

void deleteList(node_t** h)
{
    node_t *temp = (*h);
    node_t *prev;

    //Loop through each node in the list and remove it
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
        free(prev);
    }

    //Remove the last node
    free(temp);
}


