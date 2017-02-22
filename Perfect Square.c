#include <stdio.h>

int getPerfect(int n)
{
	int a;
	for(a = 0; a <= n; a++)
    {
        if (n == a * a)
        {
            return a;
        }
        return 0;
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d", getPerfect(n));
    return 0;
}
