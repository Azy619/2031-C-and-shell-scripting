/***********************************
* EECS2031 - Assignment 1
* Filename: list.c
* Author: Patel, Khushal
* Email: york18@my.yorku.ca
* Login ID: york18
************************************/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List *head, *tail;


/* Display an error message. */

void prtError( char *errMsg )
{
    printf( "%s \n", errMsg );
}


/* Print the content of the list (ignoring the dummy node). */

void prtList()
{
    List *p;
    for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
    printf( "\n");
}



/* Initialize the list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node. */

List *init()
{
    head = ( List * ) malloc( sizeof( List ) );
    if ( head == NULL )
    {
        prtError( "Insufficient memory!" );
        return( NULL );
    }
    head->data = -1;
    head->next = NULL;
    tail = head;
    return ( head );
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertFirst( int d )
{
    List *newList;

    newList = (List*) malloc( sizeof(List) );

    if (newList == NULL)
    {
        return (NULL);
    }

    newList->data = d;
    if (tail == head) /* if List is empty to begin with */
    {
        tail = newList;
        head->next = newList;
        newList->next = NULL;
    }
    else
    {
        List *secondList = head->next;
        head->next = newList;
        newList->next = secondList;
    }
    return newList;
}



/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertLast( int d )
{
    List *newList;
    newList = (List*) malloc(sizeof(List));

    if (newList == NULL)
    {
        return (NULL);
    }

    newList->data = d;
    newList->next = NULL;

    if (head == tail) /*if empty list */
    {
        tail = newList;
        head->next = newList;
    }
    else
    {
        List *old = tail;
        old->next = newList;
        tail = newList;
    }
    return newList;
}



/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* Return -1 if the list is empty, i.e., containing only the dummy node, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be remove. */

int removeFirst()
{
    if (head == tail)
    {
        prtError("Empty list!");
        return -1;
    }

    else
    {
        List *newList = head->next;
        if (newList == tail)
        {
            head->next = NULL;
            tail = head;
        }
        else
        {
            head->next = newList->next;
        }
        int d = newList->data;
        free(newList); /*free up the space memory allocation*/
        return d;
    }
}


/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

List *search( int k )
{
    if (head == tail)
    {
        return NULL;
    }

    List *pointer = head->next;
    while(pointer != NULL)
    {
        if (pointer->data == k)
        {
            return pointer;
        }
        pointer = pointer->next;
    }
    return NULL;


}


/*************************** END OF FILE ***************************/


