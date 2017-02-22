/********************************************************************************
Program name: Lesson 5 exercise

Programmed by: Kurt Aquino
Last edited on: 06/19/2013

This program will
********************************************************************************/

#include<stdio.h>

int main()
{
    /*variable declaration*/
    int nNum1, nNum2;

    /*displaying results*/      
    for( nNum1 = -10; nNum1 <= 10; nNum1++ )
    {
    	for( nNum2 = -10; nNum2 <= 10; nNum2++ )
    	{
    		if( 6 * nNum1 + 9 * nNum2 > 69 )
    		   printf("%d and %d\n", nNum1, nNum2);
    	}

    }
    
   return 0;
}
