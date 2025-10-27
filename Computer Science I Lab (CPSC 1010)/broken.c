/* 
	Benjamin McDonnough
	September 27, 2022
	CPSC 1011-001
	This program creates an array containing 10 integers
   and then at the bottom checks to see if the number 11 
	is in the array.

   Note: the program contains a bug that only shows up when 
	it is run.
*/

#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    int i = 0, count = 0, search = 1, found = 0;
    int number = 5;   
    int table[10];

    table[0] = number;
    printf( "table[%i]: %i\n", count, table[count] );

    count = 1;
    while( count < 10 ) {
		 table[count] = number++ * 2;
		 printf( "table[%i]: %i\n", count, table[count] );
       count++;
    }

    while( search == 1 ) {
       if( table[i++] == 11 ) {
         search = 0;
			found = i - 1;
		 }
		 if( count == i ) {
			 search = 0;
		 }
    }
	
	 if( found )
       printf( "The number 11 is in the table at location: %d\n", found );
    else
       printf( "The number 11 is not in the table.\n" );

    return 0;
}
