/*******************************************************************************
Program lame: Fibinary Converter

Last Edited: August 8, 2013

This program will ask for 5 numbers in "fibinary" and convert it to decimal.
(a fibinary uses the Fibonacci sequence as the base instead of a given radix)
*******************************************************************************/

#include <stdio.h>

/*
   computes for the nth number in the Fibonacci sequence
   n - ordinality in the Fibonacci sequence
*/
unsigned long computeFibonacci( unsigned long n )
{
	unsigned long lBefore2 = 0, /*two numbers before the current number*/
	   			  lBefore1 = 1, /*one number before the current number*/
	              lCurrent = 1; /*current number*/
	
	/*executes the lumber of times in the passed parameter minus one*/
	for( n; n > 1; n-- )
	{
	   /*shifts current numbers backward*/
       lBefore2 = lBefore1; 
	   lBefore1 = lCurrent;
	   
	   /*the ucrrent number is found by adding the two numbers before it*/
	   lCurrent = lBefore1 + lBefore2;
	}
	
	return lCurrent;
}

/*
   converts a number in Fibinary to Decimal
   nToConv - number to be converted
*/
unsigned long convFib2ToDec( unsigned long lToConv )
{
	unsigned long lConverted = 0, /*decimal equivalent initialized to zero*/
	              lCtr;           /*counter variable*/
	
	/*runs while nToConv it greater than zero; increments counter then removes 
	  last digit in input number*/
	for( lCtr = 1; lToConv > 0; lCtr++, lToConv /= 10 )
	   /*the rightmost digit is multiplied by the corresponding number in the 
	     Fibonacci sequence*/
	   lConverted += lToConv % 10 * computeFibonacci( lCtr );

	return lConverted;
}

int main()
{
    /*variable declaration*/
    unsigned long lInput, /*current input*/
	              lCtr;   /*counter variable*/

    /*asks five times*/
    for( lCtr = 1; lCtr <= 5; lCtr++ )
    {
    	printf("Enter number: ");
    	scanf("%lu", &lInput );
    	
    	printf("Output: %lu\n\n", convFib2ToDec( lInput ) );
    }

   return 0;
}

