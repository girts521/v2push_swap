/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:33:10 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/20 11:35:39 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->current_position = 0;
	node->final_index = 0;
	node->push_price = 0;
	node->above_median = false;
	node->cheapest = false;
	node->target_node = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
