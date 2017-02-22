/*******************************************************************************
Program Name: ASCII Art
        
Programmed by: Kurt Aquino
Section: S21A

Last Edited on: 06/17/2013
*******************************************************************************/

#include <stdio.h>

/* displays the ASCII Art for K */
void displayK()
{
	printf("K   K   U   U   RRRR    TTTTT\n"
		   "K  K    U   U   R   R     T\n"
		   "KKK     U   U   RRRR      T\n"
		   "K  K    U   U   R   R     T\n"
	   	   "K   K    UUU    R   R     T\n"
		   "\n\n");
	
}

int main()
{
    /* calls the functions to display the 
	ASCII Arts for K, U, R, and T */
	for(;;)
	{
    displayK();
    } 
	   
	system("pause");   
    return 0;
}
