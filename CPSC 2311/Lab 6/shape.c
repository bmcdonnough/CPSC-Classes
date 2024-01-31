/*
************************
*Benjamin McDonnough
*CPSC 2310 006
*mcdonn7@clemson.edu
************************
*/
#include "shape.h"

int isHitCir(circle_t c, point_t p)
{
    double inCircle;

    //Use the function given to determine the circle
    inCircle = pow((pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2)), .5);

    //Check if that point is within the given radius
    if(inCircle < c.radius){
        return 1;
    }

    return 0;
}

void readInfo(FILE* in, header_t* hdr, circle_t* cir)
{
    //Read in the type of ppm image
    fscanf(in, "%c%c", &hdr->type[0], &hdr->type[1]);

    //Read in the width, height, and maxVal
    fscanf(in, "%u %u %u", &hdr->width, &hdr->height, &hdr->maxVal);

    //Read in the circle center and radius
    fscanf(in, "%i %i %u", &cir->center.x, &cir->center.y, &cir->radius);

    //Read in the r, g, b values for the circle
    fscanf(in, "%u %u %u", 
           &cir->cirColor.r, &cir->cirColor.g, &cir->cirColor.b);
}

void makeCircle (FILE* out, circle_t* cir, int w, int h)
{
    //Create the color for outside of the circle
    pixel_t notInCircle;

    notInCircle.r = 21;
    notInCircle.g = 71;
    notInCircle.b = 52;

    //Loop through each point in the width and height of the image 
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            //Create a temp point to store the x and y pos
            point_t pointTemp;
            
            pointTemp.x = i;
            pointTemp.y = j;

            //Check if that point is in the circle
            if(isHitCir(*cir, pointTemp)){
                //If it is, then writePixel with the color set for circle
                writePixel(out, cir->cirColor);
            }
            else{
                //If not, then writePixel with the color set above
                writePixel(out, notInCircle);
            }
        }
    }
}
