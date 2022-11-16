#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// define struct
typedef struct node
{
	int val;
	struct node *prev, *nex;
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
	n->prev = n->nex = NULL;
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
	p->head->nex = p->tail;
	p->tail->prev = p->head;
	return p;
}

void insert(list *p, int pos, int val)
{
	// invaild position to insert
	if (p->size < pos) return;
	
	// go to the position
	node *now = p->head;
	for (int i = 0; i < pos; ++i)
		now = now->nex;
	
	// insert the node
	node *n = create_node(val);
	n->nex = now->nex;
	n->prev = now;
	now->nex = n;
	n->nex->prev = n;

	++p->size;
}

void delete(list *p, int pos)
{
	// list is empty
	if (p->size == 0) return;

	// invaild position to delete
	if (p->size <= pos) return;
	
	// go to the position
	node *now = p->head;
	for (int i = 0; i <= pos; ++i)
		now = now->nex;
	
	// concatenate the previous and next nodes
	now->prev->nex = now->nex;
	now->nex->prev = now->prev;
	free(now);

	--p->size;
}

void print_list(list *p)
{
	if (p->size == 0) { puts("empty"); return; }
	node *now = p->head->nex;
	while(now != p->tail)
	{
		printf("%d ", now->val);
		now = now->nex;
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
