/*
************************
*Benjamin McDonnough *
*CPSC2310 Lab10 *
*UserName: mcdonn7 *
*Lab Section: 006 *
***********************
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef TASK4_H
#define TASK4_H

/* 
 * absV - returns the absolute value of x
 *   Example: absV(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 */
int absV(int);

/* 
 * binAnd - x&y using only ~ and |
 *   Example: binAnd(6, 5) = 4
 *   Legal ops: ~ |
 */
int binAnd(int, int);

/* 
 * binNotOr - ~(x|y) using only ~ and &
 *   Example: binNotOr(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 */
int binNotOr(int, int);

/* 
 * binOr - x|y using only ~ and &
 *   Example: binOr(6, 5) = 7
 *   Legal ops: ~ &
 */
int binOr(int, int);

/* 
 * binXor - x^y using only ~ and &
 *   Example: binXor(4, 5) = 1
 *   Legal ops: ~ &
 */
int binXor(int, int);

#endif
