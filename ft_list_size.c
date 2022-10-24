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

int main(void)
{
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *d;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	d = malloc(sizeof(t_list));

	a->data = 4;
	a->next = b;
	b->data = 6;
	b->next = c;
	c->data = 8;
	c->next = d;
	d->data = 4;
	d->next = 0;

	printf("%d", ft_list_size(a));
	return (0);
}