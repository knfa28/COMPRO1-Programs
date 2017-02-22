/*******************************************************************************
Program name: Chapter 3 Exercise 4

Programmed by: Kurt Aquino
Section: S21A

Last edited on: 06/20/2013

This program will reverse an input of a three digit number, while retaining
it as a whole.
*******************************************************************************/

#include<stdio.h>

int main()
{
	/* variable declaration */
    int nNum, nRev, nOne, nTen, nHun;
	
	/* asks for user input */
	printf("Please input a three digit number: ");
	scanf("%d", &nNum);
	
	/* gets the values of the three digit number */
	nHun = nNum / 100;
	nTen = nNum % 100 / 10;
	nOne = nNum % 100 % 10;
	
	/* reverses the order of the three digit number */
	nRev = nOne * 100 + nTen * 10 + nHun;
	
	/* displays result */
	printf("\nThe reversed number of %d is %03d\n", nNum, nRev);
	
	return 0;
}
