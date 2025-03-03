/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:56:27 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 16:59:11 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_three(t_instructions *current_node, \
					t_instructions **instructions, char *node1, char *node2)
{
	t_instructions	*after;
	t_instructions	*new_node;

	after = current_node->prev;
	remove_node(instructions, current_node->next->next);
	remove_node(instructions, current_node->next);
	remove_node(instructions, current_node);
	new_node = create_new_node(node1);
	add_after(instructions, new_node, after);
	after = new_node;
	new_node = create_new_node(node2);
	add_after(instructions, new_node, after);
	current_node = new_node->next;
}

void	remove_two(t_instructions *current_node, \
					t_instructions **instructions, char *node1)
{
	t_instructions	*after;
	t_instructions	*new_node;

	after = current_node->prev;
	remove_node(instructions, current_node->next);
	remove_node(instructions, current_node);
	new_node = create_new_node(node1);
	add_after(instructions, new_node, after);
	after = new_node;
	current_node = new_node->next;
}
