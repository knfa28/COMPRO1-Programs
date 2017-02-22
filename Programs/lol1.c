#include<stdio.h>

void display( char c, int n )
{
   for( n; n > 0; n-- )
      printf("%c", c );
}

void dispStar( int n )
{
   int nLine,
         nMid = ( n + 1 ) / 2,
         nInside = ( n - 3 ) / 2,
         nOutside = 0;

   for( nLine = 1; nLine <= n; nLine++ )
   {
      if( nLine == nMid )
      {
         display( '*', n );
         nOutside--;
         nInside++;
      }
      else
      {
         display( '0', nOutside );
         printf("*");
         display( '0', nInside );
         printf("*");
         display( '0', nInside );
         printf("*");
         display( '0', nOutside );
         
         if( nLine < nMid )
         {
            nOutside++;
            nInside--;
         }
         else
         {
            nOutside--;
            nInside++;
         }
      }
      printf("\n");
   }
}

int main()
{
   int n;
 
   printf("Enter n: ");
   scanf("%d", &n );

   dispStar(n);

   return 0;
}

