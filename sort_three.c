/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:21:08 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 17:23:46 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_higher(t_list **list, t_instructions **instructions)
{
	t_list	*top;
	t_list	*middle;
	t_list	*bottom;

	top = *list;
	middle = top->next;
	bottom = middle->next;
	if (middle->value > bottom->value)
	{
		sa(list, instructions, 1);
		rra(list, instructions, 1);
		return ;
	}
	else if (bottom->value > top->value)
	{
		sa(list, instructions, 1);
		return ;
	}
	else if (bottom->value < top->value)
	{
		ra(list, instructions, 1);
		return ;
	}
}

void	top_lower(t_list **list, t_instructions **instructions)
{
	t_list	*top;
	t_list	*middle;
	t_list	*bottom;

	top = *list;
	middle = top->next;
	bottom = middle->next;
	if (bottom->value > top->value)
	{
		sa(list, instructions, 1);
		ra(list, instructions, 1);
		return ;
	}
	else if (bottom->value < top->value)
	{
		rra(list, instructions, 1);
		return ;
	}
}

int	sort_three(t_list **list, t_instructions **instructions)
{
	t_list	*top;
	t_list	*middle;

	if (is_sorted(*list))
		return (1);
	top = *list;
	middle = top->next;
	if (top->value > middle->value)
	{
		top_higher(list, instructions);
		return (1);
	}
	else if (top->value < middle->value)
	{
		top_lower(list, instructions);
		return (1);
	}
	return (0);
}
