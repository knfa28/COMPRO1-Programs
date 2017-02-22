/*******************************************************************************
Program name: Prime numbers

Programmed by: Kurt Aquino

Last edited on: 06/24/2013

*******************************************************************************/

#include<stdio.h>

int main ()    
{    
  /* variable declaration */
  int nNum, nCheck, nCount1, nCount2;
  char cNull;     
  
  /*asks for user input */
  printf("Input any number: ");    
  
/* checks whether inputed value is valid or not */
do
{
	scanf("%d%c", &nNum, &cNull);
	if (nNum <= 0) 
		/* displays error message */
		printf("Please input a positive number: ");
}while(nNum <= 0);

/* Displays prime numbers between 2 tand the given number */
for(nCount1 = 2; nCount1 < nNum; nCount1++)
{
	nCheck = 0;
	for(nCount2 = 2; nCount2 <= nCount1/2; nCount2++)
 	{
		if(nCount1 % nCount2 == 0)
 		{
			nCheck = 1;
			break;
		}
 	}
	if(nCheck == 0)
	printf("%d\n",nCount1);
}
 	
return 0;    
}    
