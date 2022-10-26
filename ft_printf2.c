/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:24:25 by malord            #+#    #+#             */
/*   Updated: 2022/10/26 13:34:08 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putstr(char *str)
{
	int i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	int len = ft_strlen(str);
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (len);
}

long ft_numlen(long nbr, long base)
{
	int len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr >= base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

long ft_putnbr(long nbr)
{
	int len = ft_numlen(nbr, 10);
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (len);
	}
	if (nbr < 0)
		nbr  = -nbr;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + 48;
	write (1, &nbr, 1);
	return (len);
}

long ft_printhexa(unsigned int nbr)
{
	long len = ft_numlen(nbr, 16);
	char *base = "0123456789abcdef";
	if (nbr >= 16)
		ft_printhexa(nbr / 16);
	write (1, &base[nbr % 16], 1);
	return (len);
}

int ft_printf(char *str, ...)
{
	int len = 0, i = 0;
	va_list args;
	char *s;
	long d, x;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			switch (str[i + 1])
			{
				case 's':
					s = va_arg(args, char *);
					len += ft_putstr(s);
					i++;
					break ;
				case 'd':
					d = va_arg(args, int);
					len += ft_putnbr(d);
					i++;
					break ;
				case 'x':
					x = va_arg(args, unsigned int);
					len += ft_printhexa(x);
					i++;
					break ;
			}
		}
		else
		{
			write (1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return(len);
}

int main(void)
{
	char *line = NULL;
	int nbr = 42, len = 0;
	len = ft_printf("La phrase est %s, le nombre est %d, l'hexa est %x\n", line, nbr, -42);
	ft_printf("ft_printf len = %d\n", len);

	len = printf("La phrase est %s, le nombre est %d, l'hexa est %x\n", line, nbr, -42);
	printf("printf len = %d\n", len);
	
}