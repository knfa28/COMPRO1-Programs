#include<stdio.h>

void hailstones( int n )
{
   int nCnt = 2;

   printf("%d\t", n );
   do
   {
      if( n == 1 )
         printf("1\t");
      else if( n % 2 == 0 )
         printf("%d\t", n /= 2 );
      else printf("%d\t", n = 3 * n + 1 );
      
      if( nCnt % 6 == 0 )
         printf("\n");
      nCnt++;
   }while( n != 1 );
}

int main()
{
   int nInput;

   printf("Enter input: ");
   scanf("%d", &nInput);

   hailstones(nInput);

   return 0;
}

