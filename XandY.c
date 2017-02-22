#include<stdio.h>

int main()
{
	int x,y,z,nCheck=0;
	
	printf("Enter z: ");
	scanf("%d", &z);
	
	for(x = 1; x <= 1000; x++)
		for(y = 1; y <= 1000; y++)
			if(2 * x + 3 * y == z )
				printf("2(%d)+ 3(%d) = %d", x, y, z);
					
	return 0;
}
