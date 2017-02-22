#include<stdio.h>
#include<stdlib.h>

void displayNum(int n)
{
     int nLine, nDigits;
     for(nLine=1; nLine <= n; nLine++)
     {
        for(nDigits = 1; nDigits <= nLine; nDigits++)
           printf("%d", nDigits %= 10);
           
        printf("\n");
     }
}


int main ()    
{   
    
    int n, nLine, nSpaces;
    
    printf("Input a number: ");
    scanf("%d", &n);
    
    for(nLine = 1; nLine <= n; nLine++);
    {
       for(nSpaces = 1; nSpaces <= n - nLine; nSpaces++)
          printf(" ");
       displayNum(nLine * 2 -1);
    }
    
    system("pause");
    return 0;
}
