/*******************************************************************************
Program Name: Automorphic Number Identifier

Last Edited: August 8, 2013

This program will keep asking the user for integers and displays whether they 
are automorphic numbers of n-digit or not. Program terminates when zero is in-
putted.
*******************************************************************************/

#include <stdio.h>

#define SENTINEL 0

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
   returns 1 if number is automorphic(the last digits of its square correspond 
   to the number itself)
   nTest - number to be tested for automorphism
*/
int isAutomorphic( int nTest )
{	
	if( nTest < 0 )
	   nTest *= -1;
	
	/*counts the digits in nTest(henceforth referred to as dCnt) and gets the 
	  last dCnt digits in the square. If they are equal, function returns 1*/
	if( nTest * nTest % posPower( 10, countDigits( nTest ) ) == nTest && nTest 
	    != 1 && nTest != 0 )
	   return 1;
	else return 0;
}

int main()
{
    /*variable declaration*/
    int nInput; /*input number*/
    
    /*asking for user input*/    
    do
    {
    	printf("Input: ");
    	scanf("%d", &nInput );
    	
    	/*if input is not zero*/
    	if( nInput != SENTINEL )
    	{
    		if( isAutomorphic( nInput ) )
    		   printf("\nAutomorphic number of %d-digit\n\n", 
			          countDigits( nInput ) );
			else printf("\nNot an Automorphic number.\n\n");
    	}
    }while( nInput != SENTINEL );

   return 0;
}

