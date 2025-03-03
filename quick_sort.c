/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:55:01 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 15:56:01 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **list, int index1, int index2)
{
	t_list	*prev1;
	t_list	*prev2;
	t_list	*node1;
	t_list	*node2;
	t_list	*temp;

	if (index1 == index2)
		return ;
	prev1 = NULL;
	prev2 = NULL;
	node1 = get_node_at_index(list, index1, &prev1);
	node2 = get_node_at_index(list, index2, &prev2);
	if (!node1 || !node2)
		return ;
	if (prev1)
		prev1->next = node2;
	else
		*list = node2;
	if (prev2)
		prev2->next = node1;
	else
		*list = node1;
	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
}

static int	pivot(t_list **list, int start, int end)
{
	t_list	*pivot;
	t_list	*current_node;
	int		swap_idx;
	int		i;

	i = 0;
	pivot = get_node_at_index(list, start, NULL);
	if (!pivot)
		return (-1);
	swap_idx = start;
	i = start + 1;
	while (i <= end)
	{
		current_node = get_node_at_index(list, i, NULL);
		if (!current_node)
			return (-1);
		if (pivot->value > current_node->value)
		{
			swap_idx++;
			swap(list, swap_idx, i);
		}
		i++;
	}
	swap(list, start, swap_idx);
	return (swap_idx);
}

t_list	**quick_sort(t_list **list, int left, int right)
{
	int	pivot_idx;

	if (left < right)
	{
		pivot_idx = pivot(list, left, right);
		if (pivot_idx < 0)
			return (NULL);
		quick_sort(list, left, pivot_idx - 1);
		quick_sort(list, pivot_idx + 1, right);
	}
	return (list);
}
