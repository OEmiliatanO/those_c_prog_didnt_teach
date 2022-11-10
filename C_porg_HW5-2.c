#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define W_ 101
#define H_ 101

typedef double (*func_t)(double);

char output[H_ + 1][W_ + 1];
void drawF(func_t f_)
{
	int origin = W_ / 2;
	for (int i = 0; i < W_; ++i)
	{
		int y = (int)ceil(f_(i - origin));
		y = -y;
		if (y + origin < H_ && y + origin >= 0)
			output[y + origin][i] = '*';
	}
}

void drawAxe()
{
	/* for (int i = 0; i < W_; ++i)
		for (int j = 0; j < H_; ++j)
			output[j][i] = ' ';
	*/
	
	for (int i = 0; i < W_; ++i)
		output[H_ / 2][i] = '-';
	for (int i = 0; i < H_; ++i)
		output[i][W_ / 2] = '|';
	output[H_ / 2][W_ / 2] = '0';
	for (int i = 1; i < W_/2 / 10; ++i)
	{
		output[H_ / 2][W_/2 + i * 10] = '|';
		output[H_ / 2 - 1][W_/2 + i * 10 - 1] = '0' + i;
		output[H_ / 2 - 1][W_/2 + i * 10] = '0';
		
		output[H_ / 2][W_/2 - i * 10] = '|';
		output[H_ / 2 - 1][W_/2 - i * 10 - 2] = '-';
		output[H_ / 2 - 1][W_/2 - i * 10 - 1] = '0' + i;
		output[H_ / 2 - 1][W_/2 - i * 10] = '0';
	}
	for (int i = 1; i < W_/2 / 10; ++i)
	{
		output[H_/2 - i * 10][W_/2 + 1] = '0' + i;
		output[H_/2 - i * 10][W_/2 + 2] = '0';
		
		output[H_/2 + i * 10][W_/2 + 1] = '-';
		output[H_/2 + i * 10][W_/2 + 2] = '0' + i;
		output[H_/2 + i * 10][W_/2 + 3] = '0';
	}
}

double a, b, c, d;
double f(double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

int main()
{
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	drawAxe();
	drawF(f);
	for (int i = 0; i < H_; ++i)
		printf("%s\n", output[i]);
	return 0;
}
