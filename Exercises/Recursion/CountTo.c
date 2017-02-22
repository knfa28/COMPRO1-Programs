#include<stdio.h>

void countTo(int nNum)
{
     if(nNum>0)
     {
       countTo(nNum -1);
       printf("%d\n", nNum);      
     }
}

int main()
{
    int nNum;
    printf("enter number: ");
    scanf("%d", &nNum);   
    countTo(nNum);
} 
