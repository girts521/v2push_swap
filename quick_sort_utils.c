/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:57:21 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 15:55:17 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_node_at_index(t_list **list, int index, t_list **prev)
{
	t_list	*current_node;
	int		i;

	i = 0;
	current_node = *list;
	while (current_node && i < index)
	{
		if (prev)
			*prev = current_node;
		current_node = current_node->next;
		i++;
	}
	if (i < index)
		return (NULL);
	return (current_node);
}
