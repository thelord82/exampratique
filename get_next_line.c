/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:16:31 by malord            #+#    #+#             */
/*   Updated: 2022/10/24 11:38:14 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd) 
{
    char *string = malloc(10000), *copy = string;
    while (read(fd, copy, 1) > 0 && *copy++ != '\n');
    return (copy > string) ? (*copy = 0, string) : (free(string), NULL);
}

int main(void)
{
	char *line;
	int fd = 0;
	int len = 0;
	fd = open("file", fd, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = printf("Contenu de gnl = %s", line);
		line = get_next_line(fd);
	}
}
