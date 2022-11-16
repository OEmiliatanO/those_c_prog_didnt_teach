#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define node struct
typedef struct node
{
	int val;
	struct node *prev, *nex;
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
	n->prev = n->nex = NULL;
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
	node *now = p->head;
	for (int i = 0; i < pos; ++i)
		now = now->nex;
	
	// put node in now->nex
	if (now->nex) // case 1: now->nex isn't a NULL node
	{
		node *n = create_node(val);
		n->nex = now->nex;
		n->prev = now;
		now->nex = n;
		n->nex->prev = n;
	}
	else // case 1: now->nex is a NULL node
	{
		now->nex = create_node(val);
		now->nex->prev = now;
		p->tail = now->nex;
	}
	++p->size;
}

void insert_front(list *p, int val)
{
	node *now = create_node(val);
	now->nex = p->head;
	
	if (p->head)
		p->head->prev = now;
	else
		p->head = p->tail = now;
	
	p->head = now;
	++p->size;
}

void delete(list *p, int pos)
{
	// list is empty
	if (p->size == 0) return;
	
	// invaild position to insert
	if (p->size <= pos) return;
	
	// go to the position
	node *now = p->head;
	for (int i = 0; i < pos; ++i)
		now = now->nex;
	
	// special case
	if (p->size == 1)
	{
		free(now);
		--p->size;
		p->head = p->tail = NULL;
		return;
	}
	// special case
	if (now == p->head)
	{
		p->head = now->nex;
		if (p->head)
			p->head->prev = NULL;
		free(now);
		--p->size;
		return;
	}
	// special case
	if (now == p->tail)
	{
		p->tail = now->prev;
		if (p->tail)
			p->tail->nex = NULL;
		free(now);
		--p->size;
		return;
	}
	
	// delete the target node
	now->prev->nex = now->nex;
	now->nex->prev = now->prev;
	free(now);
	--p->size;
}

void print_list(list *p)
{
	node *now = p->head;
	while(now)
	{
		printf("%d ", now->val);
		now = now->nex;
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
