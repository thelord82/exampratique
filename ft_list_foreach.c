#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != 0)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

void	int_doubler(void *n)
{
	int *num = (int *)n;
	*num = *num * 2;
}

int main()
{
	t_list *pt_a = malloc(sizeof(t_list));
 	int	n_a = 12;
 	pt_a->data = &n_a;
 	pt_a->next = 0;

 	t_list *pt_b = malloc(sizeof(t_list));
 	int	n_b = 42;
 	pt_b->data = &n_b;
 	pt_b->next = 0;

 	t_list *pt_c = malloc(sizeof(t_list));
 	int	n_c = 69;
 	pt_c->data = &n_c;
 	pt_c->next = 0;

 	pt_a->next = pt_b;
 	pt_b->next = pt_c;

 	t_list *cur = pt_a;
 	while (cur != 0)
 	{
 		printf("%d, ", *(int *)(cur->data));
 		cur = cur->next;
 	}
 	printf("\n");

 	ft_list_foreach(pt_a, int_doubler);
	cur = pt_a;
 	while (cur != 0)
 	{
 		printf("%d, ", *(int *)(cur->data));
 		cur = cur->next;
 	}
 	printf("\n");
 }
