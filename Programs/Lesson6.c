/********************************************************************************
Program name: Lesson 6 exercise

Programmed by: Kurt Aquino
Last edited on: 06/19/2013

This program will
********************************************************************************/

#include<stdio.h>

/* computes for the value of Num 2*/
float getNum2(float fNum1)
{
	float fNum2;
	fNum2 = ( 69 - 6 * fNum1 ) / 9;
	return fNum2;
}

int main ()
{
	/* variable declaration */
	float fNum1, fNum2;
	
	/* asks for user input */
	printf("Input Num1: ");
	scanf("%f", &fNum1);
	
	/* calls and stores the result of the function getNum2 */
	fNum2 = getNum2(fNum1);
	
	/* displays result */ 
	printf("Num 2 should be greater than %.2f", fNum2);
	
	return 0;
}

