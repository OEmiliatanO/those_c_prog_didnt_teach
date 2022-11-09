#include <stdio.h>

int parse(char *s, int *val, int *n)
{
	int i = 0;
    while(s[i] && (s[i] > '9' || s[i] < '0')) ++i;
    if (!s[i]) return -1; // no integer read
    int res = 0;
    while(s[i] && s[i] >= '0' && s[i] <= '9')
    {   
        res *= 10; 
        res += s[i] - '0';
        ++i;
    }   
    *val = res;
    *n = i;
    return 1;
}

int main()
{   
    char s[1000];
    while(~scanf("%[^\n]s%n", s) && getchar())
    {
        int offset = 0, n, val;
        while(~parse(s + offset, &val, &n))
        {
            printf("%d\n", val);
            offset += n;
        }
    }
    return 0;
}
