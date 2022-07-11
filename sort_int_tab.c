#include <stdio.h>
void ft_swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int swapped = 1;

	while (swapped == 1)
	{
		i = 1;
		swapped = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				ft_swap(&tab[i - 1], &tab[i]);
				swapped = 1;
			}
			i++;
		}
	}
}

int main()
{
	int tab[10] = {9, 8, 7, 6, 4, 5, 3, 2, 1, 0};
	int i = 0;

	sort_int_tab(tab, 10);
	while (i < 10)
	{
		printf("Valeur a l'element %d : %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
