/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:50:59 by malord            #+#    #+#             */
/*   Updated: 2022/10/25 15:24:08 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_numlen(long nbr, long base)
{
	long	i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

long ft_putnbr(int nbr)
{
	long len = ft_numlen(nbr, 10);

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	nbr = nbr % 10 + 48;
	ft_putchar(nbr);
	return (len);
}

int	ft_printhexa(unsigned int n, char c)
{
	char			*hexbase;
	int				len;

	len = ft_numlen(n, 16);
	hexbase = "0123456789abcdef";
	if (n >= 16)
		ft_printhexa(n / 16, c);
	write (1, &hexbase[n % 16], 1);
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	while (*s)
		ft_putchar(*s++);
	return (len);
}

int	ft_checkchar(char c, va_list argu)
{	
	int	len;

	if (c == 's')
		len = ft_putstr(va_arg(argu, char *));
	if (c == 'd')
		len = ft_putnbr(va_arg(argu, int));
	if (c == 'x')
		len = ft_printhexa(va_arg(argu, unsigned int), c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_checkchar(*(str), args);
		}
		else
		{
			write (1, *(&str), 1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
	char *line = NULL;
	int nombre = -42;
	int len = ft_printf("La phrase est %s, le nombre est %d, l'hexa est %x\n", line, 42, nombre);
	ft_printf("Len de ft_printf = %d\n", len);
	len = printf("La phrase est %s, le nombre est %d, l'hexa est %x\n", line, 42, nombre);
	printf("Printf Len = %d\n", len);
}