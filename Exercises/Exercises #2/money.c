#include <stdio.h>

int main()
{
   int nAmt,
       n1000, n500, n200, n100, n50, n20, n10, n5, n1;

   printf("Enter an integer amount : ");
   scanf("%d", &nAmt);

   n1000 = nAmt / 1000;
   nAmt = nAmt % 1000;  	/* nAmt %= 1000; */
				/* nAmt = nAmt - n1000 * 1000; */
   n500 = nAmt / 500;   
   n200 = nAmt % 500 / 200;
   n100 = nAmt % 500 % 200 / 100;
   n50 = nAmt % 500 % 200 % 100 / 50;
   n20 = nAmt % 500 % 200 % 100 % 50 / 20;
   n10 = nAmt % 500 % 200 % 100 % 50 % 20 / 10;
   n5 = nAmt % 500 % 200 % 100 % 50 % 20 % 10 / 5;
   n1 = nAmt % 500 % 200 % 100 % 50 % 20 % 10 % 5;

   printf("The following bills and coins sum up to PhP%d:\n",
          nAmt + n1000 * 1000);
   printf("   %d   P1000\n", n1000); 
   printf("   %d   P 500\n", n500); 
   printf("   %d   P 200\n", n200); 
   printf("   %d   P 100\n", n100); 
   printf("   %d   P  50\n", n50); 
   printf("   %d   P  20\n", n20); 
   printf("   %d   P  10\n", n10); 
   printf("   %d   P   5\n", n5); 
   printf("   %d   P   1\n", n1); 

   return 0;
}
