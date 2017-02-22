#include<stdio.h>

void stars()
{
     printf("*************************************************\n");
}

float getInput()
{
      float fValue;
      printf("Enter measurement :");
      scanf("%f", &fValue);
      return fValue;
}

int computeNumCoins(float fLength, float fWidth, float fDiameter)
{
    int nRow, nCol;
    
    nRow = fLength / fDiameter;
    nCol = fWidth / fDiameter;
    
    return (nRow * nCol);    
}

float computeOpenArea(float fLength, float fWidth, float fDiameter, int nCoins)
{
      float fAreaT, fAreaC;
      
      fAreaT = fLength * fWidth;
      fAreaC = 3.14 * fDiameter/2 * fDiameter/2;
      
      return (fAreaT - fAreaC * nCoins);
}
int main()
{
    float fLength, fWidth, fDiameter;
    int nCoins;
    
    stars();
    
    printf("\nTissue Dimension:\n");
    
    fLength = getInput();
    fWidth = getInput();
    
	printf("\nCoin Dimension:\n");
	fDiameter = getInput();
    
	nCoins = computeNumCoins(fLength, fWidth, fDiameter);
    
    printf("%d coins can fit in the tissue\n",
           nCoins);
    printf("Open area is %.2f\n",
           computeOpenArea(fLength, fWidth,fDiameter, nCoins));
    
    stars();
    
    system("pause");
    return 0;
}
