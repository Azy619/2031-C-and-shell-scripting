/***********************************
* EECS2031 - Lab 4		   
* Filename: lab4b.c		  	
* Author: Last name, first name	    
* Email: Your email address	 	
* Login ID: Your EECS login ID 		
************************************/


#include <stdio.h>

#define MAX_SIZE 100

main() {

  char my_strg[ MAX_SIZE ];
  double my_number = 0.0;


  /********** Fill in your code here. **********/

  int c, i = 0;
  int n = 0;  /* number of fractional digits */
  double frac = 0.0; 

  /* Input a string */
  while ( ( c = getchar() ) != '\n' )
    my_strg[ i++ ] = c;
  my_strg[ i ] = '\0';

  /* Convert the string to a double */
  for( i = 0; my_strg[ i ] != '.'; i++ )
    my_number = my_number * 10 + ( my_strg[ i ] - '0' );

  /* At this point, my_strg[i] == '.' and my_number contains the integer part. */
  /* Process the fractional part */
  for( i++, n = 0; my_strg[ i ] != '\0'; i++, n++ )
    frac = frac * 10 + ( my_strg[ i ] - '0' ); 

  /* At this point, my_strg[i] == '\0' */
  /* Adjust the fractional part */
  for( i = 1; i <= n; i++ )
    frac /= 10;  

  my_number += frac;
  
  /*********************************************/

  printf( "%.6f\n", my_number );
}



