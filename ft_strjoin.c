/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:43:06 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/11/03 18:18:24 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(size_t start, size_t curr_len, char *res, const char *s)
{
	size_t	i;

	i = 0;
	while (start < curr_len)
	{
		res[start] = s[i];
		start++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = malloc(s1_len + s2_len + 1);
	if (!buffer)
		return (NULL);
	fill_buffer(i, s1_len, buffer, s1);
	i = s1_len;
	fill_buffer(i, (s1_len + s2_len), buffer, s2);
	buffer[s1_len + s2_len] = '\0';
	return (buffer);
}
