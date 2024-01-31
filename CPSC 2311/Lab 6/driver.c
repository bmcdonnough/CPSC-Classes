/*
************************
*Benjamin McDonnough
*CPSC 2310 006
*mcdonn7@clemson.edu
************************
*/
#include "shape.h"

int main(int argc, char* argv[])
{
    FILE* inFile;
    FILE* outFile;

    inFile = fopen(argv[1], "r");
    outFile = fopen(argv[2],"w");

    assert(inFile != NULL);
    assert(outFile != NULL);

    header_t head;
    circle_t circle;

    readInfo(inFile, &head, &circle);

    writeHeader(outFile, head);
    makeCircle(outFile, &circle, head.width, head.height);
    
    fclose(inFile);
    fclose(outFile);
}
