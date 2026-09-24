/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:57:44 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 20:33:23 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*search;
	t_list	*next;

	if (!lst || !del)
		return ;
	search = *lst;
	while (search != NULL)
	{
		next = search->next;
		del(search->content);
		free(search);
		search = next;
	}
	*lst = NULL;
}
