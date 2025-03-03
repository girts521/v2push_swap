/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:36:41 by gikarcev          #+#    #+#             */
/*   Updated: 2025/02/20 11:18:20 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_list(t_list *original, t_list **copy)
{
	t_list	*new_node;
	t_list	*current_node;

	current_node = original;
	while (current_node != NULL)
	{
		new_node = ft_lstnew(current_node->value);
		// ft_printf("new node: %d\n", new_node->value);
		ft_lstadd_back(copy, new_node);
		current_node = current_node->next;
	}
}

void	index_list(t_list **original, t_list **sorted)
{
	t_list	*current_original;
	t_list	*current_sorted;
	int		count;

	current_original = *original;
	while (current_original != NULL)
	{
		count = 0;
		current_sorted = *sorted;
		while (current_sorted != NULL)
		{
			if (current_original->value == current_sorted->value)
				current_original->value = count;
			count++;
			current_sorted = current_sorted->next;
		}
		current_original = current_original->next;
	}
}