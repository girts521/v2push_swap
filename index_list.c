/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:36:41 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 15:11:45 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Does what it says, is used in a different file. (push_swap)
void	copy_list(t_list *original, t_list **copy)
{
	t_list	*new_node;
	t_list	*current_node;

	current_node = original;
	while (current_node != NULL)
	{
		new_node = ft_lstnew(current_node->value);
		ft_lstadd_back(copy, new_node);
		current_node = current_node->next;
	}
}

//Goes over the sorted list and changes the values of the 
//original list with the index of its value in the sorted list
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
