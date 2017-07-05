/***********************************
* EECS2031 - Assignment 1
* Filename: poly.c
* Author: Patel, Khushal
* Email: york18@my.yorku.ca
* Login ID: york18
************************************/

#include "poly.h"
void toCharArray(int n1, char *s);
void sort( int coeff[ ], int exp[ ] );

int len = 0;
/*
  Initialize all coefficients and exponents of the polynomial to zero.
 */
void init_polynom( int coeff[ ], int exp[ ] )
{
    int i = 0;
    for (; i < ASIZE; i++)
    {
        coeff[i] = exp[i]= 0;
    }
}  /* end init_polynom */


/*
  Get inputs from user using scanf() and store them in the polynomial.
 */
void get_polynom( int coeff[ ], int exp[ ] )
{
    int l = 0;
    int total;
    scanf("%d", &total);
    while(total > 0)
    {
        scanf("%d", &coeff[l]);
        scanf("%d", &exp[l]);
        total--;
        l++;
    }
    coeff[l] = '\0';
    exp[l] = '\0';

}  /* end get_polynom */

void sort( int coeff[ ], int exp[ ] )
{
    int i = 0;
    int j = 0;
    int a;
    int b;

    for(; coeff[i] != '\0' || exp[i] != '\0'; i++)
    {
        j = 0;
        for (j = i + 1; coeff[j] != '\0' || exp[j] != '\0'; j++)
        {
            if (exp[i] < exp[j])
            {
                a = exp[i];
                b = coeff[i];
                exp[i] = exp[j];
                coeff[i] = coeff[j];
                exp[j] = a;
                coeff[j] = b;
            }
        }
    }
}

/*
  Convert the polynomial to a string s.
 */
void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{
    int j = 0;
    int k = 0;
    int l = 0;
    int boolean = 0;
    for(; coeff[k] != '\0' || exp[k] != '\0';)
    {
        if(coeff[k] == 1 && exp[k] == '\0')
        {
            s[j] = '1';
            j++;
        }
        else if(coeff[k] == -1 && exp[k] == '\0')
        {
            s[j - 1] = '-';
            s[j] = '1';
            j++;
        }
        else if(coeff[k] == 0)
        {
            /* do nothing */
        }
        else
        {
            l = 0;
            char temp[ASIZE];
            char temp2[ASIZE];

            if(coeff[k] == 1)
            {
                /* don't do anything. Since coefficient 1 should not be printed */
            }
            else
            {
                if(coeff[k] == -1 && j != 0)
                {
                    s[j - 1] = '-';
                }
                else
                {
                    toCharArray(coeff[k], temp); /* If coeff[k] is not just a digit but a number > 9*/
                    for(; temp[l] != '\0'; l++)
                    {
                        /* s[j - 1] is initially '+' but since the next coefficient is negative '+' should not be printed but instaead '-' should be there*/
                        if((temp[l] == '-' && j != 0)) /*j!= 0 because if first coefficient is negative then s[j - 1] is out of bound*/
                        {
                            s[j - 1] = temp[l];
                        }
                        else
                        {
                            s[j] = temp[l];
                            j++;

                        }
                    }
                }
            }
            if(exp[k] == 0)
            {
                /* don't do anything */
            }
            else
            {
                s[j] = 'x';
                j++;
                if(exp[k] == 1)
                {
                    /* don't do anything */
                }
                else
                {
                    s[j] = '^';
                    j++;
                    l = 0;
                    toCharArray(exp[k], temp2);
                    for(; temp2[l] != '\0'; l++)
                    {
                        s[j] = temp2[l];
                        j++;
                    }
                }
            }
            /* print '+' only if there is a next element and if next element is 0 then no need to print it*/
            if(coeff[k + 1] != '\0' || exp[k + 1] != '\0')
            {
                s[j] = '+';
                j++;
            }
        }
        k++;
    }
    if(j == 0)
    {
        s[j] = '0';
        s[j + 1] = '\0';
    }
    else
    {
        s[j] = '\0';
    }


}  /* end polynom_to_string */

/* This method converts an integer into char Array */
void toCharArray(int n1, char *s)
{
    char buffer[ASIZE];
    int i = 0;
    int len;
    int booleanIsNeg = 0;

    /* If integer is 0*/
    if(n1 == 0)
    {
        s[0] = '0';
        s[1] = '\0';
    }
    else
    {
        if(n1 < 0) /* negative number */
        {
            booleanIsNeg = 1;
            n1 = -1 * n1;
        }

        for(; n1 != 0; i++)
        {
            buffer[i] = n1 % 10 + '0';
            n1 = n1 / 10;
        }
        if(booleanIsNeg == 1)
        {
            buffer[i] = '-';
            i++;
        }
        buffer[i] = '\0';
        len = i;
        int j = 0;
        /* reverse the buffer array*/
        for(; j != len; j++)
        {
            s[j] = buffer[i - 1];
            i--;
        }
        s[j] = '\0';
    }
}

/*
  Evaluate the polynomial for the value of x and store the result p(x) in variable result.
 */
void eval_polynom(int coeff[ ], int exp[ ], double x, double *result )
{
    int j = 0;
    double dupx = x;
    *result = 0;

    for(; coeff[j] != '\0' || exp[j] != '\0'; j++)
    {
        int expo = exp[j];
        if(expo == 0)
        {
            x = 1;
        }
        else
        {
            if(expo > 0)
            {
                if(expo == 1)
                {
                    x = x;
                }
                else
                {
                    while(expo != 1)
                    {
                        x = x * dupx;
                        expo--;
                    }
                }
            }
            else
            {
                if(expo == -1)
                {
                    x = 1 / x;
                }
                else
                {
                    while(expo != -1)
                    {
                        x = x * dupx;
                        expo++;
                    }
                    x = 1 / x;
                }
            }
        }
        double intermediate = coeff[j] * x;
        *result = *result + intermediate;
        x = dupx;
    }

}  /* end eval_polynom */



/*
  Add two polynomials and the result is stored in the first polynomial (arrays co1[] and ex1[]).
 */
void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ] )
{
    sort(co1, ex1);
    sort(co2, ex2);

    int co2b[ASIZE];
    int ex2b[ASIZE];

    len = 0;
    int length1 = 0; /* to store length of polynomial 1 */
    int length2 = 0; /* (to store length of co2 which is same as ex2) || (to store length of plynomial 2) */

    while(co1[length1] != '\0'|| ex1[length1] != '\0')
    {
        length1++;
    }

    while(co2[length2] != '\0'|| ex2[length2] != '\0')
    {
        length2++;
    }

    int index = 0;
    while(index < length2)
    {
       co2b[index] = co2[index];
       index++;
    }

    index = 0;
    while(index < length2)
    {
       ex2b[index] = ex2[index];
       index++;
    }


    int i = 0;
    int k = 0;

    if(length1 == 0)
    {
        co1[length1] = co2[length2];
        length1++;
    }
    /* doing addition of the exponents with 0 first*/
    if(ex1[length1 - 1] == ex2[length2 - 1] && ex1[length1 - 1] == 0)
    {
        int d = co1[length1 - 1] + co2[length2 - 1]; /* add the two coffecients of the same exponents */
        co1[length1 - 1] = d;
        co2[length2 - 1] = 0; /*turning the coefficient into 0 since its addition is done*/
    }

    for(; co1[i] != '\0' || ex1[i] != '\0'; i++)
    {
        int j = 0;
        for(; j < length2; j++)
        {
            if(ex1[i] == ex2[j] && ex1[i] != 0)
            {
                int d = co1[i] + co2[j]; /* add the two coffecients of the same exponents */
                co1[i] = d;
                co2[j] = 0; /*turning the coefficient into 0 since its addition is done*/
                ex2[j] = 0; /*turning the exponent into 0 since its addition is done*/
            }
        }
    }

    /* adding remaining elements of second polynomial to first one*/
    for(; k < length2; k++)
    {
        if(co2[k] != 0 || ex2[k] != 0)
        {
            co1[i] = co2[k];
            ex1[i] = ex2[k];
            i++;
        }
    }

    ex1[i] = '\0';
    co1[i] = '\0';
    len = i;

    index = 0;
    while(index < length2)
    {
       co2[index] = co2b[index];
       index++;
    }

    index = 0;
    while(index < length2)
    {
       ex2[index] = ex2b[index];
       index++;
    }
    sort(co1, ex1);


}  /* end add_ polynom */


/************************** END OF FILE ***************************/




