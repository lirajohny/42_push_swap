#include "push_swap.h"
#include <stdio.h>

static void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_stack *list)
{
	t_node	*node;
	t_node	*tmp;

	if (list == NULL)
		return ;
	node = list->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(list);
}

static void	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit (-1);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (-1);
	check_args(av, ac);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = NULL;
	init_stack(a, av, ac);
	check_sorted(a, b);
	if (a->size > 3)
		b = (t_stack *)malloc(sizeof(t_stack));
	sort_stack(a, b);
	free_stacks(a, b);
	return (0);
}
