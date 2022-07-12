/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:15:23 by malord            #+#    #+#             */
/*   Updated: 2022/07/12 10:26:36 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int j = 0;
		while (argv[1][i] <= 32)
			i++;
		while (argv[1][j])
			j++;
		while (argv[1][j] <= 32)
			j--;
		while (i <= j)
		{
			if (argv[1][i] > 32)
				write (1, &argv[1][i], 1);
			else
			{
				while (argv[1][i] <= 32)
					i++;
				i--;
				write (1, "   ", 3);
			}
			i++;
		}
	}
	write (1, "\n", 1);
}