/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:29:34 by malord            #+#    #+#             */
/*   Updated: 2022/07/12 10:44:27 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		unsigned int first = atoi(argv[1]);
		unsigned int second = atoi(argv[2]);

		int div = first;

		while (div > 0)
		{
			if (first % div == 0 && second % div == 0)
			{
				printf("%d", div);
				break ;
			}
			else
				div--;
		}
	}
	printf("\n");
}