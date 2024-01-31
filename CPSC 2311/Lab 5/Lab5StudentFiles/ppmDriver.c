#include "ppmUtil.h"
int main(int argc, char** argv)
{
    FILE* inFile;
    FILE* outFile;

    inFile = fopen(argv[1], "r+");
    outFile=fopen(argv[2],"w+");

    assert(inFile != NULL);
    assert(outFile != NULL);

    header_t header;
    pixel_t* pixel;

    pixel = read(inFile, &header);
    write(outFile, header, pixel);

    fclose(inFile);
    fclose(outFile);
}

