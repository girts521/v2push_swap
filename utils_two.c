/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:30:36 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 17:30:49 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*remove_last(t_list **list)
{
	t_list	*last_node;
	t_list	*previous_node;

	if (!list)
		return (NULL);
	if (*list == NULL)
		return (*list);
	last_node = *list;
	previous_node = *list;
	while (last_node->next != NULL)
	{
		previous_node = last_node;
		last_node = last_node->next;
	}
	previous_node->next = NULL;
	return (last_node);
}
