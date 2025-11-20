/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:40:02 by rsao-pay          #+#    #+#             */
/*   Updated: 2025/11/20 13:35:31 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_find(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char )*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, ssize_t n)
{
	unsigned char	*destp;
	unsigned char	*srcp;

	if (!dst && !src)
		return (NULL);
	destp = (unsigned char *)dst;
	srcp = (unsigned char *)src;
	while (n--)
		*destp++ = *srcp++;
	return (dst);
}

char	*ft_strjoin(char *previous, const char *current)
{
	size_t	len_prev;
	size_t	len_curr;
	char	*merge;

	len_prev = 0;
	len_curr = 0;
	if (previous)
		len_prev = ft_strlen_find(previous, '\n');
	if (current)
		len_curr = ft_strlen_find(current, '\n');
	merge = (char *)malloc(len_prev + len_curr + 1);
	if (!merge)
		return (NULL);
	if (previous)
		ft_memcpy(merge, previous, len_prev);
	if (current)
		ft_memcpy(merge + len_prev, current, len_curr);
	merge[len_prev + len_curr] = '\0';
	if (previous)
		free(previous);
	return (merge);
}
