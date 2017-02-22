#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, nInput;    
    
    printf("Enter a number: ");
    scanf("%d", &nInput); 
    
    for(i = 1; i <= nInput; i++)
    {
      if(nInput % i == 0)
          printf("%d\n", i);
    }
    
    system("pause");
    return 0;
}
