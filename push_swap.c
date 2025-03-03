/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:12:44 by girts             #+#    #+#             */
/*   Updated: 2025/03/03 15:48:10 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the pointer to the node with the smallest value in a stack
t_list	*find_smallest(t_list *stack)
{
	t_list	*current_node;
	t_list	*smallest;

	current_node = stack;
	smallest = current_node;
	while (current_node)
	{
		if (current_node->value < smallest->value)
			smallest = current_node;
		current_node = current_node->next;
	}
	return (smallest);
}

void	push_swap(t_list **a, t_list **b, t_instructions **instructions)
{
	int		lst_size;
	t_list	*smallest;
	t_list	*sorted;

	sorted = NULL;
	lst_size = ft_lstsize(*a);
	copy_list(*a, &sorted);
	quick_sort(&sorted, 0, lst_size - 1);
	index_list(a, &sorted);
	while (lst_size > 3)
	{
		pb(a, b, instructions, 1);
		lst_size = ft_lstsize(*a);
	}
	sort_small(a, b, instructions, ft_lstsize(*a));
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b, instructions);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, instructions, 1);
	else
		while (*a != smallest)
			rra(a, instructions, 1);
}
