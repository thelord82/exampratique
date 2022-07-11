#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void ft_swap (t_list *a, t_list *b)
{
	int tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	head = lst; 

	while (lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			ft_swap(lst, lst->next);
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}
int ascending (int a, int b)
{
	return (a <= b);
}

int main(void)
{
	t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));
	t_list *c = malloc(sizeof(t_list));

	a->data = 42;
	a->next = b;

	b->data = 21;
	b->next = c;

	c->data = 10;
	c->next = 0;

	t_list *current = a;
	printf("Liste non triee : ");
	while (current)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("\n");
	current = sort_list(a, ascending);
	printf("Liste triee : ");
	while (current)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
}