/*******************************************************************************
Program name: Digit Prime

Progammed by: Kurt Aquino
              Seaver Choy
              Austin Fernandez
Section: S21A

Last edited on: 08/12/2013

This program will as the user for two intgers the calculate for the number of 
digit primes within the given range.
*******************************************************************************/

#include<stdio.h>

/*checks all of the numbers in the given range if they are prime or not*/
int getPrime(int Num1, int Num2)
{
	/*variable declarartion*/
	int nPrime = 0,             /*initial count of prime numbers present*/
	    nTemp, nTemp2, nTemp3,  /*temporary variables for checking*/
		i, j, k,                /*counter variables*/
		nSum;                   /*stores the sum of the digits*/

	/*checks all integers within the range if they are prime or not*/
	for(i = Num1; i <= Num2; i++)
	{		
		nTemp = 0; /*initial count of the test variable*/
		
		/*checks whether the integer is a Prime Number or not*/
   		for(j = 2; j <= i / 2; j++)
     	{
	     	if (i % j == 0)    
	   	   		nTemp = 1; 
     	}
		
		/*checks if the Prime Number is a Digit Prime or Not*/ 
		if(nTemp == 0)
		{	
			nTemp2 = 0;  /*initial count of the test variable*/
			nTemp3 = i;  /*temporarily stores the value of i*/
			nSum = 0;    /*initial number of the sum*/
			
			/*adds all of the digits of the prime number*/		
			do
			{
				nSum = nSum + nTemp3 % 10;
				nTemp3 /= 10;
			}while(nTemp3 > 0);
			
			/*checks if the sum is also a Prime Number*/
			for(k = 2; k <= nSum / 2; k++)
			{
				if(nSum % k == 0)
					nTemp2 = 1;	
			}
			
			/*if the sum is also a Prime Number, the
			 number of Digit Primes is incremented*/
			if(nTemp2 == 0)
				nPrime++;
		}		
	}
	/*returns the number of Digit Primes present within the range*/
	return nPrime;
}

int main()
{
	/*variable declaration*/
	int nInput,    /*stores user input*/
		nCtr,      /*counter variable*/
		t1, t2;    /*higher and lower bound variables*/

	/*asks for user input*/
	printf("How many times do you want to execute the program? ");
	scanf("%d", &nInput);
	
	/*executes the program as many times as the user indicated*/
	for(nCtr = 1; nCtr <= nInput; nCtr++)
	{
		/*stores the lower-bound integer*/
		printf("\nInput first integer: ");
		scanf("%d", &t1);
		
		/*stores the upper-bound integer*/
		printf("Input second integer: ");
		scanf("%d", &t2);
		
		/*displays the number of Digit Primes within the given range*/
		printf("Output: %d\n", getPrime(t1, t2));
	}
	return 0;
}
