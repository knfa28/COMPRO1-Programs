/*******************************************************************************
Program name: Digit Prime

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 08/12/2013

This program will as the user for two intgers the calculate for the number of 
digit primes within the given range.
*******************************************************************************/

#include<stdio.h>

int getPrime(int Num1, int Num2)
{
	int nPrime = 0,
	    nFactor, nFactor2,
		i, j, k,
		nSum = 0;

	for(i = Num1; i <= Num2; i++)
	{		
		nFactor = 0;
		
   		for(j = 2; j < i / 2; j++)
     	{
	     	if (i % j == 0)    
	   	   		nFactor = 1; 
     	}
		 
		if(nFactor == 0)
		{	
			nFactor2 = 0;
					
			do
			{
				nSum = nSum + i % 10;
				i /= 10;
			}while(i > 0);
			
			for(k = 2; k < nSum / 2; k++)
			{
				if(nSum % k == 0)
					nFactor2 = 1;	
			}
			
			if(nFactor2 == 0)
				nPrime++;
		}		
	}
	return nPrime;
}

int main()
{
	int nInput,
		nCtr,
		t1, t2;
	char cNull;
	
	printf("How many times do you want to execute the program? ");
	scanf("%d", &nInput);
	
	for(nCtr = 1; nCtr <= nInput; nCtr++)
	{
		printf("\nInput first integer: ");
		scanf("%c%d", &cNull, &t1);
		
		printf("Input second integer: ");
		scanf("%c%d", &cNull, &t2);
		
		printf("Output: %d\n", getPrime(t1, t2));
	}
	return 0;
}
