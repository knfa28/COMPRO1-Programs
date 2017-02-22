/*******************************************************************************
Program Name: Multiplication Table Generator

Created by: Ryan Austin Fernandez
Last Edited: June 19, 2013

This program will ask the user for the number of rows and columns. It will then
print a multiplication table with the given specifications.
*******************************************************************************/

#include <stdio.h>
#include <string.h>

typedef int  arrMult[101][101];/*declares a 101 by 101 array of integers*/
typedef char String[21];/*declares a 20-character string type*/

/*
   gets a non-negative input integer less than 100
*/
int getInput( void )
{
   int nNum;/*container variable*/
   
   do
   {
   	scanf("%d", &nNum );
   	
   	if( nNum < 0)/*if number is negative*/
   	   printf("\nPlease enter a non-negative number: ");
   	else if( nNum > 100 )/*while number is greater than 100*/
   	   printf("Please enter a number below 100: ");
   }while( nNum < 0 || nNum > 100 );/*while number is negative*/
	
	return nNum;/*returns input*/
}

/*
   returns the product of two integers
   num1,
   num2 - the factors to be multiplied
*/
int getProd( int num1, int num2 )
{
	return ( num1 * num2 );/*returns product*/
}

/*
   creates a multiplication table given the specifications
   nRows - number of rows
   nCols - number of columns
*/
void createMultTable( arrMult aMTable, int nRows, int nCols )
{
	int i,/*row index*/
	    j;/*column index*/
	
	for( i = 0; i <= nRows; i++ )
	{
		for( j = 0; j <= nCols; j++ )
		{
			aMTable[i][j] = getProd( i, j );/*an element is the product of its 
			                                  indices*/
		}
	}
}

/*
   displays a multiplication table
   aMTable - table to display
   nRows - number of rows
   nCols - number of columns
*/
void displayMultTable( arrMult aMTable, int nRows, int nCols )
{
	int i,/*row index*/
	    j;/*column index*/
	
	printf("\t");/*initial space*/
	for( i = 1; i <= nCols; i++ )/*prints column headers*/
	   printf("%d\t", i );
	printf("\n");
	
	for ( i = 1; i <= nRows; i++ )/*starts from one because there will be a line
	                                of zeros on the left and top due to the al-
									goritm used in the creatMultTable function*/
	{
		printf("%d\t", i );/*prints row headers*/
		for( j = 1; j <= nCols; j++ )
		{
			printf("%d\t", aMTable[i][j] );/*prints actual elements*/
		}
		printf("\n");
	}
}

int main()
{
    /*variable declaration*/
    int     nRows,     /*number of rows*/
	        nCols;     /*number of columns*/
    arrMult aMTable;   /*array containing multiplication table*/
    String  strDisplay;/*string indicating rows or columns*/
    
    /*asking for user input*/
    strcpy( strDisplay, "rows");
    printf("How many %s? ", strDisplay);
    nRows = getInput();
    
    strcpy( strDisplay, "columns");
    printf("\nHow many %s? ", strDisplay);
    nCols = getInput();
    
    printf("\n\n");
    
    /*calls function to create table*/
    createMultTable( aMTable, nRows, nCols );
	
    /*displaying results*/      
    displayMultTable( aMTable, nRows, nCols );
    
   return 0;
}
