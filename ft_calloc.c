/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:40:21 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/31 19:21:02 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			buffer_byte;
	unsigned char	*p;

	if (size == 0 || nmemb == 0)
	{
		p = malloc(1);
		return (p);
	}
	buffer_byte = nmemb * size;
	if (buffer_byte / nmemb != size)
		return (NULL);
	p = malloc(buffer_byte);
	if (!p)
		return (NULL);
	ft_bzero (p, buffer_byte);
	return (p);
}
