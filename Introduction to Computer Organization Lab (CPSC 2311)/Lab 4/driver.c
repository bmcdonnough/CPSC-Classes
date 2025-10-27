/**************************/
/*Benjamin Mcdonnough *
*CPSC2310 Fall 2023 *
*UserName: mcdonn7 *
*Instructor: Dr. Yvon Feaster */
/*************************/
#include "functions.h"

int main(int argc, char** argv)
{
    printf("cheking command line arguments\n");

    if (argc < 2)
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did not open\n"); 
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);

    return 0;
}
