/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:26:31 by girts             #+#    #+#             */
/*   Updated: 2025/03/03 18:12:33 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stack(t_list *stack)
// {
// 	t_list *current_node;

// 	current_node = stack;
// 	ft_printf("Printing stack\n");
// 	while(current_node)
// 	{
// 		ft_printf("%d\n", current_node->final_index);
// 		current_node = current_node->next;
// 	}
// }

void	parse_add(char **args, t_list **a)
{
	int		i;
	t_list	*new_node;
	long	value;

	i = 0;
	while (args[i])
	{
		if (validate_digits(args[i]))
		{
			value = ft_atoi(args[i]);
			if (value > INT_MAX || value < INT_MIN)
				error();
			check_double_number((int)value, *a);
			new_node = ft_lstnew((int)value);
			ft_lstadd_back(a, new_node);
		}
		i++;
	}
}

void	parse_args(int argc, char **argv, t_list **a)
{
	char	**args;
	int		i;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			error();
		parse_add(args, a);
		free_args(args);
		i++;
	}
}

void	optimize_and_print(t_instructions	**instructions)
{
	t_instructions *current_node;
	t_instructions *next_node;

	current_node = *instructions;
	// optimize(instructions);
	while (current_node != NULL)
	{
		next_node = current_node->next;
		ft_printf("%s\n", current_node->value);
		free(current_node->value);
		free(current_node);
		current_node = next_node;
	}
}

int	main(int argc, char **argv)
{
	t_list			*a;
	t_list			*b;
	t_instructions	*instructions;
	int				length;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (argc < 2)
		error();
	parse_args(argc, argv, &a);
	if (a == NULL)
		return (0);
	if (is_sorted(a))
		return (1);
	length = ft_lstsize(a);
	if (length <= 5)
		sort_small(&a, &b, &instructions, length);
	else
		push_swap(&a, &b, &instructions);
	optimize_and_print(&instructions);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	free(a);
	free(b);
	// ft_lstclear(instructions, NULL);
	// // free(instructions);
	// ft_lstclear(&instructions, NULL);
	return (1);
}
