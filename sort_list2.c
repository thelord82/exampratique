/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:38:42 by malord            #+#    #+#             */
/*   Updated: 2022/08/17 12:56:17 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int ascending (int a, int b)
{
	return (a <= b);
}

void ft_swap_list (t_list *a, t_list *b)
{
	int c;
	c = a->data;
	a->data = b->data;
	b->data = c;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *new;

	new = lst;
	while (lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
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
	t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));
	t_list *c = malloc(sizeof(t_list));

	a->data = 32;
	a->next = b;
	b->data = 24;
	b->next = c;
	c->data = 12;
	c->next = 0;

	t_list *current = a;
	printf("Liste non triee : \n");
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	current = sort_list(a, ascending);
	printf("Liste triee : \n");
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	return (0);
}