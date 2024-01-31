/*
************************
*Benjamin McDonnough
*CPSC 2310 006, F23
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
    int numShapes = 0;

    readInfo(inFile, &head, &numShapes);

    shape_t shapes[numShapes];

    readShapes(inFile, shapes, numShapes);

    pixel_t backColor;
    readBack(inFile, &backColor);

    writeHeader(outFile, head);
    makeShapes(outFile, &head, shapes, &backColor, 
               head.width, head.height, numShapes);
    
    fclose(inFile);
    fclose(outFile);
}
