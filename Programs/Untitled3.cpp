#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nStart, nEnd, nStartdays, nDays=0;
    
    printf("Enter start month: ");
    scanf("%d", &nStart);
    
    printf("Enter end month: ");
    scanf("%d", &nEnd);

while(nStart <= nEnd)    
{    
    switch(nStart)
    {
       case 2: nStartdays += 28; break;
       case 4:
       case 6:
       case 9: 
       case 11: nStartdays = +30; break;
       default: nStartdays = +31;
    }
    nStart ++;
}
    
    switch(nEnd)
    {

    }
     
     if(nStart != nEnd)
     {
         nDays = nStartdays + nEnddays;
         printf("Total number of days is: %d\n", nDays);
     }
     else
         printf("Total number of days is: %d\n", nDays); 
             
    
    system("pause");
    return 0;
} 
