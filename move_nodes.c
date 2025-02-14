/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:49:56 by girts             #+#    #+#             */
/*   Updated: 2025/02/12 10:53:33 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *get_cheapest(t_list *stack)
{
    while(stack)
    {
        if(stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (stack);
}

void r_both(t_list **a, t_list **b, t_instructions **instructions, t_list *cheapest_node)
{
    while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, instructions, 1);
	set_current_position(*a);
	set_current_position(*b);
}

void rr_both(t_list **a, t_list **b, t_instructions **instructions, t_list *cheapest_node)
{
    while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, instructions, 1);
	set_current_position(*a);
	set_current_position(*b);
}

void finish_rotation(t_list **a, t_list **b, t_instructions **instructions, t_list *target)
{
    while(*a != target->target_node)
    {
        if (target->target_node->above_median)
            ra(a, instructions, 1);
        else
            rra(a, instructions, 1);
    }
    while(*b != target)
    {
        if(target->above_median)
            rb(b, instructions, 1);
        else
            rrb(b, instructions, 1);
    }
}

void move_nodes(t_list **a, t_list **b,  t_instructions **instructions)
{
    t_list *cheapest_node;

    cheapest_node = get_cheapest(*b);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        r_both(a, b, instructions, cheapest_node);
    else if(!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
        rr_both(a, b, instructions, cheapest_node);
    finish_rotation(a, b, instructions, cheapest_node);
    pa(a, b, instructions, 1);
}
