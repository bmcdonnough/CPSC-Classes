/* ************************
* Benjamin McDonnough
*CPSC 2310 Fall 23 *
*UserName: mcdonn7
*Instructor: Dr. Yvon Feaster *
************************ */

#include "functions.h"

int main(int argc, char * argv[])
{ 
    FILE *inFile;
    FILE *outFile;

    inFile = fopen(argv[1], "r");
    outFile = fopen(argv[2], "w");
    
    node_t **head;

    head = (node_t**)malloc(sizeof(node_t*));

    createList(inFile, head);
    printList(outFile, *head);
    deleteList(head);

    return 0;
}
