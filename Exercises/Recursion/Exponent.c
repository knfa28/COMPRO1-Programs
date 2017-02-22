#include<stdio.h>

float getPow(int nNum, int nPow)
{
    if(nPow == 0)
            return 1;
    else if(nPow ==1)
            return nNum;
    else if(nPow < 0)
            return 1.0 / getPow(nNum, nPow * -1);
    else if (nPow > 1)
            return nNum * getPow(nNum, nPow - 1);
}

int main()
{                            
    int nNum, nPow;
    printf("enter number: ");
    scanf("%d", &nNum);
    printf("enter power: ");
    scanf("%d", &nPow);
    printf("%d raised to %d is %.2f", nNum, nPow, getPow(nNum, nPow));
}
