/*******************************************************************************
Program name: Commas

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 08/12/2013

This program will ask the user for a number then displays it with commas.
*******************************************************************************/

#include<stdio.h>

/*gets the power of the number with base 1000*/
int getPow(int *nNum)
{
	/*variable declaration*/
	int nPow = 1,  /*initial count of the power*/
		nCtr;      /*counter variable*/
	
	/*multiplies the power by 1000 nNum times*/ 
	for(nCtr = 1; nCtr <= *nNum; nCtr++)
		nPow *= 1000;
	
	/*decrements nNum for the second iteration*/	
	(*nNum)--;
	
	/*returns the value of the power*/
	return nPow;	
}

int main()
{
	/*variable declaration*/
	int nNum,            /*stores user input*/
	    nTemp, nTemp2,   /*temporary storage variables*/   
		nCnt = 0,        /*initial count of the power*/
		nCtr,            /*counter variable*/
		nPow;            /*stores the value of the power*/
	
	/*asks for user input*/
	printf("Input any number: ");
	scanf("%d", &nNum);
	
	/*if the number is less than 1000*/
	if(nNum / 1000 == 0)
		printf("%d", nNum);
		
	else
	{
		/*temporarily stores the input value*/
		nTemp = nNum;

		/*calculates for the value of power with base 1000*/
		do
		{
			nTemp /= 1000;
			nCnt++;
		}while(nTemp >= 1000);
		
		/*temporarily stores the value of power*/
		nTemp2 = nCnt;
		
		/*gets the value of the power*/	
		nPow = getPow(&nTemp2);
		
		/*displays the digits with commas*/
		for(nCtr = 1; nCtr <= nCnt; nCtr++)
		{
			/*displays a comma after every power with base 1000*/	
			if(nCtr == 1)
				printf("%d,", nNum / nPow);
			else
				printf("%03d,", nNum / nPow);
			
			/*gets the new value of the given number by getting its
			  remainder when divided by the current power with base 1000*/
			nNum %= nPow;
			
			/*gets the new value of the power by decreasing it by 1 exponent*/
			nPow /= 1000;
	    }
	    
	    /*displays the last 3 digits*/
		printf("%03d", nNum % 1000);
	}	
	return 0;
}
