#include<stdio.h>
#include<stdlib.h>

void highlow(int *pHigh, int *pLow)
{
     int nInput;
     
     printf("Enter a number: ");
     scanf("%d", &nInput);
     *pHigh = nInput;
     *pLow = nInput;    
     
     
 
     while(nInput != -999)
     {
         printf("Enter a number: ");
         scanf("%d", &nInput);
         if(nInput > *pHigh)
             *pHigh = nInput;
         else if(nInput < *pLow)
             *pLow = nInput;
     }
}

int  main()
{
    int nHigh, nLow;

    highlow(&nHigh, &nLow);
    printf("Highest: %d\n"
           "Lowest: %d\n",
           nHigh, nLow);
           
    system("pause");
    return 0;
}
