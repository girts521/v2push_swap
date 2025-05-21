/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:32:34 by girts             #+#    #+#             */
/*   Updated: 2025/03/03 16:26:49 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Marks every node above_median (0 till size / 2)
// and rest as below median
void	set_current_position(t_list *stack)
{
	int		position;
	t_list	*current_node;
	int		mid;

	position = 0;
	current_node = stack;
	mid = ft_lstsize(stack) / 2;
	if (!stack)
		return ;
	while (current_node)
	{
		current_node->current_position = position;
		if (position <= mid)
			current_node->above_median = true;
		else
			current_node->above_median = false;
		current_node = current_node->next;
		position++;
	}
}

void	set_target_node(t_list *a, t_list *b)
{
	long	best_match;
	t_list	*stack_a;
	t_list	*target_node;

	stack_a = a;
	target_node = a;
	best_match = LONG_MAX;
	while (b)
	{
		stack_a = a;
		best_match = LONG_MAX;
		find_target(stack_a, b, &best_match, &target_node);
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (!(b->target_node->above_median))
			b->push_price += len_a - (b->target_node->current_position);
		else
			b->push_price += b->target_node->current_position;
		b = b->next;
	}
}

void	set_cheapest(t_list *b)
{
	t_list	*current_node;
	t_list	*cheapest_node;
	long	cheapest_value;

	current_node = b;
	cheapest_node = current_node;
	cheapest_value = LONG_MAX;
	while (current_node)
	{
		if (current_node->push_price < cheapest_value)
		{
			cheapest_node = current_node;
			cheapest_value = current_node->push_price;
		}
		current_node = current_node->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_list *a, t_list *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
