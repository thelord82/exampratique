/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:46:47 by malord            #+#    #+#             */
/*   Updated: 2022/07/12 11:53:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

void	str_cap(char *str)
{
	int i = 0;

	while (is_letter(str[i]) == 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	while (str[i])
	{
		if (is_lower(str[i]) == 1 && is_letter(str[i - 1]) == 0)
		{
			str[i] -= 32;
			write (1, &str[i], 1);
		}
		else if (is_upper(str[i]) == 1 && is_letter(str[i - 1]) == 1)
		{
			str[i] += 32;
			write (1, &str[i], 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int main (int argc, char **argv)
{
	if (argc < 2)
		write (1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			str_cap(argv[i]);
			i++;
		}
	}
	return (0);
}
