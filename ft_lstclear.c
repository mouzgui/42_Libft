/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:37:10 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/21 15:32:59 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*prev;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		prev = curr;
		curr = curr -> next;
		del(prev -> content);
		free(prev);
	}
	*lst = NULL;
}
