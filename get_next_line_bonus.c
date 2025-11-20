/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:40:20 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/20 15:20:04 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > MAX_FDS || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[fd][0])
			line = ft_strjoin(line, buffer[fd]);
		if (ft_strchr(buffer[fd], '\n'))
			break ;
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (buffer[fd][0] = '\0', free(line), NULL);
		buffer[fd][bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
	}
	if (!line || !line[0])
		return (free(line), NULL);
	ft_memcpy(buffer[fd], buffer[fd] + ft_strlen_find(buffer[fd], '\n'),
		ft_strlen_find(buffer[fd] + ft_strlen_find(buffer[fd], '\n'), '\0'));
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
//
// int main(void){
// 	int fd1 = open("get_next_line.c", O_RDONLY);
// 	int fd2 = open("get_next_line_bonus.c", O_RDONLY);
// 	int lines_to_read = 100;
// 	char *s;
// 	while (lines_to_read--)
// 	{
// 		s = get_next_line(fd1);
// 		printf("%s", s);
// 		free(s);
// 		s = get_next_line(fd2);
// 		printf("%s", s);
// 		free(s);
// 	}
// 	free(s);
// 	close(fd1);
// 	close(fd2);
// }