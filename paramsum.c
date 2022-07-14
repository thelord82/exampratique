/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 08:25:39 by malord            #+#    #+#             */
/*   Updated: 2022/07/13 15:03:56 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int argc)
{
	int nbr = 0;
	if (argc >= 10)
		ft_putnbr(argc / 10);
	nbr = (argc) % 10 + 48;
	write (1, &nbr, 1);
}

int main (int argc, char **argv)
{
	if (argc < 2 && argv[0] != NULL)
		write (1, "0\n", 2);
	else
		ft_putnbr(argc - 1);
	return (0);
}