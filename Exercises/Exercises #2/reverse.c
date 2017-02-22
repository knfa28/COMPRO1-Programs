#include <stdio.h>

int main()
{   int nNum,
        nRev,
        nHun, nTen, nOne;

    printf("Enter a 3-digit number: ");
    scanf("%d", &nNum);

    nHun = nNum / 100;
    nTen = nNum % 100 / 10;     /* nTen = nNum / 10 % 10; */
    nOne = nNum % 10;

    nRev = nOne * 100 + nTen * 10 + nHun;

    printf("Reverse of %d is %03d\n", nNum, nRev);

    return 0;
}
