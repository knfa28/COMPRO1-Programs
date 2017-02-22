/*******************************************************************************
Program Name: Histogram Generator

Last Edited: August 8, 2013

This program will generate a histogram of any non-negative input number
*******************************************************************************/

#include <stdio.h>

/*
   counts the digits in a number
   nInput - number whose digits are to be counted
*/
int countDigits( int nInput )
{
	int nDigitCount = 1; /*number of digits, initialized to 1 because numbers 
	                       have at least 1 digit*/
	
	/*if number is negative*/
	if( nInput < 0 )
	   nInput *= -1; /*gets absolute value of number*/
	
	while( nInput > 9 )
	{
	   /*rightmost digit is removed*/
	   nInput /= 10;
	   
	   /*digit count is incremented*/
	   nDigitCount++;
    }
    
	return nDigitCount;
}

/*
   raises a number to a certain power
   nBase - base number
   nExp  - exponent of number
*/
int posPower( int nBase, int nExp )
{
	int nPower;
	
	/*non-negative exponent*/
	if( nExp >= 0 )
	
	   /*initializes the power to the multiplicative identity 1 and multiplies 
	     it by th ebase as long as the exponent, acting as counter, is greater 
		 than or equal to one. Exponent is decremented*/
	   for( nPower = 1; nExp >= 1; nExp-- )
	      nPower *= nBase;
	else
	{
	   /*negates the negative exponent*/
	   nExp *= -1;
	   
	   /*same as above but divides instead of multiplying*/
	   for( nPower = 1; nExp >= 1; nExp-- )
	      nPower /= nBase;
    }
	
	return nPower;
}

/*
   displays a given character a given number of times
   c      - character to display
   nCount - number of times to display it
*/
void display( char c, int nCount )
{
	/*count id decremented until it is zero*/
	for( nCount; nCount > 0; nCount-- )
	   printf("%c", c );
}

/*
   displays a histogram for a number
   nInput - number whose histogram will be displayed
*/
void displayHistogram( int nInput )
{
	int nDigit = countDigits( nInput ),        /*number of digits in the 
	                                             number*/
	    nDivisor = posPower( 10, nDigit - 1 ); /*divisor to get leftmost digit*/
	    
	/*executes while input is greater than zero. After execution, input's left-
	  most digit is removed and divisor is divided by 10*/
	for( nDigit; nInput > 0; nInput %= nDivisor, nDivisor /= 10 )
	{
		/*displays the digit*/
		printf("%d ", nInput / nDivisor );
		
		/*displays asterisks equal to the current digit*/
		display( '*', nInput / nDivisor );
		printf("\n");
	}
}

int main()
{
    /*variable declaration*/
    int n; /*number whose histogram will be displayed*/

    /*asking for user input*/
    printf("Enter number: ");
    scanf("%d", &n );

    /*displaying results*/
    printf("\n");
    displayHistogram( n );

   return 0;
}

