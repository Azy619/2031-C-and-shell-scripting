/***********************************
* EECS 2031 - Lab 8
* Filename: slen.c
* Author: Last name, first name
* Email: Your preferred email address
* Login ID: Your EECS login ID
************************************/


#include <stdio.h>
#include <stdlib.h>


/* Allocate a 2D array with the number of rows being "num_of_str",
   each row having "str_len" columns.
   If an error occurs, display an error message and return NULL.
*/
char** alloc2D( int num_of_str, int str_len )
{

   char **st;

   /* ===========  ADD YOUR CODE BELOW THIS LINE  =========== */

    st = (char**) calloc( num_of_str, sizeof(char*));
    int i = 0;
    for ( i = 0; i <  num_of_str; i++ )
    {
        *(st + i) = (char*) calloc(str_len, sizeof(char));
    }

   if(!st)
   {
       printf("Cannot allocate an array. Insufficient memomry!");
       exit(1);
   }

   /* ===========  ADD YOUR CODE ABOVE THIS LINE  =========== */

   return( st );

}  /* alloc2D */


/* For each string, compute the string length by counting the
   characters one by one.  Then display on the standard output
   the string, followed by a tab, then the length of the string.
*/
void str_lengths( char **st, int num_of_str )
{

   int i = 0;
   for(; i < num_of_str; i++)
   {
      int j = 0;
      for(; *(*(st + i) + j) != '\0'; j++)
      {

      }
      printf("%s\t%d\n", (*(st + i)), j);
   }

   /* Do not use any C library function here, except printf. */

}  /* str_lengths */


