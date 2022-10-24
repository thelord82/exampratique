#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char	*str;
	if (argc == 2)
	{
		while (argv[1][j] != ' ' && argv[1][j] != '	')
			j++;
		str = malloc(sizeof(char) * j + 1);
		i = 0;
		while (argv[1][i] != ' ' && argv[1][i] != '	')
		{
			str[i] = argv[1][i];
			i++;
		}
		i = 0;
		while (argv[1][j])
		{
			write(1, &argv[1][j], 1);
			j++;
		}
		while(str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
