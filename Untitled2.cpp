#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, nBase, nExp, nExp1;
    float fBase1, fResult=1;
    
    printf("Input a base value: ");
    scanf("%d", &nBase);
    
    printf("Input exponent: ");
    scanf("%d", &nExp);
    
    fBase1 = nBase;
    
    if(nExp < 0)
    {
      fBase1 = 1 / fBase1;
      nExp1 = -nExp;
    }

    for(i =0; i < nExp1; i++)
          fResult *= fBase1;
    
    printf("%d raised to %d is %.3f\n", nBase, nExp, fResult);
    
    system("pause");
    return 0;
} 
