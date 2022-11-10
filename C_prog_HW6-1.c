#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define W_ 101
#define H_ 101

typedef double (*func_t)(double);

char output[H_ + 1][W_ + 1], cpoutput[H_ + 1][W_ + 1];
void drawF(func_t f_, func_t df_)
{
	int origin = W_ / 2;
	for (int i = 0; i < W_; ++i)
	{
		int x = i - origin;
		int y = (int)ceil(f_(x));
		if (-y + origin < H_ && -y + origin >= 0)
		{
			int slope = (int)df_(x);
			if (slope == 0) 
				output[-y + origin][i] = '-';
			else if (slope > 0)
				output[-y + origin][i] = '/';
			else
				output[-y + origin][i] = '\\';
		}
	}
}

void draw_line(double m, double x0, double y0)
{
	int origin = W_ / 2;
	for (int i = 0; i < W_; ++i)
	{
		int x = i - origin;
		int y = (int)ceil(m*(x - x0) + y0);
		if (-y + origin < H_ && -y + origin >= 0)
			output[-y + origin][i] = '#';
	}

}

void draw_xline(int x)
{
	int origin = W_ / 2;
	for (int i = 0; i < H_; ++i)
		output[i][x + origin] = '|';
}

void drawAxe()
{
	
	for (int i = 0; i < W_; ++i)
		for (int j = 0; j < H_; ++j)
			output[j][i] = ' ';	
	
	/* another way
	memset(output, ' ', sizeof(output));
	for (int i = 0; i < H_; ++i)
		output[i][W_] = '\0';
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
	output[H_/2][W_ - 1] = '>';
	output[0][W_/2] = '^';
}

void print_output()
{
	for (int i = 0; i < H_; ++i)
		printf("%s\n", output[i]);
	puts("");
}

double a, b, c, d;
double f(double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}
double df(double x)
{
	return 3*a*x*x + 2*b*x + c;
}

int main()
{
	printf("a b c d: ");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	double x1, x2;
	printf("x1 x2: ");
	scanf("%lf %lf", &x1, &x2);
	drawAxe();
	drawF(f, df);
	memcpy(cpoutput, output, sizeof(output));
	while (fabs(x1 - x2) >= 0.1)
	{
		draw_xline((int)x1);
		draw_xline((int)x2);
		x2 = (x1 + x2) / 2;
		print_output();
		memcpy(output, cpoutput, sizeof(output));
	}
	draw_xline(x1);
	double y2 = f(x2), y1 = f(x1);
	double m = (y2 - y1)/(x2 - x1);
	draw_line(m, x1, y1);
	print_output();
	printf("x1 = %lf, y1 = %lf\nx2 = %lf, y2 = %lf\n", x1, y1, x2, y2);
	printf("(x2-x1) = %lf\n(y2-y1) = %lf\n", x2 - x1, y2 - y1);
	printf("m = %lf\n", m);
	return 0;
}
