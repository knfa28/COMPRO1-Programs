#include <stdio.h>
#define SENTINEL -999
 int main()
 {
 	int nNum, nChoice;
 	int nSum = 0;
 	int nCnt = 0;
 	int nEvenCnt = 0, nOddCnt = 0;

 	scanf("%d", &nNum);
 	while (nNum != SENTINEL)
 	{ 
 		nEvenCnt += !(nNum%2) * 1;
	 	nOddCnt += nNum%2 * 1;
 		nSum += nNum;
 		nCnt++;
 		scanf("%d", &nNum);
 	}	
 	do{
 		do{
 			printf("Menu:\n");
 			printf("(1) Display sum\n");
 			printf("(2) Display average\n");
 			printf("(3) Display odd and even count\n");
 			printf("(4) Exit\n");
 			printf("Choice: ");
 			scanf("%d", &nChoice);
		 }while(nChoice < 1 || nChoice > 4);
			switch(nChoice)
 			{
 				case 1: printf("Sum = %d\n", nSum); break;
 				case 2: printf("Mean = %.2f\n", nSum * 1.0 /nCnt); break;
 				case 3: printf("Total Odd = %d\nTotal Even = %d\n", nOddCnt, nEvenCnt); break;
			}
 	 }while(nChoice != 4);
 return 0;
}

