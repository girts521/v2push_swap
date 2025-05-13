/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:58:07 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 17:31:52 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*current_node;

	if (!list->next)
		return (1);
	current_node = list;
	while (current_node->next != NULL)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

int	validate_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		{
			error();
			return (0);
		}
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (!ft_isdigit(str[i]))
			{
				error();
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	free_args(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		// if (args[i])
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
}

void	check_double_number(int content, t_list *result)
{
	t_list	*current_node;

	if (!result)
		return ;
	current_node = result;
	while (current_node != NULL)
	{
		if (current_node->value == content)
			error();
		current_node = current_node->next;
	}
}

// Removes the head from the list and returns it
t_list	*ft_pop(t_list **list)
{
	t_list	*removed;

	if (*list == NULL)
		return (NULL);
	removed = *list;
	*list = (*list)->next;
	removed->next = NULL;
	return (removed);
}
