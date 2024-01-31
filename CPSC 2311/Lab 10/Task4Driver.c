/*
************************
*Benjamin McDonnough *
*CPSC2310 Lab10 *
*UserName: mcdonn7 *
*Lab Section: 006 *
***********************
*/

#include "Task4.h"

int main(){

    //Asserts for absV
    assert(absV(1) == 1);
    assert(absV(-15) == 15);

    //Assert for binAnd
    assert(binAnd(3, 5) == 1);

    //Assert for binNotOr
    assert(binNotOr(6,5) == -8);

    //Assert for binOr
    assert(binOr(2, 5) == 5);

    //Assert for binXor
    assert(binXor(4, 7) == -8);

    printf("Passed all test cases");

    return 0;
}