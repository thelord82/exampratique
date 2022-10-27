/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:21:55 by malord            #+#    #+#             */
/*   Updated: 2022/10/27 14:41:59 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *string = malloc(10000), *buffer = string;
	while (read(fd, buffer, BUFFER_SIZE) > 0 && *buffer++ != '\n');
	return (buffer > string) ? (*buffer = 0, string) : (free(string), NULL);
}

/*int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *get_next_line(int fd)
{
	char *string = NULL; 
	char *buffer;

	string = malloc(10000);
	if (!string)
		return (NULL);
	buffer = string;
	while (read(fd, buffer, BUFFER_SIZE) > 0 && *buffer++ != '\n');
	if (buffer > string)
	{
		*buffer = 0;
		return (string);
	}
	else
	{
		free (string);
		return (NULL);	
	}
}*/

int main(void)
{
	int fd = open("file", O_RDONLY);
	char *line = get_next_line(fd);

	while (line != NULL)
	{
		printf("line = %s", line);
		free(line);
		line = get_next_line(fd);
	}
	line = get_next_line(fd);
	printf("line outside = %s", line);
}