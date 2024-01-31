/*
************************
*Benjamin McDonnough
*CPSC 2310 006, F23
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

int isHitTri(triangle_t t, point_t p){
    double a, b, c;

    double denom = ((t.angleTwo.y - t.angleThree.y) * 
                       (t.angleOne.x -t.angleThree.x)) + 
                      ((t.angleThree.x - t.angleTwo.x) *
                       (t.angleOne.y - t.angleThree.y));

    a = ((t.angleTwo.y - t.angleThree.y) * (p.x - t.angleThree.x)) +
        ((t.angleThree.x - t.angleTwo.x) * (p.y - t.angleThree.y));

    a /= denom;

    b = ((t.angleThree.y - t.angleOne.y) * (p.x - t.angleThree.x)) +
        ((t.angleOne.x - t.angleThree.x) * (p.y - t.angleThree.y));

    b /= denom;
    c = 1.0 - a - b;

    if((a >= 0 && a <= 1) && (b >= 0 && b <= 1) && (c >= 0 && c <= 1)){
        return 1;
    }
    return 0;
};

int isHitQua(qua_t q, point_t p){
    triangle_t tempTriOne, tempTriTwo;

    tempTriOne.angleOne = q.cornerOne;
    tempTriOne.angleTwo = q.cornerTwo;
    tempTriOne.angleThree = q.cornerThree;
    
    tempTriTwo.angleOne = q.cornerOne;
    tempTriTwo.angleTwo = q.cornerThree;
    tempTriTwo.angleThree = q.cornerFour;

    if(isHitTri(tempTriOne, p) == 1 || isHitTri(tempTriTwo, p) == 1){
        return 1;
    }
    return 0;
}

void readInfo(FILE* in, header_t* hdr, int* numShapes)
{
    //Read in the type of ppm image and width, height, and maxVal
    fscanf(in, "%c%c %u %u %u", &hdr->type[0], &hdr->type[1],
           &hdr->width, &hdr->height, &hdr->maxVal);

    //Read in the number of shapes to add to the image
    fscanf(in, "%i", numShapes);
}

void readBack(FILE* in, pixel_t* backColor){
    fscanf(in, "%u %u %u", &backColor->r,
           &backColor->g, &backColor->b);
}

void readShapes(FILE* in, shape_t shapes[], int numShapes){
    //Read in the shapes based off of the type given in the input file
    for(int i = 0; i < numShapes; i++){
        char shapeType[4];
        fscanf(in, "%s", shapeType);

        if(strcmp(shapeType, "Cir") == 0){
            shapes[i].Cir = (circle_t *)malloc(sizeof(circle_t));
            shapes[i].Tri = NULL;
            shapes[i].Quad = NULL;
            //Read in the circle center and radius
            fscanf(in, "%d %d %u", &shapes[i].Cir->center.x, 
                    &shapes[i].Cir->center.y, &shapes[i].Cir->radius);
            
            //Read in the r, g, b values for the circle
            fscanf(in, "%u %u %u", 
                    &shapes[i].Cir->cirColor.r, &shapes[i].Cir->cirColor.g, 
                    &shapes[i].Cir->cirColor.b);
        }
        else if(strcmp(shapeType, "Tri") == 0){
            shapes[i].Tri = (triangle_t *)malloc(sizeof(triangle_t));
            shapes[i].Cir = NULL;
            shapes[i].Quad = NULL;
            //Read in the three points that make up the triangle
            fscanf(in, "%d %d", &shapes[i].Tri->angleOne.x, 
                   &shapes[i].Tri->angleOne.y);
            fscanf(in, "%d %d", &shapes[i].Tri->angleTwo.x, 
                   &shapes[i].Tri->angleTwo.y);
            fscanf(in, "%d %d", &shapes[i].Tri->angleThree.x, 
                   &shapes[i].Tri->angleThree.y);

            //Read in the r, g, b values for the triangle
            fscanf(in, "%u %u %u", 
                    &shapes[i].Tri->triColor.r, &shapes[i].Tri->triColor.g, 
                    &shapes[i].Tri->triColor.b);
        }
        else if(strcmp(shapeType, "Qua") == 0){
            shapes[i].Quad = (qua_t *)malloc(sizeof(qua_t));
            shapes[i].Tri = NULL;
            shapes[i].Cir = NULL;
            //Read in the four points that make up the quadrilateral
            fscanf(in, "%d %d", &shapes[i].Quad->cornerOne.x, 
                   &shapes[i].Quad->cornerOne.y);
            fscanf(in, "%d %d", &shapes[i].Quad->cornerTwo.x, 
                   &shapes[i].Quad->cornerTwo.y);
            fscanf(in, "%d %d", &shapes[i].Quad->cornerThree.x, 
                &shapes[i].Quad->cornerThree.y);
            fscanf(in, "%d %d", &shapes[i].Quad->cornerFour.x, 
                   &shapes[i].Quad->cornerFour.y);

            //Read in the r, g, b values for the quad
            fscanf(in, "%u %u %u", 
                    &shapes[i].Quad->quadColor.r, &shapes[i].Quad->quadColor.g, 
                    &shapes[i].Quad->quadColor.b);
        }
    } 
}

void makeShapes(FILE* out, header_t* hdr, shape_t shape[], 
                pixel_t* backColor, int w, int h, int numShapes)
{
    bool isPrinted = false;
    //Loop through each point in the width and height of the image 
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            //Create a temp point to store the x and y pos
            point_t pointTemp;
            
            pointTemp.x = i;
            pointTemp.y = j;

            isPrinted = false;
            for(int k = 0; k < numShapes; k++){
                if(shape[k].Cir != NULL && 
                   isHitCir(*shape[k].Cir, pointTemp) &&
                   !isPrinted){
                    //If it is, then writePixel with the color set for that circle
                    writePixel(out, shape[k].Cir->cirColor);
                    isPrinted = true;
                }
                else if(shape[k].Tri != NULL &&
                   isHitTri(*shape[k].Tri, pointTemp) == 1 &&
                   !isPrinted){
                    //If it is, then writePixel with 
                    //the color set for that triangle
                    writePixel(out, shape[k].Tri->triColor);
                    isPrinted = true;
                }
                else if(shape[k].Quad != NULL &&
                        isHitQua(*shape[k].Quad, pointTemp) &&
                        !isPrinted){  
                    //If it is, then writePixel with 
                    //the color set for that quad
                    writePixel(out, shape[k].Quad->quadColor);
                    isPrinted = true;
                }
                
            }

            if(!isPrinted){
                writePixel(out, *backColor);
            }
        }
    }
}
