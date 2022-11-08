#include <stdio.h>

int main()
{
	char s[10];
	gets(s);
	printf("%s\n", s);
	fgets(s, sizeof(s), stdin);
	printf("%s\n", s);
	scanf("%[^\n]s", s);
	printf("%s\n", s);
	return 0;
}