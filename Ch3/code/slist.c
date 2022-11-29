#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}node;

typedef struct list
{
	int size;
	struct node *head, *tail;
}list;

node *create_node(int val)
{
	node *n = (node *)calloc(1, sizeof(node));
	n->val = val;
	return n;
}

list *create_list()
{
	return (list *)calloc(1, sizeof(list));
}

void insert(list *p, int pos, int val)
{
	if (p->size == 0) { p->head = p->tail = create_node(val); ++p->size; return; }
	if (pos >= p->size) return;
	node *x = p->head;
	for (int i = 0; i < pos; ++i)
		x = x->next;
	node *y = x->next;

	node *new_node = create_node(val);
	x->next = new_node;
	new_node->next = y;

	if (new_node->next == NULL) p->tail = new_node;
	++p->size;
}

void delete(list *p, int pos)
{
	if (pos >= p->size) return;
	node *x = NULL, *y = p->head;
	for (int i = 0; i < pos; ++i)
	{
		x = y;
		y = y->next;
	}
	node *z = y->next;
	
	if (x)
		x->next = z;
	else
		p->head = z;

	if (z == NULL)
		p->tail = x;

	free(y);
	--p->size;
}

void print_list(list *p)
{
	node *now = p->head;
	while (now)
	{
		printf("%d ", now->val);
		now = now->next;
	}
	puts("");
}

int main()
{
	list *p = create_list();
	insert(p, 0, 1);
	print_list(p);
	insert(p, 0, 2);
	print_list(p);
	insert(p, 0, 3);
	print_list(p);
	insert(p, 0, 4);
	print_list(p);
	insert(p, 0, 5);
	print_list(p);
	insert(p, 0, 6);
	print_list(p);
	delete(p, 0);
	print_list(p);
	insert(p, p->size-1, 1);
	print_list(p);
	delete(p, 2);
	print_list(p);
	delete(p, 0);
	print_list(p);
	delete(p, 0);
	print_list(p);
	delete(p, 0);
	print_list(p);
	delete(p, 0);
	print_list(p);
	delete(p, 0);
	print_list(p);
	return 0;
}
