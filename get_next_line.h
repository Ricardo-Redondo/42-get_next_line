/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:40:32 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/20 13:35:42 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_find(const char *str, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *previous, const char *current);
void	*ft_memcpy(void *dst, const void *src, ssize_t n);

char	*get_next_line(int fd);

#endif