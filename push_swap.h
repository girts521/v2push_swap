/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:51:08 by gikarcev          #+#    #+#             */
/*   Updated: 2025/03/03 17:22:57 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_instructions
{
	struct s_instructions	*next;
	struct s_instructions	*prev;
	char					*value;
}							t_instructions;

int				validate_digits(char *str);
void			free_args(char	**args);
void			check_double_number(int content, t_list *result);
void			error(t_list *a, t_list *b);
void			clean_up(t_list *a, t_list *b);
int				sort_three(t_list **list, t_instructions **instructions);
int				sort_small(t_list **a, t_list **b, \
							t_instructions **instructions, int size);
int				is_sorted(t_list *list);
void			sa(t_list **a, t_instructions **instructions, int add);
void			sb(t_list **b, t_instructions **instructions, int add);
void			ss(t_list **a, t_list **b, \
					t_instructions **instructions, int add);
void			pa(t_list **a, t_list **b, \
					t_instructions **instructions, int add);
void			pb(t_list **a, t_list **b, \
					t_instructions **instructions, int add);
void			ra(t_list **a, t_instructions **instructions, int add);
void			rb(t_list **b, t_instructions **instructions, int add);
void			rr(t_list **a, t_list **b, \
					t_instructions **instructions, int add);
void			rra(t_list **a, t_instructions **instructions, int add);
void			rrb(t_list **b, t_instructions **instructions, int add);
void			rrr(t_list **a, t_list **b, \
					t_instructions **instructions, int add);
t_list			*ft_pop(t_list **list);
t_list			*remove_last(t_list **list);
void			init_nodes(t_list *a, t_list *b);
void			move_nodes(t_list **a, t_list **b, \
							t_instructions **instructions);
void			push_swap(t_list **a, t_list **b, \
							t_instructions **instructions);
void			set_current_position(t_list *a);
t_list			*find_smallest(t_list *stack);
t_instructions	*create_new_node(char *value);
void			add_new_node(t_instructions **instructions, \
								t_instructions *new_node);
void			remove_node(t_instructions **instructions, \
							t_instructions *node);
void			add_after(t_instructions **instructions, \
							t_instructions *new_node, t_instructions *after);
void			optimize(t_instructions **instructions);
t_list			**quick_sort(t_list **list, int left, int right);
t_list			*get_node_at_index(t_list **list, int index, t_list **prev);
void			index_list(t_list **original, t_list **sorted);
void			copy_list(t_list *original, t_list **copy);
void			print_stack(t_list *stack);
void			find_target(t_list	*stack_a, t_list *b, \
							long *best_match, t_list **target_node);
void			remove_three(t_instructions *current_node, \
					t_instructions **instructions, char *node1, char *node2);
void			remove_two(t_instructions *current_node, \
						t_instructions **instructions, char *node1);

#endif
