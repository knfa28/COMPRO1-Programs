#include <stdio.h>

#define PI  3.1416

void stars()
{
   printf("*************************************\n");
}

float getInput()
{
    float fValue;
   
    printf("Enter measurement: ");
    scanf("%f", &fValue);
 
    return fValue;  
}

int computeNumCoins(float fLength, float fWidth, float fDiam)
{   int nRow, nCol;

    nRow = fLength / fDiam;
    nCol = fWidth / fDiam;

    return (nRow * nCol);
}

float computeOpenArea(float fLength, float fWidth, 
                      float fDiam, int nCoins)
{   float fAreaT, fAreaC;

    fAreaT = fLength * fWidth;
    fAreaC = PI * fDiam / 2 * fDiam / 2;

    return (fAreaT - fAreaC * nCoins);
}

int main()
{
   float  fLength, fWidth, fDiam;
   int    nCoins;

   stars();

   printf("\nTissue Dimension:\n");
   fLength = getInput();
   fWidth = getInput();

   printf("\nCoin Diameter:\n");
   fDiam = getInput();

   printf("Tissue is %.2f x %.2f, Coin is %.2f diameter\n",
          fLength, fWidth, fDiam);

   nCoins = computeNumCoins(fLength, fWidth, fDiam);
   printf("%d coins can fit in the tissue\n", nCoins);
   printf("Open area is %.2f\n", 
          computeOpenArea(fLength, fWidth, fDiam, nCoins)); 

   stars();
   return 0;
}
