/*******************************************************************************
Program name: Commas

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 08/12/2013

This program will ask the user for a number then displays it with commas.
*******************************************************************************/

#include<stdio.h>

int getPow(int *nNum)
{
	int nPow = 1, nCtr;
	
	for(nCtr = 1; nCtr <= *nNum; nCtr++)
		nPow *= 1000;
		
	(*nNum)--;
	return nPow;	
}

int main()
{
	int nNum,
	    nTemp, nTemp2, 
		nCnt = 0,
		nCtr,
		nPow;
	
	printf("Input any number: ");
	scanf("%d", &nNum);
	
	if(nNum / 1000 == 0)
		printf("%d", nNum);

	else
	{
		nTemp = nNum;

		do
		{
			nTemp /= 1000;
			nCnt++;
		}while(nTemp >= 1000);
		
		nTemp2 = nCnt;
		
		for(nCtr = 1; nCtr <= nCnt; nCtr++)
		{		
			nPow = getPow(&nTemp2);
			printf("%d,", nNum / nPow);
			nNum = nNum % (nNum / nPow * nPow);
	    }
		printf("%d", nNum % 1000);
	}	
	return 0;
}
