/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:41:57 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/27 18:28:08 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_len(long n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*handle_buffer(long *nb, char *tmp, int *i)
{
	char	*buffer;
	int		len;

	len = get_len(*nb);
	if (*nb < 0)
		*nb *= -1;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	while (*nb > 0)
	{
		tmp[*i] = ((*nb) % 10 + '0');
		(*i)++;
		(*nb) /= 10;
	}
	return (buffer);
}

static char	*handle_zero(void)
{
	char	*buffer;

	buffer = malloc(2);
	if (!buffer)
		return (NULL);
	buffer[0] = '0';
	buffer[1] = '\0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	int		j;
	char	*buffer;
	char	tmp[20];

	nb = n;
	i = 0;
	j = 0;
	if (nb == 0)
		return (handle_zero());
	buffer = handle_buffer(&nb, tmp, &i);
	if (!buffer)
		return (NULL);
	if (n < 0)
	{
		buffer[j] = '-';
		j++;
	}
	while (i > 0)
		buffer[j++] = tmp[--i];
	buffer[j] = '\0';
	return (buffer);
}
