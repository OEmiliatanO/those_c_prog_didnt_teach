#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *l, *r, *pa;
}node;

typedef struct tree
{
	node *root;
	size_t size;
}tree;

node* create_node()
{
	return (node *)calloc(1, sizeof(node));
}

tree* create_tree()
{
	return (tree *)calloc(1, sizeof(tree));
}
void print_node(node *now)
{
	if (!now) return;
	print_node(now->l);
	printf("%d ", now->val);
	print_node(now->r);
}
void print_tree(tree *T)
{
	print_node(T->root);
	puts("");
}
void insert(tree *T, int val)
{
	// special case
	if (T->size == 0)
	{
		T->root = create_node();
		T->root->val = val;
		++T->size;
		return;
	}

	node *pp = NULL;
	node *p = T->root;
	// find where to put in
	while (p)
	{
		pp = p;
		if (p->val < val)
			p = p->r;
		else
			p = p->l;
	}
	p = create_node();
	p->val = val;
	p->pa = pp;

	if (pp->val < val)  pp->r = p;
	else                pp->l = p;
	++T->size;
}

node* search(tree *T, int val)
{
	node *p = T->root;
	while (p && p->val != val)
	{
		if (p->val < val)
			p = p->r;
		else
			p = p->l;
	}
	return p;
}

void delete_by_node(tree *T, node *n)
{
	// no children
	if (n->l == n->r && n->l == NULL)
	{
		if (n->pa == NULL) { T->root = NULL; --T->size; free(n); return; }

		if (n->pa->l == n) n->pa->l = NULL;
		if (n->pa->r == n) n->pa->r = NULL;
		free(n);
		--T->size;
		return;
	}

	// having two children
	if (n->l != NULL && n->r != NULL)
	{
		node *y = n->r;
		while (y->l) y = y->l;
		n->val = y->val;
		delete_by_node(T, y);
		return;
	}
	
	//swap
	if (n->l)
	{
		n->r = n->l;
		n->l = NULL;
	}
	// having one child and the one is at the right node
	if (n->pa == NULL) { T->root = n->r; free(n); --T->size; return; }
	if (n->pa->l == n) n->pa->l = n->r;
	if (n->pa->r == n) n->pa->r = n->r;
	free(n);
	--T->size;
}
void delete_by_val(tree *T, int val)
{
	delete_by_node(T, search(T, val));
}

int main()
{
	tree *T = create_tree();
	insert(T, 5);
	insert(T, 3);
	insert(T, 2);
	insert(T, 1);
	insert(T, 4);
	print_tree(T);
	delete_by_val(T, 5);
	print_tree(T);
	delete_by_val(T, 3);
	print_tree(T);
	delete_by_val(T, 2);
	print_tree(T);
	return 0;
}
