#include<stdio.h>
#include<stdlib.h>

int getFactorial(int nInput)
{
	int nFactorial = 1;
	
	while( nInput > 1 )
    {
    	nFactorial *= nInput;
    	nInput--;
    }
    
    return nFactorial;
}

int main()
{
   
    int nInput;    
    
    printf("Enter a number: ");
    scanf("%d", &nInput);
    
    printf("The factorial of %d is %d\n", nInput, getFactorial(nInput) );

    system("pause");
    return 0;
}
