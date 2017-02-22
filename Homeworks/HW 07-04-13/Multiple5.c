/*******************************************************************************
Program name: Multipe of 5

Programmed by: Kurt Aquino
Section: S21A

Last edited on: 07/02/2013

This program will ask the user for a positive integer and then checks if it is 
a multiple of 5
*******************************************************************************/
#include<stdio.h>

int main()
{
	/* variable declaration */
	int nNum;
	
	/* asks for user input */
	printf("Input: ");
    scanf("%d", &nNum);
    
    /* checks if input value is a multiple of 5 */
    if (nNum % 5 == 0)
	   printf("\nIt's a multiple of 5");
	else
	   printf("\nIt's NOT a multiple of 5");
	   
    return 0;
}
