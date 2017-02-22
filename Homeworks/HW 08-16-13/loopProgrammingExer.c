/*******************************************************************************
Program Name:

This program will
*******************************************************************************/

#include <stdio.h>

/*
   computes for the factorial of a number
   nInput - number whose factorial is to be computed
*/
int computeFactorial( int nInput )
{
	int nFactorial = 1;/*factorial is initialized to multiplicative identity*/
	
	if(nInput == 0 || nInput == 1)
        return 1;
	
	else
	{
        while( nInput > 1 )/*while current multiplier is greater than 1*/
        {
    	    nFactorial *= nInput;/*current factorial is multiplied to current
                                   multiplier*/
    	    nInput--;/*multiplier is decremented*/
        } 
        return nFactorial;
    }   
}

/*
   raises a number to a certain power
   nBase - base number
   nExp  - exponent of number
*/
float power( int nBase, int nExp )
{
	float fPower;
	
	/*non-negative exponent*/
	if( nExp >= 0 )
	
	   /*initializes the power to the multiplicative identity 1 and multiplies 
	     it by th ebase as long as the exponent, acting as counter, is greater 
		 than or equal to one. Exponent is decremented*/
	   for( fPower = 1; nExp >= 1; nExp-- )
	      fPower *= nBase;
	else
	{
	   /*negates the negative exponent*/
	   nExp *= -1;
	   
	   /*same as above but divides instead of multiplying*/
	   for( fPower = 1; nExp >= 1; nExp-- )
	      fPower /= nBase;
    }
	
	return fPower;
}

/*
   for two integers x and y, computes x^0/0! + x^1/1! - x^2/2! + x^3/3! - ... 
   x^y/y!
   x, y - parameters
*/
float computeExpression( int x, int y )
{
	int i;
	float fResult = 0;
	
	for( i = 0; i <= y; i++ )
	{
		if( i == 0 || i % 2 != 0 )
		   fResult += power( x, i ) / computeFactorial( i );
		else fResult -= power( x, i ) / computeFactorial( i );
	}
	
	return fResult;
}

/*
   counts the factors of a number
   nInput - number whose factors are to be counted
*/
int countFactors( int nInput )
{
	int nFactorCount, /*container for factor count*/
	    i;            /*counter variable*/
	
	if( nInput == 1 ) /*1 only has one factor*/
	   return 1;
	else 
	{
	   nFactorCount = 2; /*all other number have at least 2 factors, 1 and 
	                         itself*/
	
	   /*from 2 to half the input number*/
	   for( i = 2; i <= nInput / 2; i++ )
	      if( nInput % i == 0 )
	         nFactorCount++;
	
	   return nFactorCount;
    }
}

/*
   returns 1 if input is prime and 0 otherwise
   nInput - number to be tested
*/
int isPrime( int nInput )
{
	/*a number is prime if and only if it has exactly two positive factors*/
	if( countFactors( nInput ) == 2 )
	   return 1;
	else return 0;
}

/*
   return the nth prime number
   n - ordinality of the prime number
*/
int findNthPrime( int n )
{
	int i = 1,    /*initial count of the integers to be checked*/
	    nCtr = 0; /*initial count of the prime numbers*/
 
	/*checks for all numbers until prime count is equal to n*/
	while ( nCtr < n )
	{    
	    i++;  
    	if (isPrime(i))
      		nCtr++;
	}
	
	return i;
}

/*
   displays all pairs of x and y from n to the nth prime number that, when eval-
   uated in the expression, are less than the nth prime number.
   n - lower limit. Upper limit is the nth prime number.
*/
void displayAllPossible( int n )
{
	int x, y,
	    nPrime = findNthPrime( n );
	
	for( x = n; x <= nPrime; x++ )
	{
		for( y = n; y <= nPrime; y++ )
		{
			if( computeExpression( x, y ) <= nPrime )
			   printf("x = %d, y = %d\n", x, y );
		}
	}
}

int main()
{
    /*variable declaration*/
    int n, temp;

    /*asking for user input*/
    printf("Input n: ");
    scanf("%d", &n);
    
    /*displaying results*/
    printf("Nth Prime = %d\n", findNthPrime( n ) );
    displayAllPossible( n );

system("pause");
   return 0;
}

