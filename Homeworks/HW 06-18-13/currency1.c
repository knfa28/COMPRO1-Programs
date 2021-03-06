/*******************************************************************************
Program Name: Currency 1
        
Programmed by: Kurt Aquino
Section: S21A

Last Edited on: 06/17/2013
*******************************************************************************/

#include <stdio.h>

int main()
{
    /* variable declaration */
    float fPeso;
    
    /* display intro design */
    printf("**********CURRENCY CONVERT**********\n"
           "Please input an amount in peso: \n"); /* asks for user input */
    scanf("%f", &fPeso);

    /* displays results */
    printf("Converting... Done!\n"
           "In US Dollars: %c%.2f\n"
           "In Euro: %c%.2f\n"
           "In Japanese Yen: %c%.2f\n"
           "In British Pound: %c%.2f\n"
           "In Swiss Franc: %c%.2f\n"
           "Thank You!\n"
           "************************************\n", /* display closing design */
           36, fPeso * 0.02323,
           238, fPeso * 0.01740,
           157, fPeso * 2.21785,
           156, fPeso * 0.01481,
           159, fPeso * 0.02136);

    system("pause");
    return 0; 
}

