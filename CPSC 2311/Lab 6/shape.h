/*
************************
*Benjamin McDonnough
*CPSC 2310 006
*mcdonn7@clemson.edu
************************
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

/* Parameters: FILE* - input file that is being read in from
*              header_t* - pointer to the struct with all of the header
*                          information of the input image.
*              circle_t* - pointer to the circle struct that holds
*                          the center point, radius, and color of the circle
* Return: void
* This function reads in the header and circle information and puts
* the values into the header and circle structs respectively.
*/
void readInfo(FILE*, header_t*, circle_t*);

/* Parameters: circle_t - circle struct used to get the circle center x and y
*              point_p - point struct that is used to get the current
*                        x and y pos
* Return:      int - 1 if the point is inside of the circle
*                    and 0 if the point is outside the circle
* This function checks whether or not a given point (x,y) lies within
* the circle coordinates by checking if the distance between the center
* of the circle and the given point is less than the radius set in circle_t.
*/
int isHitCir(circle_t, point_t);

/* Parameters: FILE* - out: output file to write all the data to.
*              circle_t* - pointer to the circle struct to get the 
*                          rgb values set in the input file for the 
*                          circle
*              w - width of the image
*              h - height of the image  
* Return: void
* This function sets the color for outside of the circle, loops through
* the width and height of the image, checks if the currnt point is
* in the circle, and writes that pixel with the rgb values of the circle
* if the point is inside the circle and the rgb values set otherwise if
* outside the circle.
*/
void makeCircle(FILE* out, circle_t* cir, int w, int h);

#endif