
/*******************************************************************************
Program Name: 69-ers

Created by: Ryan Austin Fernandez
Last Edited: June 17, 2013

This program will display 69 AS MANY TIMES AS YOU WISH and insult you if you do 
not wish to display the number. This program will enhance your quality of living, 
and if you disagree, you are entitled to your own opinion, but mine is that you
are a miserable human being and you have my sincerest pity, sympathy, empathy, 
and priority spot in my ignore list. Nah, just kidding... about the pity, 
sympathy, and empathy part. No seriously, if you input zero, you suck...

Really...
*******************************************************************************/

#include <stdio.h>
#include <string.h>

/*declares string*/
typedef char String[50];

/*this functions takes a counter as a parameter and displays the magic number that
many times*/
void displaySixtyNine( int nCtr )
{
	int i;
	
	for( i = 0; i < nCtr; i++ )
	{
		printf("6666666666    9999999999\n");
		printf("6666666666    9999999999\n");
		printf("66            99      99\n");
		printf("66            99      99\n");
		printf("6666666666    9999999999\n");
		printf("6666666666    9999999999\n");
		printf("66      66            99\n");
		printf("66      66            99\n");
		printf("6666666666    9999999999\n");
		printf("6666666666    9999999999\n");
		printf("\n\n");
	}
}

/*insults bitches*/
void displayInsult()
{
	printf("FFFFF U   U CCCCC K   K        Y   Y OOOOO U   U   !!! \n");
	printf("F     U   U C     K  K          YYY  O   O U   U   !!! \n");
	printf("FFFFF U   U C     KKKK           Y   O   O U   U   !!! \n");
	printf("F     U   U C     K  K           Y   O   O U   U       \n");
	printf("F     UUUUU CCCCC K   K          Y   OOOOO UUUUU   !!! \n");
	printf("\n\nbitch...\n\n");
}

/*this function returns an uppercase or lowercase 'Y' or 'N'. The mechanism ensures
that the input is uppercase or lowercase 'Y' or 'N'*/
char YesNo(void)
{
	char cCont, cNull;
	
	do
	{
	   scanf("%c%c", &cCont, &cNull );
	   
	   if( cCont != 'y' && cCont != 'Y' && cCont != 'N' && cCont != 'n' )
	      printf("Please enter valid input(Y/N): ");
	}while( cCont != 'y' && cCont != 'Y' && cCont != 'N' && cCont != 'n' );
	
	return cCont;
}

int main()
{
    /*variable declaration*/
    int nCtr/*is the number of times the magic number is to be displayed*/;
	int nAgain = -1 /*counts the number of iterations of the program*/;
    char cCont, cNull /*takes a newline character to free keyboard buffer*/;
    String strAgain = "\0";
    
    /*asking for user input*/
    do
    {
       /*increments iteration counter*/
       nAgain++;
	   	
	   	/*includes "more" in the prompt if program has run more than once*/
	   if( nAgain > 0 )
	      strcpy( strAgain, " more");	
	      
	   /*asks user how many times the magic number is to be displayed*/
       printf("\nHow many%s times would you like to display the magic number? ", strAgain);
       
       /*ensures that user inputs a positive number*/
       do
       {
    	   scanf("%d%c", &nCtr, &cNull);
    	
    	   if( nCtr < 0 )/*if negative*/
    	      /*asks the user to enter a non-negative number*/
    	      printf("%s%s", "\nPlease enter a positive number so ", 
		             "the magic number can be displayed properly: ");
		   else if( nCtr == 0 )
		   {
		   	  /*calls function to insult user for being a prude/killjoy. Function is called
			  because user is too shitty to be insulted in the main function, dammit. 
			  Program then terminates.*/
		      displayInsult();
		      cCont = 'n';
	       }
	    
       }while( nCtr < 0)/*repeats if nCtr is negative*/;
    
       /*passes the user-inputted counter to the display function*/
       displaySixtyNine( nCtr );
    
       /*asks user if they would like to see the numerical messianic revelation some more*/
       if( nCtr > 0 )/*if they didn't input zero*/
       {
          printf("Would you like to display the magic number some more(Y/N)? ");
          
          /*assigns the returned char from the called YesNo function to cCont*/
          cCont = YesNo();
       }
       
    }while( cCont != 'n' && cCont != 'N' );  /*repeats while user does not input 'n' or 'N'*/
    
   return 0;
}
