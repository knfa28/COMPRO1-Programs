/*******************************************************************************
Program Name: Pattern Display

Last Edited: August 8, 2013

This program will display a pattern given the number of lines, which is also the
line width.
*******************************************************************************/

#include <stdio.h>

/*
   displays a given character a given number of times
   c      - character to display
   nCount - number of times to display it
*/
void display( char c, int nCount )
{
	/*count id decremented until it is zero*/
	for( nCount; nCount > 0; nCount-- )
	   printf("%c", c );
}

/*
   displays the digits in succession a certain number of times starting from a 
   value in an address while updating the number in the passed address.
   pNum   - points to the number
   nCount - number of digits to display
*/
void displayNumbers( int *pNum, int nCount )
{
	/*nCount is decremented until it reaches zero. For every iteration, the 
	  value in pNum is incremented*/
	for( nCount; nCount > 0; nCount--, (*pNum)++ )
	   printf("%d", *pNum % 10 );
}

/*
   displays the specified pattern
   n - number of lines and line width
*/
void displayPattern( int n )
{
	int nLine,   /*line number*/
	    nNum,    /*current number whose ones digit is to be displayed*/
	    nX,      /*number of X's to be displayed*/
	    nDigits; /*number of digits to be displayed*/
	     
    nNum = 1;    /*the first digit to be displayed is 1*/
    nX = n;      /*for the first line, n number of X's are to be displayed*/
    nDigits = 0; /*for the first line, zero digits are to be displayed*/
    
    for( nLine = 1; nLine <= n; nLine++ )
    {
    	/*displays a line*/
    	displayNumbers( &nNum, nDigits );
    	display( 'X', nX );
    	displayNumbers( &nNum, nDigits );
    	printf("\n");
    	
    	/*for the first half of lines*/
    	if( nLine < ( n + 1 ) / 2 )
    	{
    		/*2 less X's are to be displayed*/
    		nX -= 2;
    		
    		/*1 more digit is to be displayed per side*/
    		nDigits++;
    	}
    	else /*for the second half of lines*/
    	{
    		/*2 more X's are to be displayed*/
    		nX += 2;
    		
    		/*1 less digit is to be displayed per side*/
    		nDigits--;
    	}
    }
}

int main()
{
    /*variable declaration*/
    int n; /*number of lines and line width*/

    /*asking for user input*/
    printf("Enter n: ");
    scanf("%d", &n );

    /*calls function*/
    displayPattern( n );

   return 0;
}

