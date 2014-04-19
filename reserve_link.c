#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int value;
	struct node *next;
}node_t;

node_t *create_link()
{
	node_t *head = NULL, *p;
	int i;
	for (i = 1; i < 10; i++) {
		p = (node_t *)malloc(sizeof(node_t));
		if (NULL == p)
			break;
		p->value = i;
		if (NULL == head) {
			head = p;
			head->next = NULL;
		}
		else {
			p->next = head;
			head = p;
		}
	}

	return head;
}

void destroy_link(node_t *link)
{
	node_t *p, *q;
	p = link;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
}

node_t *reverse_link(node_t *link)
{
	node_t *r, *prev, *cur, *next;
	if (NULL == link || NULL == link->next)
		return link;

	prev = link;
	r = cur = link->next;
	next = cur->next;

	while (r){
		
		next = r->next;
		r->next = prev;
		prev = r;
		r = next;
		
	}
	
	link->next = NULL;
	return prev; 
}


void print_link(node_t *link)
{
	while (link) {
		if (link->next)
			printf("%d->", link->value);
		else
			printf("%d\n", link->value);
		link = link->next;
	}
}

int main()
{
	node_t *link = create_link();
	print_link(link);
	node_t *link2 = reverse_link(link);
	print_link(link2);
	destroy_link(link2);
	return 0;
}
