/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:30:17 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 16:30:35 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	sa(t_list **a, t_instructions **instructions, int add)
{
	t_list			*head;
	t_list			*new_head;
	t_instructions	*new_node;

	new_node = NULL;
	if (*a && (*a)->next)
	{
		head = *a;
		new_head = head->next;
		head->next = new_head->next;
		new_head->next = head;
		*a = new_head;
	}
	if (add == 1)
	{
		new_node = create_new_node("sa");
		add_new_node(instructions, new_node);
	}
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	sb(t_list **b, t_instructions **instructions, int add)
{
	t_instructions	*new_node;

	new_node = NULL;
	sa(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("sb");
		add_new_node(instructions, new_node);
	}
}

// sa and sb at the same time. 
void	ss(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_instructions	*new_node;

	new_node = NULL;
	sa(a, instructions, 0);
	sa(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("ss");
		add_new_node(instructions, new_node);
	}
}

//  If b is not empty it takes the first element on top of b and puts it on a.
void	pa(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_list			*head;
	t_instructions	*new_node;

	new_node = NULL;
	if (*b)
	{
		head = ft_pop(b);
		ft_lstadd_front(a, head);
	}
	if (add == 1)
	{
		new_node = create_new_node("pa");
		add_new_node(instructions, new_node);
	}
}

//  If a is not empty, it takes the first element on top of a and puts it on b.
void	pb(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_list			*head;
	t_instructions	*new_node;

	new_node = NULL;
	if (*a)
	{
		head = ft_pop(a);
		ft_lstadd_front(b, head);
	}
	if (add == 1)
	{
		new_node = create_new_node("pb");
		add_new_node(instructions, new_node);
	}
}
