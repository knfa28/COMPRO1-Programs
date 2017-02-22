#include<stdio.h>
#include<stdlib.h>

void getFactor5()
{
     int nCtr, i = 5;
     
     for(nCtr = 1; nCtr <= 25; nCtr++) 
         printf("%d\n", i * nCtr);     
}

int main()
{
    getFactor5();
    
    system("pause");
    return 0;
}
