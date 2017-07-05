/***********************************
* EECS 2031 - Assignment 2
* Filename: mm.c
* Author: Patel, Khushal
* Email: york18@my.yorku.ca
* Login ID: york18
************************************/


#include <stdio.h>
#include <stdlib.h>


/***************** DO NOT USE ARRAY INDEXING *****************/
/************** USE ONLY POINTERS IN THIS FILE ***************/

static int** allocate2D( int nrows, int ncols )
{

    int **array, i;

    /* Allocate an array of pointers, each pointing to a row. */
    array = ( int** ) malloc( nrows * sizeof( int* ) );
    if ( array == NULL )
    {
        printf( "Insufficient memory!\n" );
        exit ( 1 );
    }

    /* Allocate each row. */
    for(i = 0; i < nrows; i++)
    {
        *(array + i) = ( int* ) malloc( ncols * sizeof( int ) );
        if ( *(array + i) == NULL )
        {
            printf( "Insufficient memory!\n" );
            exit ( 1 );
        }
    }

    return( array );

}


/*
* Converts a char array into an int
*/
int toInt(char *a)
{
    int c, sign, offset, n;
    offset = 0;
    if (*(a + 0) == '-')    // Handle negative integers
    {
        sign = -1;
    }

    if (sign == -1)    // Set starting position to convert
    {
        offset = 1;
    }
    else
    {
        offset = 0;
    }

    n = 0;

    for (c = offset; *(a+c) != '\0'; c++)
    {
        n = n * 10 + *(a+c) - '0';
    }

    if (sign == -1)
    {
        n = -n;
    }
    return n;
}



/*
   Save the three command-line arguments into nr1, nc1 and nc2.
 */

void get_args( char **argv, int *nr1, int *nc1, int *nc2 )
{
    *nr1 = toInt(*(argv + 1));
    *nc1 = toInt(*(argv + 2));
    *nc2 = toInt(*(argv + 3));
}




/*
   Initialize a 2-dimensional array.
   Element (i, j) is assigned value i+j.
 */

void initMatrix ( int **a, int nrows, int ncols )
{
    int i = 0;
    for(; i < nrows; i++)
    {
        int j = 0;
        for(; j < ncols; j++)
        {
            *(*(a + i) + j) = i + j;
        }

    }

}





/*
   Multiply arrays a and b.
   Array a has nr1 rows and nc1 columns.
   Array b has nc1 rows and nc2 columns.
   Allocate an array c having nr1 rows and nc2 columns.
   Compute a x b and store the result in array c.
   Return array c.
   If an error occurs (e.g., insufficient memory), return NULL pointer.
 */


int **matrix_mult( int **a, int **b, int nr1, int nc1, int nc2 )
{
    int **mm;
    mm = allocate2D(nr1, nc2);
    int sum = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < nr1; i++)
    {
        for (j = 0; j < nc2; j++)
        {
            for (k = 0; k < nc1; k++)
            {
                sum = sum + (*(*(a + i)+ k) * (*(*(b + k) + j)));
            }
            *(*(mm + i) + j) = sum;
            sum = 0;
        }
    }
    return( mm );
}



/************************* END OF FILE *************************/

