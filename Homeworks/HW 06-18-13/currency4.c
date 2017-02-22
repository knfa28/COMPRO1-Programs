/*******************************************************************************
Program Name: Currency 4
        
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

/* converts and stores the peso equivalent */
void convert(float fPeso, float *pUSD, float *pEuro, float *pJPY,
             float *pGBP, float *pCHF)
{
	*pUSD = fPeso * 0.02323;
	*pEuro = fPeso * 0.01740;
	*pJPY = fPeso * 2.21785;
	*pGBP = fPeso * 0.01481;
	*pCHF = fPeso * 0.02136;
}

/* displays result */
void displayResult(float fPeso, float fUSD, float fEuro,
                   float fJPY, float fGBP, float fCHF)
{     
     printf("Converting... Done!\n"
            "In USD: %c%.2f\n"
            "In Euro: %c%.2f\n"
            "In JPY: %c%.2f\n"
            "In GBP: %c%.2f\n"
            "In CHF: %c%.2f\n"
            "************************************\n", /* display closing design */
            36, fUSD,
            238, fEuro,
            157, fJPY,
            156, fGBP,
            159, fCHF);
}

int main() 
{
    /* variable declaration */
    float fPeso, fUSD, fEuro, fJPY, fGBP, fCHF;
    fPeso = getInput();
    
    /* calls the function to convert peso value */
    convert(fPeso, &fUSD, &fEuro, &fJPY, &fGBP, &fCHF);
    
    /* calls the function to display the results */
    displayResult(fPeso, fUSD, fEuro, fJPY, fGBP, fCHF);
    
    system("pause");
    return 0;
}
