
/*******************************************************************************
Program Name: Ugly Number Finder

Last Edited: August 8, 2013

This program will look for the nth Ugly Number(a number who has no other prime 
factors but 2, 3, and 5) and display it.
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
	if( countFactors( nTest ) == 2 )
	   return 1;
	else return 0;
}

/*
   returns 1 if number is ugly and 0 otherwise
   nTest - number to be tested
*/
int isUgly( int nTest )
{
	int nCtr,          /*counter variable*/
	    isUglyNum = 1; /*boolean variable initialized to true*/
	    
	/*empty statement if input is 1*/
	if( nTest == 1 );
	else 
	{
	   /*loops while nCtr is less than nTest and no other prime factors are 
	     found*/
	   for( nCtr = 1; nCtr <= nTest && isUglyNum; nCtr++ )
	   {
	   	   /*if the current counter is a factor and is prime and is not 2, 3, or
			 5, then the number is not an ugly number*/
	      if( nTest % nCtr == 0 && isPrime( nCtr ) && nCtr != 2 && nCtr != 3 && 
		      nCtr != 5 )
	         isUglyNum = 0;  
	   }
	}
	
	return isUglyNum;
}

int main()
{
    /*variable declaration*/
    int n,        /*inputted ordinality of ugly number*/
        nUglyCtr, /*counts the number of ugly numbers so far*/
	    nCtr;     /*counter variable*/

    /*asking for user input*/
    printf("Enter n: ");
    scanf("%d", &n );
    
    /*computing*/
    
    /*executes statements while the ugly counter is not equal to the input n*/
    for( nCtr = 1, nUglyCtr = 0; nUglyCtr != n; nCtr++ )
       /*if current counter is an ugly number*/
       if( isUgly( nCtr ) )
		  nUglyCtr++; /*increments ugly number counter*/

    /*displaying results*/
    printf("Output: %d", nCtr - 1 );

   return 0;
}

