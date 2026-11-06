/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:17:58 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/20 15:27:46 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	zero_negative(int *n,	int fd)
{
	if (*n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (*n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (*n < 0)
	{
		write(fd, "-", 1);
		*n *= -1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	res[20];
	int		i;

	if (fd < 0)
		return ;
	zero_negative(&n, fd);
	i = 0;
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(fd, &res[i], 1);
	}
}
