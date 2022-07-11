#include <stdlib.h>
#include <stdio.h>

int	numlen(int nbr)
{
	int numlen = 0;

	if (nbr < 0)
	{
		nbr *= -1;
		numlen++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		numlen++;
	}
	numlen++;
	return (numlen);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		chiffre = numlen(nbr);

	str = malloc(sizeof(char) * numlen(nbr) + 1);
	while (chiffre > 0)
	{
		str[chiffre - 1] = (nbr % 10) + 48;
		chiffre--;
		nbr /= 10;
	}
	return(str);
}
			 

int main()
{
	int nbr = 51110;

	printf("%s\n", ft_itoa(nbr));
	return (0);
}
