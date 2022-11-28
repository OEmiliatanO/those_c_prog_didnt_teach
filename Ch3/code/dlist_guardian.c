#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// define struct
typedef struct node
{
	int val;
	struct node *prev, *next;
}node;

// define struct
typedef struct list
{
	int size;
	node *head, *tail;
}list;

// node constructor
node *create_node(int val)
{
	node *n = (node *)malloc(sizeof(node));
	n->prev = n->next = NULL;
	n->val = val;
	return n;
}

// list constructor
list* create_list()
{
	list *p = (list *)malloc(sizeof(list));
	p->size = 0;
	p->head = create_node(0);
	p->tail = create_node(0);
	p->head->next = p->tail;
	p->tail->prev = p->head;
	return p;
}

void insert(list *p, int pos, int val)
{
	// invaild position to insert
	if (p->size < pos) return;
	
	// go to the position
	node *x = p->head;
	for (int i = 0; i < pos; ++i)
		x = x->next;
	node *y = x->next;
	
	// insert the node
	node *new_node = create_node(val);
	new_node->prev = x;
	new_node->next = y;
	x->next = new_node;
	y->prev = new_node;

	++p->size;
}

void delete(list *p, int pos)
{
	// list is empty
	if (p->size == 0) return;

	// invaild position to delete
	if (p->size <= pos) return;
	
	// go to the position
	node *y = p->head;
	for (int i = 0; i <= pos; ++i)
		y = y->next;
	node *x = y->prev, *z = y->next;

	// concatenate the previous and next nodes
	x->next = z;
	z->prev = x;
	free(y);

	--p->size;
}

void print_list(list *p)
{
	if (p->size == 0) { puts("empty"); return; }
	node *now = p->head->next;
	while(now != p->tail)
	{
		printf("%d ", now->val);
		now = now->next;
	}
	puts("");
}

int main()
{
	list *L = create_list();
	insert(L, 0, 0);
	delete(L, 0);
	print_list(L);

	for (int i = 0; i < 10; ++i)
	{
		insert(L, i, i+1);
		print_list(L);
	}
	for (int i = 0; i < 10; ++i)
	{
		insert(L, 0, 10-i);
		print_list(L);
	}
	
	for (int i = 0; i < 10; ++i)
	{
		delete(L, 9);
		print_list(L);
	}
	
	return 0;
}
