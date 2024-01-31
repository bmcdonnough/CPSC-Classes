/*************************
 *Benjamin McDonnough  
 *CPSC 2311 006
 *mcdonn7@clemson.edu
 *************************/
#include "src/functions.h"

int main(int argc, char* argv[])
{
    
    FILE* inFile;
    FILE* outFile;

    inFile = fopen(argv[1], "r");
    outFile = fopen(argv[2], "w");

    assert(inFile != NULL);
    assert(outFile != NULL);

    numSentences(inFile, outFile);
    numWords(inFile, outFile);

    return 0;
}
