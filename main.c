/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:21:51 by jlira             #+#    #+#             */
/*   Updated: 2024/04/26 08:42:49 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		to_free;

	if (ac == 1)
		return (-1);
	if (ac == 2)
	{
		to_free = ac;
		av = ft_split(av[1], ' ', av[0], &ac);
	}
	check_args(av, ac);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = NULL;
	init_stack(a, av, ac);
	check_sorted(a, b);
	if (a->size > 3)
		b = (t_stack *)malloc(sizeof(t_stack));
	sort_stack(a, b);
	free_stacks(a, b);
	if (to_free == 2)
		ft_free((void **)av);
	return (0);
}
