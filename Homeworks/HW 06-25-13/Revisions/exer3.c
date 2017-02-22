/*******************************************************************************
Program name: Chapter 3 Exercise 3

Programmed by: Kurt Aquino
Section: S21A

Last edited on: 06/20/2013

This program will break down an input into the smallest number of bills and
coins that would add up to that amount.
*******************************************************************************/

#include<stdio.h>

int main()
{
	/* variable declaration */
    int nPeso, n1000, n500, n200, n100, n50, n20, n10, n5, n1;
	/* asks for user input */
	printf("Input a value in pesos: ");
	scanf("%d", &nPeso);
	
	/* calculates the number of bills and coins needed */
	n1000 = nPeso / 1000; /* gets the smallest number of 1000 peso bills */
	n500 = nPeso % 1000 / 500; /* gets the smallest number of 500 peso bills */	
	n200 = nPeso % 500 / 200; /* gets the smallest number of 200 peso bills */	
	n100 = nPeso % 500 % 200 / 100; /* gets the smallest number of 100 peso bills */
	n50 = nPeso % 500 % 200 % 100 / 50; /* gets the smallest number of 50 peso bills */	
	n20 = nPeso % 500 % 200 % 100 % 50 / 20; /* gets the smallest number of 20 peso bills */	
	n10 = nPeso % 500 % 200 % 100 % 50 % 20 / 10; /* gets the smallest number of 10 peso coins */	
	n5 = nPeso %  500 % 200 % 100 % 50 % 20 % 10 / 5; /* gets the smallest number of 5 peso coins */
	n1 = nPeso % 500 % 200 % 100 % 50 % 20 % 10 % 5; /* gets the smallest number of 1 peso coins */
	
	/* displays results */
	printf("\nPhp%d can be divided into:\n\n"
	       "%d 1000 peso bills\n"
	       "%d 500 peso bills\n"
	       "%d 200 peso bills\n"
		   "%d 100 peso bills\n"
		   "%d 50 peso bills\n"
		   "%d 20 peso bills\n"
		   "%d 10 peso coins\n"
		   "%d 5 peso coins\n"
		   "%d 1 peso coins\n", 
		   nPeso, n1000, n500, n200, n100, n50, n20, n10, n5, n1);
	       
	system("pause");
    return 0;
}
