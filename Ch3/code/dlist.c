#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define node struct
typedef struct node
{
	int val;
	struct node *prev, *next;
}node;
// define list struct
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
	p->head = p->tail = NULL;
	return p;
}

void insert(list *p, int pos, int val)
{
	// special case
	if (p->size == 0)
	{
		p->tail = p->head = create_node(val);
		++p->size;
		return;
	}
	
	// invaild position to insert
	if (p->size <= pos) return;
	
	// go to the position
	node *x = p->head;
	for (int i = 0; i < pos; ++i)
		x = x->next;
	
	node *y = x->next;
	// put node in now->nex
	if (y) // case 1: now->nex isn't a NULL node
	{
		node *new_node = create_node(val);
		new_node->prev = x;
		new_node->next = y;
		x->next = new_node;
		y->prev = new_node;
	}
	else // case 1: now->nex is a NULL node
	{
		node *new_node = create_node(val);
		new_node->prev = x;
		x->next = new_node;
		p->tail = x->next;
	}
	++p->size;
}

void insert_front(list *p, int val)
{
	node *x = create_node(val);
	x->next = p->head;
	
	if (p->head)
		p->head->prev = x;
	else
		p->head = p->tail = x;
	
	p->head = x;
	++p->size;
}

void delete(list *p, int pos)
{
	// list is empty
	if (p->size == 0) return;
	
	// invaild position to insert
	if (p->size <= pos) return;
	
	// go to the position
	node *y = p->head;
	for (int i = 0; i < pos; ++i)
		y = y->next;

	node *x = y->prev;
	node *z = y->next;
	// special case
	if (p->size == 1)
	{
		free(y);
		--p->size;
		p->head = p->tail = NULL;
		return;
	}
	// special case
	if (y == p->head)
	{
		p->head = y->next;
		if (p->head)
			p->head->prev = NULL;
		free(y);
		--p->size;
		return;
	}
	// special case
	if (y == p->tail)
	{
		p->tail = y->prev;
		if (p->tail)
			p->tail->next = NULL;
		free(y);
		--p->size;
		return;
	}
	
	// delete the target node
	x->next = z;
	z->prev = x;
	free(y);
	--p->size;
}

void print_list(list *p)
{
	node *now = p->head;
	while(now)
	{
		printf("%d ", now->val);
		now = now->next;
	}
	puts("");
}

int main()
{
    list *L = create_list();
	insert(L, 0, 1);
    print_list(L);

    for (int i = 1; i < 10; ++i)
    {   
        insert(L, i-1, i+1);
        print_list(L);
    }   
    for (int i = 0; i < 10; ++i)
    {   
        insert_front(L, 10-i);
        print_list(L);
    }   
    
    for (int i = 0; i < 10; ++i)
    {   
        delete(L, 9); 
        print_list(L);
    }   

	return 0;
}
