#include "push_swap.h"

void print_stack(t_list *stack)
{
	t_list *current_node;
	current_node = stack;
	ft_printf("Printing stack\n");
	while(current_node)
	{
		ft_printf("%d\n", current_node->value);
		current_node = current_node->next;
	}
}


void parse_add(char **args, t_list **a)
{
	int	i;
	t_list *new_node;
	long	value;

	i = 0;
	while(args[i])
	{
		if(validate_digits(args[i]))
		{
			value = ft_atoi(args[i]);
			if (value > INT_MAX || value < INT_MIN)
				error();
			check_double_number((int)value, *a);
			new_node = ft_lstnew((int)value);
			ft_lstadd_back(a, new_node);
			// print_stack(*a);
		}
		i++;
	}
}

void parse_args(int argc, char **argv, t_list **a)
{
	char **args;
	int	i;

	i = 1;
	while(i < argc)
	{
		args = ft_split(argv[i], ' ');
		if(!args)
			error();
		parse_add(args, a);
		free_args(args);
		i++;
	}
}
int main(int argc, char **argv)
{
	
	t_list	*a;
	t_list	*b;
	t_instructions *instructions;
	int		length;

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
	// print_stack(a);
	optimize(&instructions);
	while (instructions != NULL)
	{
		ft_printf("%s\n", instructions->value);
		instructions = instructions->next;
	}
	return (1);
}
