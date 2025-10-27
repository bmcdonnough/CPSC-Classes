/*
************************
*Benjamin McDonnough *
*CPSC2310 Lab10 *
*UserName: mcdonn7 *
*Lab Section: 006 *
***********************
*/

#include <stdio.h>

int isOneOdd(unsigned);


int main()
{

    printf("%d\n", isOneOdd(128));
    printf("%d\n", isOneOdd(64));

    return 0;
}
/*This functions checks if any of the odd bits are one.  If it is return 1 
 *otherwise return 0.  You can assume w = 32; 
 * Example if the bit pattern is 1100 (w=4) would return 1 for true becuase 
 *the 1st bit in the number is a one. 
 *You must follow the Bit-Level Rules for this problem. */
int isOneOdd(unsigned int x)
{
    int mask = 0xAAAAAAAA;
    
    return (x & mask) != 0;
}
