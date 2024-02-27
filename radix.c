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
	if (check->simple == 0 || (b && ((b->head->simple == 0) && check->simple == 1)))
		return ;
	else if (check->next->simple == 0 || (b && (b->head->simple == 0) && check->next->simple == 1))
		sa(a);
	else if (a->tail->simple == 0 || (b && (b->head->simple == 0) && a->tail->simple == 1))
		rra(a);
	else if (check->next->next->simple == 0 || (b &&(b->head->simple == 0) && check->next->next->simple == 1))
		rra3(a);
	else
	{
		printf("A: simple is %i -> nummber is %li\n", check->simple, check->value);
		printf("B : simple is %i -> nummber is %li\n", b->head->simple, b->head->value);
		rra(a);
		rra(a);
	}
}

