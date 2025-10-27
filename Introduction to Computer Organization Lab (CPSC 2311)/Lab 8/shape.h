/*
************************
*Benjamin McDonnough
*CPSC 2310 006, F23
*mcdonn7@clemson.edu
************************
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "ppm.h"

#ifndef SHAPE_H
#define SHAPE_H

typedef struct Point
{
    int x, y;
}point_t;

typedef struct Cirlce
{
    point_t center;
    unsigned int radius;
    pixel_t cirColor;
}circle_t;

typedef struct Triangle
{
    point_t angleOne;
    point_t angleTwo;
    point_t angleThree;
    pixel_t triColor;
}triangle_t;

typedef struct Quad
{
    point_t cornerOne;
    point_t cornerTwo;
    point_t cornerThree;
    point_t cornerFour;
    pixel_t quadColor;
}qua_t; 

typedef struct Shape
{
    circle_t* Cir;
    triangle_t* Tri;
    qua_t* Quad;
}shape_t;

/* Parameters: FILE* - input file that is being read in from
*              header_t* - pointer to the struct with all of the header
*                          information of the input image.
*              int* - pointer to the int that holds the number of shapes
* Return: void
* This function reads in the header information and puts
* the values into the header struct.
*/
void readInfo(FILE*, header_t*, int*);

/* Parameters: FILE* - input file that is being read in from
*              shapte_t[] - array that holds the shapes from the input file
*              int - holds the number of shapes from the input file
* Return: void
* This function reads in the shape information by checking which shape is 
* specified in the input file and then inputs the values into the shape 
* specified in a certain position in the shapes array.
*/
void readShapes(FILE*, shape_t[], int);

/* Parameters: FILE* - input file that is being read in from
*              pixel_t* - pointer to the pixel struct to hold the 
*                         rgb values for the background color
* Return: void
* This function reads in the background color information and stores it
* into the pixel struct.
*/
void readBack(FILE*, pixel_t*);

/* Parameters: circle_t - circle struct used to get the circle center x and y
*              point_t - point struct that is used to get the current
*                        x and y pos
* Return:      int - 1 if the point is inside of the circle
*                    and 0 if the point is outside the circle
* This function checks whether or not a given point (x,y) lies within
* the circle coordinates by checking if the distance between the center
* of the circle and the given point is less than the radius set in circle_t.
*/
int isHitCir(circle_t, point_t);

/* Parameters: triangle_t - triangle struct used to get 
*              the three points of the triangle
*              point_t - point struct that is used to get the current
*                        x and y pos
* Return:      int - 1 if the point is inside of the triangle
*                    and 0 if the point is outside the triangle
* This function checks whether or not a given point (x,y) lies within
* the triangle coordinates by using the barycentric formula to see if the 
* point is inside of the triangle.
*/
int isHitTri(triangle_t, point_t);

/* Parameters: qua_t - quad struct used to get the 
*              four corners of the quadurateral
*              point_t - point struct that is used to get the current
*                        x and y pos
* Return:      int - 1 if the point is inside of the quad
*                    and 0 if the point is outside the quad
* This function checks whether or not a given point (x,y) lies within
* the quad coordinates by checking if the point is in either of the two 
* triangles within the quad.
*/
int isHitQua(qua_t, point_t);

/* Parameters: FILE* - out: output file to write all the data to.
*              header_t* - pointer to the header struct to get the background
*              shape_t[] - array that holds the shapes from the input file
*              pixel_t* - pointer to the background color in the header to 
*                         be able to print it out if there is not a shape 
*              w - width of the image
*              h - height of the image  
* Return: void
* This function loops through each pixel and sees if the current pixel is 
* within any of the shapes. If it is, then that pixel will be printed with 
* the color of the respective shape. Otherwise, it will be printed with the
* background color specified in the header.
*/
void makeShapes(FILE* out, header_t*, shape_t[], 
                pixel_t*, int, int, int);

#endif