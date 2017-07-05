/***********************************
* EECS 2031 - Lab 7
* Filename: marks.c
* Author: Last name, first name
* Email: Your preferred email address
* Login ID: Your EECS login ID
************************************/

#include <stdio.h>
#include <stdlib.h>


void main( int argc, char *argv[] )
{


    /*****************************************/
    /***** ADD YOUR CODE BELOW THIS LINE *****/

    if(argc < 3)
    {
        printf("Usage: marks [input_file] [output_file]\n");
    }
    else
    {
        FILE *ifile, *ofile;
        ifile = fopen( argv[1], "r" );
        if ( ifile == NULL )
        {
            printf("File empty!\n");
            exit(1);
        }
        ofile = fopen( argv[2], "w" );
        if ( ofile == NULL )
        {
            printf("No write permission!\n");
            exit(1);
        }

        char fname[30], lname[30];
        int asg1;
        int asg2;
        float avg;
        while ( fscanf( ifile, "%s %s %d %d", &fname, &lname, &asg1, &asg2 ) != EOF )
        {
            avg = (float) (asg1 + asg2) / 2;
            fprintf( ofile, "%s %s %d %d %.1f\n", fname, lname, asg1, asg2, avg);
        }

    }





    /***** ADD YOUR CODE ABOVE THIS LINE *****/
    /*****************************************/

}  /* end main */


