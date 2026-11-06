/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:12:25 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/27 18:23:34 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	while (j < i)
	{
		dst[j] = s[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
