#include<stdio.h>

int main()
{
	int nCtr, nBase, nPower, nSum=0, n;
	
	printf("Enter base: ");
	scanf("%d", &nBase);
	
	printf("Enter Power: ");
	scanf("%d", &n);
	
	while(n > 0)
	{
		nPower = 1;
	
		for(nCtr = 1; nCtr <= n; nCtr++)
			nPower *= nBase;	
	
		if(nPower % 2 == 0)
			nSum += nPower;
		else
			nSum -= nPower;
			
		n--;
	}
		
	printf("\n%d\n", nSum);
	return 0;
}
