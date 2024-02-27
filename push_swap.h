#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // retirar
# include "stdbool.h"

typedef struct l_node
{
	long							value;
	int								index;
	int								simple;
	struct l_node					*next;
}									t_node;

typedef struct l_stack
{
	t_node							*head;
	t_node							*tail;
	int								size;
}									t_stack;

void		ft_free(void **mat);
void		free_stack(t_stack *list);
void		init_stack(t_stack *stack_a, char **av, int ac);
long		ft_atol(const char *nptr);
void		set_index(t_stack *stack);
t_node		*add_node(int n, t_stack *p, int i);
int			is_sorted(t_stack *list);
void		sort_list(t_stack *stack_a);
void		put_in_order(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack_a);
void	radix_sort(t_stack *a, t_stack *b);
int		rra(t_stack *stack_a);
int	has_duplicate(int num, char **argv, int i);
int	ft_isdigit(int c);
void	check_args(char **av, int ac);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
/*
int	find_midle(t_stack *stack_a);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	little(t_stack *stack_a);
void	little(t_stack *stack_a);*/

int		sa(t_stack *stack_a);
//int		sb(t_stack *stack_b);
//int		ss(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack *stack_a);
//int		rb(t_stack *stack_b);
//int		rr(t_stack *stack_a, t_stack *stack_b);
//int		rrb(t_stack *stack_b);
//int		rrr(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_b, t_stack *stack_a);
//void	rra3(t_stack *stack_a);

#endif
