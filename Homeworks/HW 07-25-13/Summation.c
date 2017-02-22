/*******************************************************************************
Program name: Summation

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 07/23/2013

This program will ask the user for a number then gets its summation
*******************************************************************************/

#include<stdio.h>

main()
{
	/*variable declaration*/
	int x = 0,    /*stores the value of the summation*/
	    nInput;   /*user input*/
	    
	/*asks for user input*/
	printf("Input: ");
	scanf("%d", &nInput);
	
	/*loops the statements while nInput is greater than zero*/
	while (nInput > 0)
	{
		x += nInput; /*multiplies the current value of x to nInput*/
		nInput--;	 /*decrements nInput*/	
	}
	    
	/*displays results*/
	printf("Output: %d\n", x);
	
	system("pause");
	return 0;
}

