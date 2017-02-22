/*******************************************************************************
Program Name:
        
Programmed by: Jason Baylon
Last Edited on:
     
This program will 
*******************************************************************************/
#include <stdio.h>

int main()
{
    int nNum1, nCtr;
    
    printf("Input an integer: ");
    scanf("%d", &nNum1);
    
	for (nCtr = 1; nCtr <= nNum1; nCtr++)
	{
		printf("The ASCII equivalent of %d is %c\n", nCtr, nCtr);
	}
    
    
    system("pause");
    return 0;
}
