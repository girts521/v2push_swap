/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:30:09 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 16:31:04 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all the elements of the stack a up by one position.
//  The first element becomes the last. 
void	ra(t_list **a, t_instructions **instructions, int add)
{
	t_list			*head;
	t_instructions	*new_node;

	new_node = NULL;
	head = ft_pop(a);
	ft_lstadd_back(a, head);
	if (add == 1)
	{
		new_node = create_new_node("ra");
		add_new_node(instructions, new_node);
	}
}

// Shifts all the elements of the stack b one position upwards.
//  The first element becomes the last one. 
void	rb(t_list **b, t_instructions **instructions, int add)
{
	t_instructions	*new_node;

	new_node = NULL;
	ra(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rb");
		add_new_node(instructions, new_node);
	}
}

// ra and rb at the same time. 
void	rr(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_instructions	*new_node;

	new_node = NULL;
	ra(a, instructions, 0);
	rb(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rr");
		add_new_node(instructions, new_node);
	}
}

// Shifts all elements of the stack down one position. 
// the stack a. The last element becomes the first. 
void	rra(t_list **a, t_instructions **instructions, int add)
{
	t_list			*last;
	t_instructions	*new_node;

	new_node = NULL;
	last = remove_last(a);
	ft_lstadd_front(a, last);
	if (add == 1)
	{
		new_node = create_new_node("rra");
		add_new_node(instructions, new_node);
	}
}

// Shifts all the elements of the stack b one position downwards.
// the stack b. The last element becomes the first. 
void	rrb(t_list **b, t_instructions **instructions, int add)
{
	t_instructions	*new_node;

	new_node = NULL;
	rra(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rrb");
		add_new_node(instructions, new_node);
	}
}
