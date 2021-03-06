/*******************************************************************************
Program Name: Currency 3
        
Programmed by: Kurt Aquino
Section: S21A

Last Edited on: 06/17/2013
*******************************************************************************/

#include <stdio.h>

/* asks for user input */
float getInput()
{
     float fPeso;
     printf("**********CURRENCY CONVERT**********\n"
            "Please input an amount in Peso: \n");
     scanf("%f", &fPeso);
     return fPeso;
}
     
/* converts the peso value */
float convert(float fPeso,float fRate)
{
      float fMoney;
      fMoney = fPeso * fRate;
      return fMoney;
}

/* displays result */
void displayResult(float fPeso, float fUSD, float fEuro,float fJPY,
                   float fGBP, float fCHF)
{ 
	 printf("Converting... Done!\n"
            "In USD: %c%.2f\n"
            "In Euro: %c%.2f\n"
            "In JPY: %c%.2f\n"
            "In GBP: %c%.2f\n"
            "In CHF: %c%.2f\n"
            "************************************\n", /* displays closing design */
            36, convert(fPeso, fUSD),
            238, convert(fPeso, fEuro),
            157, convert(fPeso, fJPY),
            156, convert(fPeso, fGBP),
            159, convert(fPeso, fCHF));
}

int main()
{
    /* variable declaration */
	float fPeso, fUSD, fEuro, fJPY, fGBP, fCHF;
	fPeso = getInput();
	
	/* defines peso rate for each currency */
	fUSD = 0.02323;
    fEuro = 0.01740;
    fJPY = 2.21785;
    fGBP = 0.01481;
    fCHF = 0.02136;
    
    /* calls the function to display the results */
    displayResult(fPeso,fUSD,fEuro,fJPY,fGBP,fCHF);
    
    system("pause");
    return 0;
}
