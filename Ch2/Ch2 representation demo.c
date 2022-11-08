#include <stdio.h>

int main()
{
	int x = 0x40000000;
	printf("%d\n", *(int *)&x);
	printf("%u\n", *(unsigned int *)&x);
	printf("%f\n", *(float *)&x);
	
	return 0;
}