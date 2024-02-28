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
	//printf("B: i got %li which position should be %i\n", stack_b->head->value, stack_b->head->simple);
	write(1, "pb\n", 3);
	return (0);
}
/*
int	sb(t_stack *stack_b)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*tmp;

	if (stack_b->size < 2)
		return (-1);
	node1 = stack_b->head;
	node2 = node1->next;
	tmp = (t_node *)malloc(sizeof(t_node));
	if (!node1 || !node2)
		return (-1);
	tmp->value = node1->value;
	node1->value = node2->value;
	node2->value = tmp->value;
	free(tmp);
	write(1, "sb\n", 3);
	return (0);
}



int	rb(t_stack *stack_b)
{
	t_node	*node_lst;
	t_node	*node1;

	if (stack_b->size < 2 || stack_b->head == NULL)
		return (-1);
	node1 = stack_b->head;
	node_lst = stack_b->tail;
	stack_b->head = node1->next;
	node1->next = NULL;
	node_lst->next = node1;
	stack_b->tail = node1;
	write(1, "rb\n", 3);
	return (0);
}

int	rrb(t_stack *stack_b)
{
	t_node	*node_lst;
	t_node	*node1;
	t_node	*node_penultimate;

	if (stack_b->size < 2)
		return (-1);
	node_lst = stack_b->tail;
	node1 = stack_b->head;
	while (node1 && node1->next->next != NULL)
		node1 = node1->next;
	node_penultimate = node1;
	node1 = stack_b->head;
	node_lst->next = node1;
	node_penultimate->next = NULL;
	stack_b->head = node_lst;
	write(1, "rrb\n", 4);
	return (0);
}*/
