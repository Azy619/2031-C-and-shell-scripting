/***********************************
* EECS2031 - Lab 4
* Filename: lab4a.c
* Author: Last name, first name
* Email: Your preferred email address
* Login ID: Your login ID
************************************/

#include <stdio.h>

#define MAX_SIZE 500

void myStrInput ( char *s );
int myStrCmp( char *s1, char *s2 );

int main()
{
    char strg1[ MAX_SIZE ], strg2[ MAX_SIZE ];

    myStrInput( strg1 );
    myStrInput( strg2 );
    printf( "%d\n", myStrCmp( strg1, strg2 ));
    return 0;
}

void myStrInput ( char *s )
{

    int c = getchar();
    int i = 0;
    while(c != '\n')
    {
        *(s + i) = c;
        i++;
        c = getchar();
    }
    *(s + i) = '\0';
}

int myStrCmp( char *s1, char *s2 )
{

    int i = 0;
    for(; *(s1 + i) != '\0'; i++)
    {
        if(*(s1 + i) != *(s2 + i))
        {
            return i;
        }
        else
        {
            if(*(s1 + i + 1) == '\0' && *(s2 + i + 1) == '\0')
            {
                return -1;
            }
        }
    }
    return i;

}

