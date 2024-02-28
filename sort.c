#include "push_swap.h"

int	is_sorted(t_stack *list)
{
	t_node	*node;

	node = list->head;
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	put_in_order(t_stack *stack_a)
{
	t_node	*next_one;
	t_node	*smaller;
	int		n;

	n = 0;
	smaller = stack_a->head;
	next_one = smaller->next;
	while (n < stack_a->size)
	{
		while (next_one)
		{
			if (smaller->simple != -1)
				smaller = next_one;
			if (next_one->value < smaller->value && next_one->simple == -1)
				smaller = next_one;
			next_one = next_one->next;
		}
		if (smaller->simple == -1)
			smaller->simple = n++;
		next_one = stack_a->head;
	}
}

int	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*tmp;

	if (stack_a->size == 0)
		return (-1);
	tmp = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->size--;
	tmp->next = stack_b->head;
	stack_b->head = tmp;
	stack_b->size++;
	if (stack_b->size == 1)
		stack_b->tail = stack_b->head;
	write(1, "pb\n", 3);
	return (0);
}
