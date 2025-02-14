#include "push_swap.h"

//  If there are 2 numbers, swap the first 2 elements at the top of the stack a.
void	sa(t_list **a, t_instructions **instructions, int add)
{
	t_list	*head;
	t_list	*new_head;
	t_instructions *new_node;

	new_node = NULL;
	if (*a && (*a)->next)
	{
		head = *a;
		new_head = head->next;
		head->next = new_head->next;
		new_head->next = head;
		*a = new_head;
	}
	if (add == 1)
	{
		new_node = create_new_node("sa");
		add_new_node(instructions, new_node);
	}
}

// If there are 2 numbers, swap the first 2 elements at the top of the stack b.
void	sb(t_list **b, t_instructions **instructions, int add)
{
	t_instructions *new_node;

	new_node = NULL;
	sa(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("sb");
		add_new_node(instructions, new_node);
	}
}

// sa and sb at the same time. 
void	ss(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_instructions *new_node;

	new_node = NULL;
	sa(a, instructions, 0);
	sa(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("ss");
		add_new_node(instructions, new_node);
	}
}

//  If b is not empty it takes the first element on top of b and puts it on a.
void	pa(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_list	*head;
	t_instructions *new_node;

	new_node = NULL;
	if (*b)
	{
		head = ft_pop(b);
		ft_lstadd_front(a, head);
	}
	if (add == 1)
	{
		new_node = create_new_node("pa");
		add_new_node(instructions, new_node);
	}
}

//  If a is not empty, it takes the first element on top of a and puts it on b.
void	pb(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_list	*head;
	t_instructions *new_node;

	new_node = NULL;
	if (*a)
	{
		head = ft_pop(a);
		ft_lstadd_front(b, head);
	}
	if (add == 1)
	{
		new_node = create_new_node("pb");
		add_new_node(instructions, new_node);
	}
}

// Shifts all the elements of the stack a up by one position.
//  The first element becomes the last. 
void	ra(t_list **a, t_instructions **instructions, int add)
{
	t_list	*head;
	t_instructions *new_node;

	new_node = NULL;
	head = ft_pop(a);
	ft_lstadd_back(a, head);
	if (add == 1)
	{
		new_node = create_new_node("ra");
		add_new_node(instructions, new_node);
	}
}

// Shifts all the elements of the stack b one position upwards.
//  The first element becomes the last one. 
void	rb(t_list **b, t_instructions **instructions, int add)
{
	t_instructions *new_node;

	new_node = NULL;
	ra(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rb");
		add_new_node(instructions, new_node);
	}
}

// ra and rb at the same time. 
void	rr(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_instructions *new_node;

	new_node = NULL;
	ra(a, instructions, 0);
	rb(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rr");
		add_new_node(instructions, new_node);
	}
}

// Shifts all elements of the stack down one position. 
// the stack a. The last element becomes the first. 
void	rra(t_list **a, t_instructions **instructions, int add)
{
	t_list	*last;
	t_instructions *new_node;

	new_node = NULL;
	last = remove_last(a);
	ft_lstadd_front(a, last);
	if (add == 1)
	{
		new_node = create_new_node("rra");
		add_new_node(instructions, new_node);
	}
}

// Shifts all the elements of the stack b one position downwards.
// the stack b. The last element becomes the first. 
void	rrb(t_list **b, t_instructions **instructions, int add)
{
	t_instructions *new_node;

	new_node = NULL;
	rra(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rrb");
		add_new_node(instructions, new_node);
	}
}

// rra and rrb at the same time.
void	rrr(t_list **a, t_list **b, t_instructions **instructions, int add)
{
	t_instructions *new_node;

	new_node = NULL;
	rra(a, instructions, 0);
	rrb(b, instructions, 0);
	if (add == 1)
	{
		new_node = create_new_node("rrr");
		add_new_node(instructions, new_node);
	}
}
