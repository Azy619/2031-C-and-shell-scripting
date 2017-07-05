/***********************************
* EECS 2031 - Lab 7
* Filename: slist.c
* Author: Last name, first name
* Email: Your preferred email address
* Login ID: Your EECS login ID
************************************/


#include <stdio.h>
#include <stdlib.h>


struct list {
   int data;
   struct list *next;
};




/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}



/* Print the content of the list (ignoring the dummy node). */

void prtList( struct list *head )
{
   struct list *p;
   for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/* Initialize the list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */


void init( struct list **hptr, struct list **tptr )
{
   struct list *head;

   head = ( struct list * ) malloc( sizeof( struct list ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      exit( 1 );
   }
   head->data = -1;
   head->next = NULL;

   *tptr = *hptr = head;
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/


/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* If a new node cannot be created, call prtError() to display
   an error message and exit the program using exit(1). */


void insert( struct list **hptr, struct list **tptr, int d )
{

   struct list *newList;
    newList = (struct list*) malloc(sizeof(struct list));
    if ( newList == NULL ) {
      prtError( "Insufficient memory!" );
      exit( 1 );
   }
   if (hptr == tptr) /*if empty list */
    {
        *tptr = newList;
        (*hptr)->next = newList;
    }
    else
    {
        struct list *old = *tptr;
        old->next = newList;
        *tptr = newList;
    }


}



/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* If the list is empty (i.e., containing only the dummy node),
   call prtError() to display an error message and return -1. */
/* Otherwise, return the data (integer) of the node to be removed. */


int removeFirst( struct list **hptr, struct list **tptr )
{

   if (hptr == tptr)
    {
        prtError("Empty list!");
        return -1;
    }

    else
    {
        struct list *newList = (*hptr)->next;
        if (newList == *tptr)
        {
            (*hptr)->next = NULL;
            tptr = hptr;
        }
        else
        {
            (*hptr)->next = newList->next;
        }
        int d = newList->data;
        free(newList); /*free up the space memory allocation*/
        return d;
    }
}




