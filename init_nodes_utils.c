/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:26:08 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 16:26:51 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_list	*stack_a, t_list *b, \
	long *best_match, t_list **target_node)
{
	while (stack_a)
	{
		if (stack_a->value > b->value && stack_a->value < (*best_match))
		{
			*best_match = stack_a->value;
			*target_node = stack_a;
		}
		stack_a = stack_a->next;
	}
}
