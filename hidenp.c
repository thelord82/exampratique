/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:48:30 by malord            #+#    #+#             */
/*   Updated: 2022/07/12 13:59:59 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] != argv[2][j] && argv[2][j] != '\0')
				j++;
			if (argv[2][j] == '\0')
			{
				write(1, "0\n", 2);
				return (0);
			}
			i++;
			j++;
		}
		write (1, "1", 1);
	}
	write(1, "\n", 1);
}
