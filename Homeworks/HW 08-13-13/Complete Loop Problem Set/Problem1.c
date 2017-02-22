/*******************************************************************************
Program Name: Digit Prime Counter

Last Edited: August 8, 2013

This program will ask for the number of time to ask for input. It then asks for 
an interval and displays the number of digit primes within the interval, inclu-
sive.
(A digit prime is a prime number whose sum of digits is also prime)
*******************************************************************************/

#include <stdio.h>

/*
   counts the factors of passed number
   nNum - number to count factors of; only works with positive numbers
*/
int countFactors( int nNum )
{
	int nCtr,         /*counter variable*/
	    nFactorCount; /*number of factors\*/
	    
	if( nNum == 1 )
	   nFactorCount = 1;/*1 has only itself as a variable*/
	else if( nNum == 0 )
	   nFactorCount = 0; /*zero has no factors*/
	else nFactorCount = 2; /*other numbers have at least 2 factors, 1 and 
	                         itself*/
	
	/*checks from 2 until half the number*/
	for( nCtr = 2; nCtr <= nNum / 2; nCtr++ )
	   if( nNum % nCtr == 0 ) /*if number is divisible*/
	      nFactorCount++; /*increments counter*/
	      
	return nFactorCount;
}

/*
   returns 1 if number is prime and 0 otherwise
   nTest - number to be tested
*/
int isPrime( int nTest )
{
    /*prime numbers only have 2 factors*/
	if( countFactors( nTest ) ==  2)
	   return 1;
	else return 0;
}

/*
   adds the digits of a number
   nToAdd - number whose digits are to be added
*/
int addDigits( int nToAdd )
{
	int nSumDigits; /*sum of the digits of the number*/
	
	/*the sum is initialized to zero. The code executes while the altered input
	  number is greater than zero. After executing, the input number's rightmost
	  digit is removed.*/
	for( nSumDigits = 0; nToAdd > 0; nToAdd /= 10 )
	
	   /*adds the rightmost digit to the sum variable*/
	   nSumDigits += nToAdd % 10;
	   
	return nSumDigits;
}

/*
   returns 1 if input is digit prime and 0 otherwise
   nInput - number to be testes
*/
int isDigitPrime( int nInput )
{
	/*if number is prime and the sum of its digits is prime as well, returns 1*/
	if( isPrime( nInput ) && isPrime( addDigits( nInput ) ) )
	   return 1;
	else return 0;
}

int main()
{
    /*variable declaration*/
    int n,                /*number of iterations*/
        nLowLim,          /*lower limit*/
        nHighLim,         /*higher limit*/
		nCtr1, nCtr2,     /*counter variables*/
		nDigitPrimeCount; /*count of digit primes within range*/

    /*asking for user input*/
    printf("Enter n: ");
    scanf("%d", &n );
    
    /*repeats the number of times specified by user*/
    for( nCtr1 = 1; nCtr1 <= n; nCtr1++ )
    {
    	/*asks for limits*/
    	printf("Enter lower limit: ");
    	scanf("%d", &nLowLim );
    	
    	printf("Enter higher limit: ");
    	scanf("%d", &nHighLim );
    	
    	/*initializes count to zero and counter to lower limit. It then tests 
		  all number from lower limit to higher limit. It then icnrements 
		  counter*/
    	for( nDigitPrimeCount = 0, nCtr2 = nLowLim; nCtr2 <= nHighLim; nCtr2++ )
    	   /*increments digit prime counter is current counter is a digit 
		     prime*/
    	   if( isDigitPrime( nCtr2 ) )
    	      nDigitPrimeCount++;
    	     
	    /*prints the number of digit primes within range*/ 
    	printf("Output: %d\n\n", nDigitPrimeCount );	
    }

   return 0;
}

