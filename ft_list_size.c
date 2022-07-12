#include "list.h"
#include <stdlib.h>
#include <stdio.h>
int	ft_list_size(t_list *begin_list)
{
	int size = 0;
	
	while(begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

int main ()
{
	t_list *head;
	t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));
	t_list *c = malloc(sizeof(t_list));
	t_list *d = malloc(sizeof(t_list));

	a->data = 3;
	a->next = b;
	b->data = 5;
	b->next = c;
	c->data = 7;
	c->next = d;
	d->data = 11;
	d->next = 0;
	head = a;
	printf("Taille de liste : %d\n", ft_list_size(head));
}
