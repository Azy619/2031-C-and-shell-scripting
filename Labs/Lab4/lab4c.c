/***********************************
* EECS2031 - Lab 4		   
* Filename: lab4c.c		  	
* Author: Last name, first name	    
* Email: Your email address	 	
* Login ID: Your EECS login ID 		
************************************/


#include <stdio.h>

#define MAX_SIZE 100

main() {

   char my_strg[ MAX_SIZE ];
   char *p = my_strg;
   char *v = my_strg;

   /********** Add your code in the below space. **********/
   /****** Do not use variable my_strg in the code. *******/
   /** You may define additional variables except arrays. */
   
    int len = 0, i;
	char c;
	c = getchar();
	while( c != '\n' ) {
		*p = c;
		p++;
		c = getchar();
	} ;
	*p = '\0';
	p--;
	while( p > v ){
		char tmpc = *p;
		*p = *v;
		*v = tmpc;
		p--;
		v++;
	}
   /********** Add your code in the above space. **********/

   printf( "%s\n", my_strg );  /* output the reversed string */

} /* end main */


