/*
************************
*Benjamin McDonnough *
*CPSC2310 Lab10 *
*UserName: mcdonn7 *
*Lab Section: 006 *
***********************
*/

#include<stdio.h>

int main()
{
    /*Fill in a C expression that evaluates to 1 when the follow conditions are
     *true and to 0 when they are false.  Assume the value is of type int. 
     *Your code MUST follow the Rules described in the lab document. With the
     *additional restriction that you may not use equality (==) or inequality
     *(!=) test. */
    
    //Part A:  
    printf("1.\n");
    int a = 0;
    printf("prints 1 when any bit of a number equals 1 %d\n", !!a);
    a = 10;
    printf("prints 1 when any bit of a number equals 1 %d\n", !!a);


    //Part B:
    printf("\n2.\n");
    int b = -5;
    printf("prints 1 when any bit of a number equals 0 %d\n", !!~b);
    b = 0;
    printf("prints 1 when any bit of a number equals 0 %d\n", !!~b);

    //Part C:
    printf("\n3.\n");
    int c = 1;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", !!(c & 0xFF));
    c = 0;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", !!(c & 0xFF));

    //Part D;
    printf("\n4.\n");
    int d = -1;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !(d & (0xFF << ((sizeof(int) << 3) - 8))));
    d = 0;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !(d & (0xFF << ((sizeof(int) << 3) - 8))));

    return 0;
}
