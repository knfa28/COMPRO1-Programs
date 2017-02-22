/********************************************************************************
Program name: Lesson 4 exercise

Programmed by: Kurt Aquino
Last edited on: 06/19/2013

This program will
********************************************************************************/

#include<stdio.h>

/* computes if value is greater than 69 */ 
int getSixtyNine(int nNum1, int nNum2)
{
	if(nNum1 * 6 + nNum2 * 9 > 69)
		return 1;
	else
		return 0;
}

int main()
{
	/* variable declaration */
	int nNum1, nNum2, nResult;
	
	/* asks for two input numbers */
	printf("Please input number for Num1: ");
	scanf("%d", &nNum1);
	printf("\nPlease input number for Num2: ");
	scanf("%d", &nNum2);
	
	/* calls and stores the result of the function getSixtyNine */
    nResult = getSixtyNine(nNum1, nNum2);
	
	/* displays result */ 
	printf("\n%d", nResult);
	
	
	return 0;
}
