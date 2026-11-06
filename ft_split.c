/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:35:33 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/31 19:19:44 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_tokens(const char *s, char c)
{
	int	i;
	int	tokens;

	i = 0;
	tokens = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			tokens++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (tokens);
}

static char	**free_buffer(char **buffer, int *j)
{
	while (*j > 0)
	{
		(*j)--;
		free(buffer[*j]);
	}
	free(buffer);
	return (NULL);
}

static char	*fill_buffer(int start, int end, const char *s)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(end - start + 1);
	if (!buffer)
		return (NULL);
	while (end > start)
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	**fill_arr(const char *s, char c, char **arr)
{
	int		start;
	int		end;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		arr[j] = fill_buffer(start, end, s);
		if (!arr[j])
			return (free_buffer(arr, &j));
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((get_tokens(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_arr(s, c, arr));
}
