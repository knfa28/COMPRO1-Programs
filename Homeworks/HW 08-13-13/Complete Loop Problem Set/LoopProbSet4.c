/*******************************************************************************
Program Name: Binary Converter

Last Edited: August 8, 2013

This program will ask for an input from 0 to 255 and display the binary equiva-
lent
*******************************************************************************/

#include <stdio.h>

/*
   converts a decimal number to binary
   nInput - number to be converted
*/
int decToBin( int nInput )
{
	int nBinary, /*contains the converted binary number*/
	    nMult;   /*multiplier*/
	
	/*Converted binary number is initialized to additive identity, 0. Multiplier
	  is initialized to multiplicative identity, 1. Code executes while altered 
	  input is greater than zero. After execution, input is divided by two and 
	  multiplier is multiplied by 10*/
	for( nBinary = 0, nMult = 1; nInput > 0; nInput /= 2, nMult *= 10 )
	   
	   /*the remainder of current input when divided by two is appended to the 
	     left of the binary number*/
	   nBinary += nInput % 2 * nMult;
	   
	return nBinary;
}

int main()
{
    /*variable declaration*/
    int nInput; /*input number*/

    /*asking for user input*/
    printf("Enter decimal number from 0 to 255: ");
    scanf("%d", &nInput );

    /*displaying results*/
    printf("\n%d in binary is %d", nInput, decToBin( nInput ) );

   return 0;
}

