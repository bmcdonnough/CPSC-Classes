/* ************************
* Benjamin McDonnough
*CPSC 2310 Fall 23 *
*UserName: mcdonn7
*Instructor: Dr. Yvon Feaster *
************************ */

/*Add structs and other needed code to this file*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Birthday{
    char month[20];
    int day;
    int year;
}birthday_t;

typedef struct Student{
    char firstName[20];
    char lastName[20];
    char degree[7];
    char classStanding[12];
    char favoriteBookType[30];
}student_t;

typedef struct Node{
    birthday_t bday;
    student_t student;
    struct Node *next;
}node_t;

/* Parameters: node - node_t double pointer which is the node to
*                     be added to the list
*              head - node_t double pointer which is the first node
*                     in the list
* Return: void
* This function adds the new node to the end of the linked list
*/
void add(node_t **node, node_t **head);

/* Parameters: input - file pointer to the input file
* Return: node_t* - a pointer to the node with all of the input from the file
* This function reads in the info for a single node and returns that node
*/
node_t* readNodeInfo(FILE* input);

/* Parameters: input - file pointer to the input file
               node_t** - double pointer to the head node in the list
* Return: node_t* - a pointer to the head node in the list
* This function goes through the entire input file, reads in the info by 
* calling the readNodeInfo() function, and then calls the add() function on each
* node it creates
*/
node_t* createList(FILE*, node_t**);

/* Parameters: input - file pointer to the output file
*              node_t* - node pointer to the head node in the list   
* Return: void
* This function prints the info from each node in the list to the
* output file
*/
void printList(FILE*, node_t*);

/* Parameters: input - file pointer to the output file
* Return: void
* This function prints a string of 80 '*' characters to the output file
*/
void printBorder(FILE*);

/* Parameters: node_t** - double pointer that points to the head node
*                         in the list
* Return: void
* This function removes each node from the linked list
*/
void deleteList(node_t** );

#endif
