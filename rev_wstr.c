#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int 	i = 0;
	int		words = 1;
	int		total_words = 0;
	char	 array[4][5];

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
				words++;
			i++;
		}
		//array = malloc(sizeof(char *) * words + 1);
		i = 0;
		total_words = words;
		words = 0;
		while (words < total_words)
		{
			while (argv[1][i] != ' ')
			{
				array[words][i] = argv[1][i];
				i++;
			}
			write(1, &array[words], strlen(array[words]));
			write(1, " ", 1);
			words++;
			i++;
		}
		/*words = 0;
		i = 0;
		while (array[words])
		{
			i = 0;
			while (array[words][i])
			{
				write(1, &array[words][i], 1);
				i++;
			}
			words++;
		}*/
	}
	write (1, "\n", 1);
}
