#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int height;
	int num;
}student;

student students[1000];

int comp(const void * a, const void * b)
{
	int ha = ((student*)a)->height, hb = ((student *)b)->height;

	// a < b, ret -1;
	if (ha < hb) return -1;
	// a == 0, ret 0;
	if (ha == hb) return 0;
	// a > b, ret 1;
	if (ha > hb) return 1;
}

int main()
{
	char s[1000];
	scanf("%[^\n]s", s); getchar();
	int offset = 0, n, height, num = 0;
	while(~sscanf(s + offset, "%d%n", &height, &n))
	{
		students[num].num = num;
		students[num].height = height;
		++num;
		offset += n;
	}
	qsort((void *)students, num, sizeof(student), comp);

	for (int i = 0; i < num; ++i)
		printf("seat:%d, number:%d, height:%d\n", i+1, students[i].num+1, students[i].height);

	return 0;
}
