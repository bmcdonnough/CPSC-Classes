/* Fall 2022 PA4
   Benjamin McDonnough
   December 7, 2022
   CPSC 1010-001
   PA4
*/

#include "defs.h"

void reduceSize(struct pixels pixArr[], struct pixels out[], int flagWidth, int flagHeight){
    for (int k=0; k<((flagWidth) * (flagHeight)); k+=2) {
        if ((k % flagWidth) == 0 && k != 0){
           k += flagWidth;
        }
        if (k != (flagWidth * flagHeight)){
           out[k-1].r = (pixArr[k].r + pixArr[k+1].r + pixArr[k+flagWidth].r + pixArr[k+flagWidth+1].r)/4;	
           out[k-1].g = (pixArr[k].g + pixArr[k+1].g + pixArr[k+flagWidth].g + pixArr[k+flagWidth+1].g)/4;	
           out[k-1].b = (pixArr[k].b + pixArr[k+1].b + pixArr[k+flagWidth].b + pixArr[k+flagWidth+1].b)/4;	
        }
    }
}

void greenScreen(struct pixels pixArr[], struct pixels pix2Arr[], struct pixels supPixArr[], int flagWidth, int flagHeight){
	 for(int k=0; k<((flagWidth) * (flagHeight)); k++){
		  if (k % flagWidth == 0 && k != 0){
			  k += flagWidth;
		  }
        if(pix2Arr[k].r == 0 && pix2Arr[k].g == 255 && pix2Arr[k].b == 0){
            supPixArr[k].r = pixArr[k].r;
            supPixArr[k].g = pixArr[k].g;
            supPixArr[k].b = pixArr[k].b;
        }
        else if(pix2Arr[k].r != 0 && pix2Arr[k].g != 255 && pix2Arr[k].b != 0){
            supPixArr[k].r = pix2Arr[k].r;
            supPixArr[k].g = pix2Arr[k].g;
            supPixArr[k].b = pix2Arr[k].b;
        }
    }
}
