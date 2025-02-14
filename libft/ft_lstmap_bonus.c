/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:08:11 by gkarcevs          #+#    #+#             */
/*   Updated: 2025/02/10 11:11:34 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(lst->value);
	if (!new_list)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	save = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(lst->value);
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (save);
}
