/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:56:22 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 17:21:00 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_list *lst)
{
	int		min;
	int		pos;
	int		min_pos;
	t_list	*current;

	min = lst->value;
	pos = 0;
	min_pos = 0;
	current = lst;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_to_top(t_list **lst, int pos, t_instructions **instructions)
{
	while (pos > 0)
	{
		ra(lst, instructions, 1);
		pos--;
	}
}

void	sort_four(t_list **a, t_list **b, t_instructions **instructions)
{
	int	min_pos;

	min_pos = find_min_position(*a);
	rotate_to_top(a, min_pos, instructions);
	pb(a, b, instructions, 1);
	sort_three(a, instructions);
	pa(a, b, instructions, 1);
}

void	sort_five(t_list **a, t_list **b, t_instructions **instructions)
{
	int	min_pos;

	min_pos = find_min_position(*a);
	rotate_to_top(a, min_pos, instructions);
	pb(a, b, instructions, 1);
	min_pos = find_min_position(*a);
	rotate_to_top(a, min_pos, instructions);
	pb(a, b, instructions, 1);
	sort_three(a, instructions);
	pa(a, b, instructions, 1);
	pa(a, b, instructions, 1);
}

int	sort_small(t_list **a, t_list **b, t_instructions **instructions, int size)
{
	if (size == 2)
	{
		sa(a, instructions, 1);
		return (1);
	}
	if (size == 3)
		sort_three(a, instructions);
	if (size == 4)
		sort_four(a, b, instructions);
	if (size == 5)
		sort_five(a, b, instructions);
	return (0);
}
