/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:34:31 by malord            #+#    #+#             */
/*   Updated: 2022/07/14 09:23:30 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	nb_words(char *str)
{
	int i = 0;
	int words =0;

	while(str[i])
	{
		if(str[i] > 32 && str[i - 1] <= 32)
			words++;
		i++;
	}
	return(words);
}

int word_len(char *str, int index)
{
	int i = index;
	while(str[i])
		i++;
	return (i);
}

char *trimword(char *str, int index)
{
	char *trimmed;
	int j = 0;
	while (str[index] <= 32)
		index++;
	trimmed = malloc(sizeof(char) * (word_len(str, index)));
	while(str[index] > 32)
	{
		trimmed[j] = str[index];
		j++;
		index++;
	}
	return (trimmed);
}
char **ft_split(char *str)
{
	char **result;
	int i = 0;
	int index = 0;
	int words = nb_words(str);
	result = malloc(sizeof(char *) * (words) + 1);
	while (str[index] <= 32)
		index++;
	while (str[index])
	{
		while (i < words)
		{
			result[i] = trimword(str, index);
			while (str[index] > 32)
				index++;
			while (str[index] <= 32)
				index++;
			i++;
		}
		index++;
	}
	return (result);
}

int main()
{
	char *str = "phrase        de      quatre			 mots ou    plus    ";
	char **result = ft_split(str);
	int i = 0;
	while(result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}