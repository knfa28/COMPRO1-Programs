/*******************************************************************************
Program name: Chapter 3 Exercise 5

Programmed by: Kurt Aquino
Section: S21A

Last edited on: 06/20/2013

This program will calculate how much more each person will contribute for a gift
worth Php 10000.00 after an input number of people has dropped out.
*******************************************************************************/

#include<stdio.h>

int main()
{
	/* variable declaration */
	int nDrop, nPeople;
	float fAddCntrbt, fCompCntrbt;
	char cNull;
	
	/* asks for user input */
	printf("Enter the amount of people who dropped out: ");
	
	
	/* determines whether inputed value is greater than zero and less than 10 */
	do
	{
		scanf("%d%c", &nDrop, &cNull);
		
        if (nDrop <= 0 || nDrop >= 10)
        /*displays error message */
    	printf("\nPlease enter the proper amount of people who dropped out :");
    }while (nDrop <= 0 || nDrop >= 10);	
        
    /* calculates desired outputs */
	nPeople = 10 - nDrop;
	fCompCntrbt = 10000.00 / nPeople;
	fAddCntrbt = fCompCntrbt - 1000.00;

    /* displays results */
    printf("\nRemaining amount of people: %d\n"
           "Original contribution per person: Php1000.00\n"	   
           "Additional contribution per person: Php%.2f\n"
           "Computed contribution per person: Php%.2f\n",
           nPeople, fAddCntrbt, fCompCntrbt);
		        
    system("pause");
    return 0;
}
