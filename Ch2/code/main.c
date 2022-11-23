#include <stdio.h>
#define offsetof(st, member) ((size_t)&(((st*)0)->member))

void print_in_bin(int x)
{
	for (int i = 31; i >= 0; --i)
	{
		putchar("01"[!!(x&(1<<i))]);
	}
	puts("");
}


struct obj_t
{
	int ival;
	float fval;
	unsigned int uival;
};

void func0(void) { printf("calling func0.\n"); }
void func1(void) { printf("calling func1.\n"); }
void func2(void) { printf("calling func2.\n"); }
void func3(void) { printf("calling func3.\n"); }
void func4(void) { printf("calling func4.\n"); }

int add(int a, int b) { return a+b; }
int mul(int a, int b) { return a*b; }
int sub(int a, int b) { return a-b; }
int div(int a, int b) { return a/b; }

int main()
{
	/*** explicit cast 1 ***/
	/*
	int x = 0x40000000;
	printf("int:          %d\n", *(int *)&x);
	printf("unsigned int: %u\n", *(unsigned int *)&x);
	printf("float:        %f\n", *(float *)&x);
	*/

	/*** explicit cast 2 ***/
	/*
	int x = 0x40000000;
	float *fpx = (float *)&x;
	printf("before:\n");
	printf("x    = %d\n", x);
	printf("*fpx = %f\n", *fpx);
	
	*fpx = 4.0;
	printf("after:\n");
	printf("x    = %d\n", x);
	printf("*fpx = %f\n", *fpx);
	*/

	/*** malloc ***/
	/*
	float f = malloc(4);
	long l = malloc(8);
	*/

	/*** function pointer demo ***/
	/*
	int op;
	void (*ops[5])(void) = {func0, func1, func2, func3, func4};
	scanf("%d", &op);
	ops[op]();
	*/

	/*** simple calculate using function pointer ***/
	/*
	int a, b;
	char ch;
	int (*ops[256])(int,int);
	ops['+'] = add;
	ops['*'] = mul;
	ops['-'] = sub;
	ops['/'] = div;
	scanf("%d%c%d", &a, &ch, &b);
	printf("result = %d\n", ops[(size_t)ch](a, b));
	*/

	/*** pointer & struct ***/
	/*
	struct obj_t obj;
	struct obj_t *p_obj = &obj;
	printf("&obj       = %p\n", &obj);
	printf("&obj.ival  = %p\n", &obj.ival);
	printf("&obj.fval  = %p\n", &obj.fval);
	printf("&obj.uival = %p\n", &obj.uival);
	printf("p_obj + 1  = %p\n", p_obj + 1);
	*/

	/*** offset ***/
	/*
	printf("offset of  ival in obj_t is %ld.\n", offsetof(struct obj_t, ival));
	printf("offset of  fval in obj_t is %ld.\n", offsetof(struct obj_t, fval));
	printf("offset of uival in obj_t is %ld.\n", offsetof(struct obj_t, uival));
	*/

	/*** modify string literal ***/
	/*
	char *p = "hello";
	//p[0] = 'g';
	printf("%s\n", p);
	*/
	return 0;
}
