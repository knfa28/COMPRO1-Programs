#include<stdio.h>
#include<stdlib.h>

void displayLetters()
{
     int i;
     
     for(i = 65; i <= 90; i++)
        printf("%c%c\n", i, i+32);
}

int main()
{
    displayLetters();
    
    system("pause");
    return 0;
}
