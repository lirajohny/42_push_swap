/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:22:44 by jlira             #+#    #+#             */
/*   Updated: 2024/04/26 08:22:45 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b->size == 0)
		return (-1);
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->size--;
	tmp->next = stack_a->head;
	stack_a->head = tmp;
	stack_a->size++;
	if (stack_a->size == 1)
		stack_a->tail = stack_a->head;
	write(1, "pa\n", 3);
	return (0);
}

int	ra(t_stack *stack_a)
{
	t_node	*node_lst;
	t_node	*node1;

	if (stack_a->size < 2 || stack_a->head == NULL)
		return (-1);
	node1 = stack_a->head;
	node_lst = stack_a->tail;
	stack_a->head = node1->next;
	node1->next = NULL;
	node_lst->next = node1;
	stack_a->tail = node1;
	write(1, "ra\n", 3);
	return (0);
}

int	sa(t_stack *stack_a)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*tmp;

	if (stack_a->size < 2)
		return (-1);
	node1 = stack_a->head;
	node2 = node1->next;
	tmp = (t_node *)malloc(sizeof(t_node));
	if (!node1 || !node2)
		return (-1);
	tmp->value = node1->value;
	tmp->simple = node1->simple;
	node1->value = node2->value;
	node1->simple = node2->simple;
	node2->value = tmp->value;
	node2->simple = tmp->simple;
	free(tmp);
	write(1, "sa\n", 3);
	return (0);
}

int	rra(t_stack *stack_a)
{
	t_node	*node_lst;
	t_node	*node1;
	t_node	*node_penultimate;

	if (stack_a->size < 2)
		return (-1);
	node_lst = stack_a->tail;
	node1 = stack_a->head;
	while (node1 && node1->next && node1->next->next != NULL)
		node1 = node1->next;
	node_penultimate = node1;
	node1 = stack_a->head;
	node_lst->next = node1;
	node_penultimate->next = NULL;
	stack_a->head = node_lst;
	stack_a->tail = node_penultimate;
	write(1, "rra\n", 4);
	return (0);
}

void	rra3(t_stack *stack_a)
{
	rra(stack_a);
	rra(stack_a);
	rra(stack_a);
}
