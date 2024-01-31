/*
************************
*Benjamin McDonnough
*CPSC 2310 006, F23
*mcdonn7@clemson.edu
************************
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef PPM_H
#define PPM_H

typedef struct Pixel
{
    unsigned int r, g, b;
}pixel_t;

typedef struct Header
{
    char type[3];
    unsigned int width;
    unsigned int height;
    unsigned int maxVal;
    pixel_t backColor;
}header_t;

/* Parameters: FILE* - out: output file that is being read to
*              header_t - hdr: the struct with the header information
*                         of the input image
* Return:      void
* This function writes the header information to the output file
*/
void writeHeader(FILE* out, header_t hdr);

/* Parameters: FILE* - out: output file that is being read to
*              pixel_t - color: the struct with the pixel information
*                         of the input image
* Return:      void
* This function writes the pixel information to the output file
*/
void writePixel(FILE* out,  pixel_t color);

#endif