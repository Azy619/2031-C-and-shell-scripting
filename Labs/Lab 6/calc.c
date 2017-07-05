/***********************************
* EECS 2031 - Lab 6
* Filename: calc.c
* Author: Last name, first name
* Email: Your preferred email address
* Login ID: Your EECS login ID
************************************/


#include <stdio.h>
#include <stdlib.h>


/*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/
int stringToInt(char a[])
{
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


/* Implement a simple calculator.
   Input: two operands and one operator as command-line arguments.
   Output: the result displayed on the standard output.
 */

void main( int argc, char *argv[] )
{
    int result = 0;  /* stores the result of the arithmetic operation */


    /*****************************************/
    /***** ADD YOUR CODE BELOW THIS LINE *****/

    if(argc <= 1)
    {
        printf("Usage: calc [operand_1] [operator] [operand_2]\n");
    }
    else
    {
        int operand1 = stringToInt(argv[1]);
        int operand2 = stringToInt(argv[3]);
        char operator =  argv[2][0];
        if(operator == '+')
        {
            result = operand1 + operand2;
        }
        else if(operator == '-')
        {
            result = operand1 - operand2;
        }
        else if(operator == 'x')
        {
            result = operand1 * operand2;
        }
        else if(operator == '/')
        {
            result = operand1 / operand2;
        }
        else
        {
            result = operand1 % operand2;
        }




        /***** ADD YOUR CODE ABOVE THIS LINE *****/
        /*****************************************/

        /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

        printf( "%d\n", result );
    }

}



