/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:47:11 by malord            #+#    #+#             */
/*   Updated: 2022/11/04 14:54:21 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	printhexa(int number)
{
	char *base = "0123456789abcdef";
	if (number >= 16)
		printhexa(number / 16);
	number = number % 16;
	write (1, &base[number], 1);
}

int main(int argc, char **argv)
{
	int number = 0;
	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		printhexa(number);
	}
	write(1, "\n", 1);
}