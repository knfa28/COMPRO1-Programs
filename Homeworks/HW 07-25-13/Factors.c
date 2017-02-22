/*******************************************************************************
Program name: Factors

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 07/23/2013

This program will ask the user for a number then get its factors
*******************************************************************************/

#include<stdio.h>

main()
{
	/*variable declaration*/
	int x = 1,    /*stores the value of the factors*/
	    nInput;   /*user input*/
	    
	/*asks for user input*/
	printf("Input: ");
	scanf("%d", &nInput);
	
	printf("Factors are ");
	
	/*loops the statements while x is less than nInput*/
	while(x <= nInput)
	{
		if(nInput % x == 0)   /*checks if nInput is divisible by x*/
		    printf("%d ", x); /*displays the value of x*/
		
		x++; /*increments the value of x*/
	}
	printf("\n");
	system("pause");
	return 0;
}
