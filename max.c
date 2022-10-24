#include <stdio.h>
int max(int *tab, unsigned int len)
{
    if (len == 0)
        return (0);
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
	int tab[7] = {};
	printf("%d\n", max(tab, 20));
}
