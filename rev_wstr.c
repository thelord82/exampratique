/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:48:14 by malord            #+#    #+#             */
/*   Updated: 2022/07/11 21:14:54 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int len = 0;
	int index = 0;
	
	if (argc == 2)
	{
		while (argv[1][len])
			len++;
		len--;
		while (len >= 0)
		{
			while (argv[1][len] != ' ' && len >= 0)
				len--;
			index = len + 1;
			while (argv[1][index] != ' ' && argv[1][index] != '\0')
			{
				write (1, &argv[1][index], 1);
				index++;
			}
			if (len > 0)
				write (1, " ", 1);
			len--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
