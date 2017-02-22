/*******************************************************************************
Program name: Pythagorean triple

Programmed by: Kurt Aquino
Last edited on: 06/19/2013

This program will
*******************************************************************************/

#include<stdio.h>

/* gets the sum of the squares of nNum1 and nNum2 */
int getSquare(int nNum1, int nNum2)
{
	int nSquare;
	nSquare = nNum1 * nNum1 + nNum2 * nNum2;
	return nSquare;
}

/*checks whether nSquare is a perfect square or not */
int getPrfctSqr(int nSquare)
{
	int nTest;
	for(nTest = 0 ; nTest < 20 ; nTest ++)
	{
		if(nSquare == nTest * nTest)
			return 1;		
	}
	return 0;
}

/* gets the square root nSquare */
int getSqrRt(int nSquare)
{
	int nTest;
	for(nTest = 0 ; nTest < 20 ; nTest ++)
	{
		if(nSquare == nTest * nTest)
			return nTest;
	}
	return 0;
}

int main()
{
	/* variable declaration */
	int nNum1, nNum2, nSquare, nSqrRt, nPrfctSqr;

	/* asks for two input numbers */
	printf("Please input number for Num1: ");
	scanf("%d", &nNum1);
	printf("\nPlease input number for Num2: ");
	scanf("%d", &nNum2);
		
	/* stores the values of the functons */
	nSquare = getSquare(nNum1, nNum2);
	nPrfctSqr = getPrfctSqr(nSquare);
	nSqrRt = getSqrRt(nSquare);
	
	/* displays the results */
	printf("\nThe sum of the squares of %d and %d is %d\n",
	       nNum1, nNum2, nSquare);

	/* checks whether the integers can form a Pythagorean Triple or not */	
	if(nPrfctSqr == 1)
		printf("\n%d, %d, and %d CAN form a Pythagorean Triple.\n",
		       nNum1, nNum2, nSqrRt);
	else
		printf("\nThe numbers %d and %d CANNOT help form a Pythagorean Triple.\n",
		       nNum1, nNum2);	      
	
	return 0;
}
