/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rj>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:23:03 by jlira             #+#    #+#             */
/*   Updated: 2024/04/26 08:23:04 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	small_to_top(t_stack *a, t_stack *b)
{
	t_node	*check;

	check = a->head;
	if (check->simple == 0 || (b->size == 1 && check->simple == 1))
		return ;
	else if (check->next->simple == 0
		|| (b->size == 1 && check->next->simple == 1))
		sa(a);
	else if (a->tail->simple == 0 || (b->size == 1 && a->tail->simple == 1))
		rra(a);
	else
	{
		ra(a);
		ra(a);
	}
}
