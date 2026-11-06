/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:05:35 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/27 13:54:28 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*data1;
	const unsigned char	*data2;

	data1 = (const unsigned char *)s1;
	data2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (data1[i] != data2[i])
			return (data1[i] - data2[i]);
		i++;
	}
	return (0);
}
