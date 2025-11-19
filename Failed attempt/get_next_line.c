/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:40:20 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/19 13:55:12 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer)
{
	ssize_t	i;
	char	*line;

	i = 1;
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i <= 0)
			break ;
		line[i] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	if (i == -1)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	if (ft_strlen_find(buffer, '\0') > 0)
		return (buffer);
	return (NULL);
}

static char	*set_line(char **buffer)
{
	char	*line;
	char	*remain;
	size_t	before_n;
	size_t	before_0;

	if (!buffer || !*buffer)
		return (NULL);
	before_n = ft_strlen_find(*buffer, '\n');
	if ((*buffer)[before_n] == '\n')
		before_n++;
	line = cpy_buffer(*buffer, before_n);
	if (!line)
		return (NULL);
	before_0 = ft_strlen_find(*buffer, '\0');
	remain = cpy_buffer(*buffer + before_n, before_0 - before_n + 1);
	if (!remain)
	{
		free(line);
		return (NULL);
	}
	free(*buffer);
	*buffer = remain;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = set_line(&buffer);
	if (!buffer[0] || !buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main(void){
	int fd = open("get_next_line.c", O_RDONLY);
	char *line;
	
	int lines_to_read = 5;
	while ((line = get_next_line(fd)) && lines_to_read--)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
}
