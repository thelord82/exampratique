/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal <mal@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:20:13 by mal               #+#    #+#             */
/*   Updated: 2022/12/09 20:21:31 by mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	len_of_array(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] <= 32)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] > 32)
			i++;
		len++;
		while (str[i] && str[i] <= 32)
			i++;
	}
	return (len);
}

int	ft_strlen(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && str[i] > 32)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		array_index;
	int		len;
	char	**array;

	i = 0;
	j = 0;
	array_index = 0;
	if (!str)   // protection en cas de string null
		return (NULL);
	len = len_of_array(str);
	array = malloc(sizeof(char *) * len + 1);
	array[len] = 0; // au lieu de array[len] = '\0';
	while (str[i])
	{
		while (str[i] && str[i] <= 32)
			i++;
		len = ft_strlen(str, i);
		array[array_index] = malloc(sizeof(char) * len + 1);
		array[array_index][len] = '\0';
		while (str[i] && str[i] > 32)
		{
			array[array_index][j] = str[i];
			i++;
			j++;
		}
		array_index++;
		j = 0;
		while (str[i] && str[i] <= 32)
			i++;
	}
	return (array);
}

int	main(void)
{
	char *str = "          allo         mon ti          coco";
	char **result = ft_split(str);
	int i = 0;
	while (result && result[i])
	{
		printf("result[i] = %s\n", result[i]);
		i++;
	}
}