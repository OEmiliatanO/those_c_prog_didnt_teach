#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
#define INT_MIN 0xffffffff

typedef struct pos_t
{
	int x, y, z;
}pos_t;

pos_t* queue[SIZE];
int qhead = 0, qtail = 0, qsize = 0;

void push(pos_t* val)
{
	if (qsize == SIZE) return;
	++qsize;
	queue[qtail++] = val;
}

pos_t* pop()
{
	if (qsize == 0) return NULL;
	--qsize;
	return queue[qhead++];
}

pos_t* peek()
{
	if (qhead == qtail) return NULL;
	return queue[qhead];
}

#define WALL -1
int maze[100][100][100];
const int dir[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
void bfs(pos_t* s, pos_t* t)
{
	push(s);
	maze[s->x][s->y][s->z] = 1;
	while (qsize)
	{
		pos_t* now = pop();
		if (now->x == t->x && now->y == t->y && now->z == t->z) return;
		int x = now->x, y = now->y, z = now->z;
		//printf("%d %d %d\n", x, y, z);
		for (int dirc = 0; dirc < 6; ++dirc)
		{
			int nx = x+dir[dirc][0], ny = y+dir[dirc][1], nz = z+dir[dirc][2];

			if (maze[nx][ny][nz] == WALL || maze[nx][ny][nz] != 0) continue;
			
			maze[nx][ny][nz] = maze[x][y][z] + 1;
			
			pos_t* nexp = (pos_t *)malloc(sizeof(pos_t));
			nexp->x = nx, nexp->y = ny, nexp->z = nz;
			push(nexp);
		}
		free(now);
	}
}

int main()
{
	int w, l, h;
	pos_t* s = (pos_t *)malloc(sizeof(pos_t)), *t = (pos_t *)malloc(sizeof(pos_t));

	scanf("%d %d %d", &h, &l, &w);
	scanf("%d %d %d", &s->x, &s->y, &s->z);
	scanf("%d %d %d", &t->x, &t->y, &t->z); getchar();
	memset(maze, WALL, sizeof(maze));
	
	for (int z = 1; z <= h; ++z, getchar())
		for (int y = 1; y <= l; ++y, getchar())
			for (int x = 1; x <= w; ++x)
			{
				if (getchar() == 'x')
					maze[x][y][z] = WALL;
				else
					maze[x][y][z] = 0;
			}
	
	bfs(s, t);

	for (int z = 1; z <= h; ++z, putchar('\n'))
		for (int y = 1; y <= l; ++y, putchar('\n'))
			for (int x = 1; x <= w; ++x)
				printf("%d ", maze[x][y][z]);

	free(t);

	return 0;
}

/*** test data ***/
/*
1 5 5
3 3 1
5 5 1
...x.
.x.x.
.x.x.
.xxx.
.....
*/
