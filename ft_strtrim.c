/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:45:19 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/24 19:03:47 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*handle_empty(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static void	start_end(char const *s, char const *s2, size_t *str, size_t *end)
{
	int		i;

	i = 0;
	*end = ft_strlen(s);
	while (s[i] && found(s2, s[i]))
		i++;
	*str = i;
	while (*end > *str && found(s2, s[*end - 1]))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*res;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (handle_empty());
	i = 0;
	start_end(s1, set, &start, &end);
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i] = s1[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
