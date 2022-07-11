#include "list.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void	ft_swap_list(t_list *a, t_list *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

int ascending(int a, int b)
{
	return (a <= b);
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *new;

	new = lst;
	while (lst->next != 0)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			ft_swap_list(lst, lst->next);
			lst = new;
		}
		else
			lst = lst->next;
	}
	return (new);
}

int main(void)
{
	t_list *un;
	t_list *deux;
	t_list *trois;
	t_list *quatre;
	un = malloc(sizeof(t_list));
	deux = malloc(sizeof(t_list));
	trois = malloc(sizeof(t_list));
	quatre = malloc(sizeof(t_list));
	un->data = 18;
	un->next = deux;

	deux->data = 14;
	deux->next = trois; 

	trois->data = 69;
	trois->next = quatre;

	quatre->data = 42;
	quatre->next = 0;
	t_list *current = un;
	printf("Liste non triee : ");
	while (current)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("\n");
	current = sort_list(un, ascending);
	printf("Liste triee : ");
	while (current)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("\n");
}

