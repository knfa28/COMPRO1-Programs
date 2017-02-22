/*******************************************************************************
Program name: Palindrome

Progammed by: Kurt Aquino
Section: S21A

Last edited on: 08/06/2013

This program will ask the user for a number then check if
it is a palindrome or not.
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main ()    
{    
	int nNum,       /*stores the input of the user*/
        nTemp,      /*temporary storage of the input number*/
        r,          /*stores the remainder*/
        nSum = 0;   /*stores the value of the reversed number*/

    /*asks for user input*/
    printf("Enter a number: ");
    scanf("%d", &nNum);
    
    /*reverses the values of the number to check if it is still the same*/
    
    /*this function will divide the given number by
      ten after performing the indicated operations*/
    for(nTemp = nNum; nNum != 0; nNum /= 10)
	{
         r = nNum % 10;        /*gets the remainder of the given
                                 input when divided by 10*/
         nSum = nSum * 10 + r; /*reverses the given number by multiplying
                                 the stored value by 10 then adding it to 
                                 the remainder*/
    }
    
    /*if the reversed number is equal to the given number*/
    if(nTemp == nSum)
         printf("\n%d IS a palindrome\n",nTemp);
    else
         printf("\%d is NOT a palindrome\n",nTemp);
     
    system("pause");
    return 0;
}
