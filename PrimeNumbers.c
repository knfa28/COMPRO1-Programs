/*******************************************************************************
Program name: Prime numbers

Programmed by: Kurt Aquino

Last edited on: 06/24/2013

*******************************************************************************/

#include<stdio.h>

int main ()    
{    
  /* variable declaration */
  int i=2, nNum, nCheck=0;
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
	else if(nNum == 1)
		printf("Please input a positive number other than 1: ");
}while(nNum <= 0 || nNum ==1);
  
/* Tests if inputed value is divisible by numbers less than itself */

do{
	if (nNum % i == 0)    
		nCheck = 1; 
    i++;  
}while(i < nNum/2);
  
if(nCheck == 0)
	printf ("\n%d is a PRIME number\n", nNum);
else
	printf("\n%d is a COMPOSITE number\n", nNum);    
system("pause");
return 0;    
}    
