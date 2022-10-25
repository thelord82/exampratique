/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 08:16:31 by malord            #+#    #+#             */
/*   Updated: 2022/10/25 15:26:21 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
    char *string = malloc(10000), *buffer = string;
    while (read(fd, buffer, BUFFER_SIZE) > 0 && *buffer++ != '\n');
    return (buffer > string) ? (*buffer = 0, string) : (free(string), NULL);
}

int main(void)
{
    int fd = open("file", O_RDONLY);
    char *line = get_next_line(fd);

    while (line != NULL)
    {
        printf("%s", line);
        line = get_next_line(fd);
    }
}