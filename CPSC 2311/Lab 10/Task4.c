/*
************************
*Benjamin McDonnough *
*CPSC2310 Lab10 *
*UserName: mcdonn7 *
*Lab Section: 006 *
***********************
*/

#include "Task4.h"

/* 
 * absV - absolute value of x
 *   Example: absV(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absV(int x) {
    int w = sizeof(int) << 3;
    int mask = x >> (w - 1);
    return (x ^ mask) - mask;
}

/* 
 * binAnd - x&y using only ~ and |
 *   Example: binAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int binAnd(int x, int y) {
    x = ~x;
    y = ~y;
    return ~(x | y);
}

/* 
 * binNotOr - ~(x|y) using only ~ and &
 *   Example: binNotOr(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 */
int binNotOr(int x, int y) {
    x = ~x;
    y = ~y;
    return (x & y);
}

/* 
 * binOr - x|y using only ~ and &
 *   Example: binOr(6, 5) = 7
 *   Legal ops: ~ &
 */
int binOr(int x, int y) {
    x = ~x;
    y = ~y;
    return ~(x & y);
}

/* 
 * binXor - x^y using only ~ and &
 *   Example: binXor(4, 5) = 1
 *   Legal ops: ~ &
 */
int binXor(int x, int y) {
    int s = ~x & ~y;
    int t = x & y;
    return ~s & ~t;
}



