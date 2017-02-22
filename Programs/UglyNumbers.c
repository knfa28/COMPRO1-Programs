/*******************************************************************************
Program name: Ugly Numbers

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 08/12/2013

This program will ask the user for a number n then displys the nth ugly number.
*******************************************************************************/

# include<stdio.h>
 
/*checks if a number is ugly or not */
int isUgly(int nNum)
{
	/*if the number is only divisible by either 2, 3, or 5*/
	if(nNum % 2 == 0 || nNum % 3 == 0|| nNum % 5 == 0) 
		return 1;
	else
		return 0;
}    
 
/*function to get the nth ugly number*/
int getUgly(int nNum)
{
	int i = 1,  /*initial count of the integers to be checked*/
	nCtr = 1;   /*initial count of the ugly numbers*/
 
	/*checks for all numbers until ugly count is equal to nInput*/
	while (nCtr < nNum)
	{
		i++;      
    	if (isUgly(i))
      		nCtr++; 
	}
	return i;
}
 
int main()
{
	/*variable declaration*/
    int nInput;
    
    /*asks for user input*/
    printf("Enter a number: ");
    scanf("%d", &nInput);
	
	/*displays results*/
    printf("Output: %d ", getUgly(nInput));

    return 0;
}
