/*
************************
*Benjamin McDonnough
*CPSC 2310 006, F23
*mcdonn7@clemson.edu
************************
*/
#include "ppm.h"
void writeHeader(FILE* out, header_t hdr)
{
    fprintf(out, "%c%c\n%d %d\n%d\n", hdr.type[0], hdr.type[1],
            hdr.width, hdr.height, hdr.maxVal);
}

void writePixel(FILE* out, pixel_t color)
{ 
    fprintf(out, "%c%c%c", color.r, color.g, color.b);
}
