/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:40:20 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/14 16:34:57 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*cpy_buffer(const char *buffer, size_t len)
{
	char	*cpy;
	size_t	i;

	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (buffer[i] && i < len)
	{
		cpy[i] = buffer[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	i;
	char	*line;

	i = 1;
	line = malloc(BUFFER_SIZE + 1);
	while (i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		else if (i == 0)
			break ;
		line[i] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	if (ft_strlen_find(buffer, '\0') > 0)
		return (buffer);
	return (NULL);
}

char	*set_line(char **buffer)
{
	char	*line;
	char	*remain;
	size_t	before_n;
	size_t	before_0;

	before_n = ft_strlen_find(*buffer, '\n');
	if ((*buffer)[before_n] == '\n')
		before_n++;
	line = cpy_buffer(*buffer, before_n);
	if (!line)
		return (NULL);
	before_0 = ft_strlen_find(*buffer, '\0');
	remain = cpy_buffer(*buffer + before_n, before_0 - before_n + 1);
	if(!remain)
	{
		free(buffer);
		buffer = NULL;
		return(line);
	}
	free(*buffer);
	*buffer = remain;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = set_line(&buffer);
	return (line);
}
