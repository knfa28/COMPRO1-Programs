/*******************************************************************************
Program Name: Standard Form Displayer

Last Edited: August 8, 2013

This program will display a number in standard form (with commas).
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
   displays a number in standard form(with commas)
   nInput - number to be displayed
*/
void displayStandard( int nInput )
{
   int nDigits = countDigits( nInput ), /*number of digits in input*/
       nCommas,                         /*number of commas*/
       nDivisor,                        /*divisor to get digits to the left and 
	                                      in between commas*/
	   nCtr;                            /*counter variable*/
	   
   if( nDigits % 3 == 0 ) 
      nCommas = nDigits / 3 - 1;
   else nCommas = nDigits / 3;
   
   nDivisor = posPower(10, nCommas * 3 );

   /*Code executes the same number of times as the number of commas*/
   for( nCtr = 1; nCtr <= nCommas; nCtr++ )
   {
   	  if( nCtr == 1 )
   	     printf("%d,", nInput / nDivisor );
      else printf("%03d,", nInput / nDivisor );
      nInput %= nDivisor; 
	  nDivisor /= 1000;
   }
   
   /*prints the last three digits*/
   if( nCommas == 0 )
      printf("%d", nInput );       	
   else printf("%03d", nInput );       	
}


int main()
{
    /*variable declaration*/
    int n; /*number that will be displayed with commas*/

    /*asking for user input*/
    printf("Enter number: ");
    scanf("%d", &n );

    /*displaying results*/
    printf("\n");
    displayStandard( n );

   return 0;
}

