/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:46:21 by malord            #+#    #+#             */
/*   Updated: 2022/08/17 11:49:31 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(char *nbr)
{
	int i = 0;
	int nb = 0;
	while (nbr[i])
	{
		nb = (nb * 10) + nbr[i] - '0';
		i++;
	}
	return (nb);
}

void ft_putnbr(int nbr)
{
	char c;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write (1, &c, 1);
}

int main (int argc, char **argv)
{
	int sum = 2;
	if (argc == 2)
	{
		int nombre = ft_atoi(argv[1]);
		while (nombre > 1)
		{
			if (nombre % 2 != 0)
				sum += nombre; 
			nombre--;
		}
		ft_putnbr(sum);
		write (1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
