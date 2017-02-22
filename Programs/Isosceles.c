#include<stdio.h>

void displaySpace(int n, char cData)
{
	int nCtr;

	for(nCtr = 1; nCtr <= n; nCtr++)
		printf("%c", cData);
}

void displayIsosceles(int n)
{
	int nLines, nDigits, nCtr = 1;
	
	for(nLines = 1; nLines <= n; nLines++)
	{
		displaySpace(n - nLines, ' ');
		
		for(nDigits = 1; nDigits <= nLines * 2 - 1; nDigits++)
		{
			printf("%d", nCtr % 10);
			nCtr++;
		}	
		printf("\n");
	}
}

int main()
{
	int n, nNum;
	char cData;
	
	printf("Input a number: ");
	scanf("%d", &n);
	
	displayIsosceles(n);
	
	return 0;
}
