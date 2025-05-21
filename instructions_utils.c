/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:41:27 by girts             #+#    #+#             */
/*   Updated: 2025/03/03 16:31:13 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

t_instructions	*create_new_node(char *value)
{
	t_instructions	*node;

	node = (t_instructions *)malloc(sizeof(t_instructions));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	if (!node->value)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_new_node(t_instructions **instructions, t_instructions *new_node)
{
	t_instructions	*current_node;

	if (!instructions || !new_node)
		return ;
	if (*instructions == NULL)
		*instructions = new_node;
	else
	{
		current_node = *instructions;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}

void	remove_node(t_instructions **instructions, t_instructions *node)
{
	t_instructions	*current_node;

	if (!instructions || !(*instructions) || !node)
		return ;
	current_node = *instructions;
	while (current_node != node)
		current_node = current_node->next;
	if (current_node == NULL)
		return ;
	if (current_node->prev)
		current_node->prev->next = current_node->next;
	else
		*instructions = current_node->next;
	if (current_node->next)
		current_node->next->prev = current_node->prev;
	free(current_node);
}

void	add_after(t_instructions **instructions, \
				t_instructions *new_node, t_instructions *after)
{
	t_instructions	*current_node;

	if (!instructions || !new_node || !after)
		return ;
	current_node = *instructions;
	while (current_node != NULL && current_node != after)
		current_node = current_node->next;
	if (current_node == NULL)
		return ;
	new_node->next = current_node->next;
	new_node->prev = current_node;
	current_node->next = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

// rra and rrb at the same time.
void	rrr(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_instructions	*new_node;

	new_node = NULL;
	rra(a, instructions, 0);
	rrb(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rrr");
		add_new_node(instructions, new_node);
	}
}
