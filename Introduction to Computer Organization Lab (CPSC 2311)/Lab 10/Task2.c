/*
************************
*Benjamin McDonnough *
*CPSC2310 Lab10 *
*UserName: mcdonn7 *
*Lab Section: 006 *
***********************
*/

#include<stdio.h>


/*You are going to write a function that returns 1 when ran on a machine that
 uses arithmetic right shifts for data type int and yields 0 otherwise.
 FYI – I tested the solution on the SoC servers on a cerf15 machine so you can
 assume that this machine uses arithmetic right shifts.
 You are to implement the  isArithmetic() function.  You are not allowed to
 change the prototype of the function. You will receive a 0 for this task
 if you change the prototype.
 */


int isArithmetic();

int main()
{
    printf("%d\n", isArithmetic());
    return 0;
}

int isArithmetic()
{
    int x = -1;

    int shifted = x >> 1;

    if(shifted < 0){
        return 1;
    }
    else{
        return 0;
    }
}
