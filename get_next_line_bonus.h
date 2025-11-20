/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:40:32 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/20 14:13:26 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_find(const char *str, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *previous, const char *current);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*get_next_line(int fd);

#endif