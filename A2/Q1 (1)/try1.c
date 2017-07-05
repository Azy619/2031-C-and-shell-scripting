#include <stdio.h>
#include <stdlib.h>


/***************** DO NOT USE ARRAY INDEXING *****************/
/************** USE ONLY POINTERS IN THIS FILE ***************/

int toString(char []);

int main()
{
  char a[100];
  int n;

  printf("Input a valid string to convert to integer\n");
  scanf("%s", a);

  n = toString(a);

  printf("String  = %s\nInteger = %d\n", a, n);

  return 0;
}

int toString(char a[]) {
  int c, sign, offset, n;

  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }

  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }

  n = 0;

  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1) {
    n = -n;
  }

  return n;
}


/*
   Save the three command-line arguments into nr1, nc1 and nc2.
 */

void get_args( char **argv, int *nr1, int *nc1, int *nc2 )
{

   /*************** ADD YOUR CODE HERE ***************/

}




/*
   Initialize a 2-dimensional array.
   Element (i, j) is assigned value i+j.
 */

void initMatrix ( int **a, int nrows, int ncols )
{

   /*************** ADD YOUR CODE HERE ***************/

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

   /*************** ADD YOUR CODE HERE ***************/

   return( NULL );	/* replace this line with your code */
}



/************************* END OF FILE *************************/
