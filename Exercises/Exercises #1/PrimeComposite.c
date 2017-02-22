#include<stdio.h>
#include<stdlib.h>

int main ()    
{    
  int i, nInput, nCheck=0;    
  
  printf("Input any number: ");    
  scanf("%d", &nInput);

   if(nInput == 1)
       printf("%d is NEITHER prime nor composite\n", nInput);
   
   else
   {
     for(i = 2; i < nInput/2; i++)
     {
	     if (nInput % i == 0)    
	   	    nCheck = 1; 
     }
  
      if(nCheck == 0)
	      printf ("\n%d is a PRIME number\n", nInput);
      else
	      printf("\n%d is a COMPOSITE number\n", nInput);    
   }
      
   system("pause");
   return 0;    
}    
