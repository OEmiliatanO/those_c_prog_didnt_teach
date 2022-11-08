#include <stdio.h>

int main()
{
	char s[1000];
	while(~scanf("%[^\n]s", s) && getchar())
	{
		int offset = 0, n, val;
		while(~sscanf(s + offset, "%d%*s%n", &val, &n))
		{
			offset += n;
			// do some operation
			printf("%d\n", val);
		}
	}
}
