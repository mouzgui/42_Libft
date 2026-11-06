/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumouzgu <oumouzgu@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:53:11 by oumouzgu          #+#    #+#             */
/*   Updated: 2026/10/23 18:41:29 by oumouzgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clear_all(t_list *head, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&head, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = f(lst -> content);
		tmp = ft_lstnew(content);
		if (!tmp)
			return (clear_all(head, content, del));
		ft_lstadd_back(&head, tmp);
		lst = lst -> next;
	}
	return (head);
}
