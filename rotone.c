/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:03:54 by malord            #+#    #+#             */
/*   Updated: 2022/08/19 15:33:43 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 65 && argv[1][i] <= 77)
			{
				argv[1][i] = argv[1][i] + 13;
				write (1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 78 && argv[1][i] <= 90)
			{
				argv[1][i] = argv[1][i] - 13;
				write (1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 97 && argv[1][i] <= 109)
			{
				argv[1][i] = argv[1][i] + 13;
				write (1, &argv[1][i], 1);
			}
			else if (argv[1][i] >= 110 && argv[1][i] <= 122)
			{
				argv[1][i] = argv[1][i] - 13;
				write (1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}