#include <stdio.h>

int main()
{
	int x, y;
	scanf("%d %*f %d", &x, &y);
	printf("%d %d\n", x, y);
	
	return 0;
}