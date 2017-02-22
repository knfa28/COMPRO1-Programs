#include <stdio.h>

#define GIFT  10000.00
#define PEEPS 10

int main()
{
   int   nDrop;
   float fAdd, fFinal;   
   
   printf("Enter number of persons who dropped out: ");
   scanf("%d", &nDrop);

   printf("Original contribution per person: PhP%.2f\n",    
          GIFT / PEEPS);

   fFinal = GIFT / (PEEPS - nDrop);
   fAdd = fFinal - GIFT / PEEPS ;
 
   printf("Additional contribution per person: PhP%.2f\n", fAdd);
   printf("Computed contribution per person: PhP%.2f\n", fFinal);
 
   return 0;
}

