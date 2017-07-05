/***********************************
* EECS 2031 - Lab 7
* Filename: slistMain.c
* Author: Last name, first name
************************************/


#include <stdio.h>
#include <stdlib.h>
#include "slist.c"

int main()
{
   struct list *head, *tail;
   int i;

   init( &head, &tail );

   for ( i = 1; i <= 10; i++ ) {
	insert( &head, &tail, i*5 );
	prtList( head );
   }

   while ( removeFirst( &head, &tail ) > 0 )
      	prtList( head );

    return 0;
}

