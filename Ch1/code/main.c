#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "myheader.h"
#include "child.h"

//#define min(x, y) (x<y?x:y)
#define min(x, y) ({__typeof__(x) __x = (x);\
					__typeof__(y) __y = (y);\
					__x < __y ? __x : __y;\
					})

#define swap(a, b)  \
					{\
						char *__a = (char *)&a;\
						char *__b = (char *)&b;\
						size_t __size = sizeof(a);\
						do\
						{\
							char tmp = *__a;\
							*__a++ = *__b;\
							*__b++ = tmp;\
						}while(--__size > 0);\
					}
int main()
{
	/*** floating point error: different answer between O0 and Ofast ***/
	/*
	double x = 0.01;
	printf("%.10lf\n", 1e9 + (x - 1e9));
	*/

	/*** buffer overflow demo (need flag, -fno-stack-protector) ***/
	/*
	int x = -1;
	char s[] = "hello";
	gets(s);
	//printf("s:   %p\n", s);
	//printf("s+5: %p\n", s + 5);
	//printf("s+6: %p\n", s + 6);
	//printf("x:   %p\n", &x);
	printf("x=%d\n", x);
	printf("s=%s\n", s);
	*/

	/*** scanf regular expression ***/
	/*
	char s[100];
	scanf("%[abcdefg]s", s);
	//scanf("%[0123456789]s", s);
	//scanf("%[a-z]s", s);
	//scanf("%[0-9]s", s);
	//scanf("%[^a-z]s", s);
	//scanf("%[^0-9]s", s);
	//scanf("%[^\n]s", s);
	//scanf("%[^a-zA-Z]s", s);
	printf("s=%s\n", s);
	*/

	/*** sprintf and sscanf ***/
	/*
	char s[100];
	int x = 1, y = -1, z = -3;
	sprintf(s, "%d %d %d", x, y, z);
	printf("%s\n", s);
	int val1, val2, val3;
	sscanf(s, "%d %d %d", &val1, &val2, &val3);
	printf("%d %d %d\n", val1, val2, val3);
	*/
	
	/*** scanf trap ***/
	/*
	char c;
	int x;
	while(~scanf("%[^\n]s", s)) printf("%s\n", s);
	//scanf("%d", &x); scanf("%c", &c);
	//printf("x=%d, c=%c\n", x, c);
	*/
	
	/*** c preprocessor demo ***/
	/*
	int x = 100, y = 102, z = 102;
	printf("%d\n", min(x, y<z?y:z));
	*/

	/*** memset demo ***/
	/*
	int a[2];
	memset(a, 256, sizeof(a));
	printf("%d\n", a[0]);
	memset(a, 0b00000001, sizeof(a));
	printf("%d\n", a[0]);
	*/

	/*** strlen ***/
	/*
	int x = 0xFFFFFFFF;
	char s[6] = "hello";
	//s[5] = 11;
	printf("%ld\n", strlen((char *)&x));
	printf("%ld\n", strlen(s));
	*/

	return 0;
}
