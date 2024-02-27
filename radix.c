#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	max_num;

	max_num = a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit <= max_bits)
	{
		size = a->size;
		while (size-- && !is_sorted(a))
		{
			if (((a->head->simple >> bit) & 1) == 0)
				pb(b, a);
			else
				ra(a);
		}
		bit++;
		while (b->size != 0)
			pa(a, b);
	}
}
/*
void	check_little(int i, t_node *node, t_node *node_tail, t_stack *stack_a)
{
	if (i == node->value)
		return ;
	else if (i == node->next->value)
		sa(stack_a);
	else if (i == node_tail->value)
		rra(stack_a);
	else if (i == find_midle(stack_a))
		rra3(stack_a);
	else
	{
		rra(stack_a);
		rra(stack_a);
	}
}

void	little(t_stack *stack_a)
{
	t_node	*node;
	t_node	*node_tail;
	int		i;

	node = stack_a->head;
	node_tail = stack_a->tail;
	i = node->value;
	while (node->next)
	{
		if (node->next->value < i)
			i = node->next->value;
		node = node->next;
	}
	node = stack_a->head;
	check_little(i, node, node_tail, stack_a);
}

*/
