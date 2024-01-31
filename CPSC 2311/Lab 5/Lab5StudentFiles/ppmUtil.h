#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef PPMUTIL_H
#define PPMUTIL_H

typedef struct Pixel
{
    unsigned char r, g, b;
}pixel_t;

typedef struct Header
{
    char type[3];
    unsigned int width;
    unsigned int height;
    unsigned int maxVal;
}header_t;

/* Parameters: FILE* - input file that is being read in from
*              header_t* - used to store the header information 
*              from the input file
* Return:      void
* This function reads in the header information and puts
* the values into the header struct using the header_t*.
*/
void readHeader(FILE*, header_t*);

/* Parameters: FILE* - input file that is being read in from
*              header_t - the struct with all of the header information
*                         of the input image.
* Return:      pixel_t* - pointer to the pixel struct that holds 
*                         the pixel rgb values
* This function reads in the pixel information and puts
* the values into each pixel struct using the pixel_t*.
*/
pixel_t* readPixels(FILE*, header_t);

/* Parameters: FILE* - output file that is being read to
*              header_t - the struct with the header information
*                         of the input image
* Return:      void
* This function writes the header information to the output file
*/
void writeHeader(FILE*, header_t);

/* Parameters: FILE* - output file that is being read to
*              header_t - the struct with the header information
*                         of the input image
* Return:      void
* This function writes the header information to the output file
*/
void writePixels(FILE*, pixel_t*, header_t);

/* Parameters: FILE* - input file that is being read in from
*              header_t* - poimnter to the struct with all of 
*                         the header information of the input image
* Return:      pixel_t* - pointer to the pixel struct that holds 
*                         the pixel rgb values
* This function reads all of the information from the input file
* by calling readHeader() and readPixels()Hu
*/
pixel_t* read(FILE*, header_t*);

/* Parameters: FILE* - output file that is being read to
*              header_t - the struct with the header information
*                         of the input image
*              pixel_t* - point to the pixel struct that holds the
*                         pixel rgb values
* Return:      void
* This function writes all of the information into the output file
* by calling writeHeader() and writePixels()
*/
void write(FILE*, header_t, pixel_t*);

/* Parameters: header_t - header struct that stores the header 
*                         information from the input image
* Return:      pixel_t* - pixel_t struct containing output image data
* This functions allocates the memory required for the output image 
*/
pixel_t* allocatePixMemory(header_t);

/* Parameters: pixel_t* - a pointer to the pixel struct
* Return:      void
* This functions frees the memory previously allocated for the image
*/
void freeMemory(pixel_t*);

/* Parameters: FILE* - input file that is being red in from
* Return:      void
* This function checks for any comments in the header of the 
* input file and ignores them if they exist by reading line by line
* and storing them into a buffer char array
*/
void ckComment(FILE*);

#endif