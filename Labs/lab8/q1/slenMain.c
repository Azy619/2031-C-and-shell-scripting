/***********************************
* EECS 2031 - Lab 8
* Filename: slenMain.c
* Author: U. T. Nguyen
************************************/

#include <stdio.h>
#include <stdlib.h>
#include "slenArray.c"

#define MAX_STR_LEN 100

int main() {

   char **str;
   int number_of_str, i;

   /* Let user input the number of strings. */
   /* Assumption: number_of_str > 0 */
   scanf( "%d", &number_of_str );
   if( number_of_str <= 0 )
      exit( 1 );

   /* Allocate a 2D array for these strings. */
   str = alloc2D( number_of_str, MAX_STR_LEN );
   if( !str )
      exit( 1 );

   /* Let users input the strings. */
   for( i = 0; i < number_of_str; i++ )
      scanf( "%s", str[i] );

   /* Compute and output string lengths */
   str_lengths( str, number_of_str );
   return (0);
}


