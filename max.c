#include <stdio.h>
int max(int *tab, unsigned int len)
{
	int max = tab[len - 1];
	while (len > 0)
	{
		if (tab[len - 1] >= max)
			max = tab[len - 1];
		len--;
	}
	return (max);
}

int main (void)
{
	int tab[7] = {100, 200, 15, 4200, 888, 13, 1100};
	printf("%d\n", max(tab, 7));
}