/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:58:42 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 20:34:52 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_list_node;
	t_list	*search;

	if (!lst || !f || !del)
		return (NULL);
	search = lst;
	new_list_head = NULL;
	while (search != NULL)
	{
		new_list_node = ft_lstnew(f(search->content));
		if (!new_list_node)
		{
			ft_lstclear(&new_list_head, del);
			return (NULL);
		}
		if (!new_list_head)
			new_list_head = new_list_node;
		else
			ft_lstadd_back(&new_list_head, new_list_node);
		search = search->next;
	}
	return (new_list_head);
}
