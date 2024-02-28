#include "push_swap.h"

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
