/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:50:14 by jlira             #+#    #+#             */
/*   Updated: 2024/03/25 11:50:16 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
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

void	ft_free(void **mat);
void	free_stack(t_stack *list);
void	init_stack(t_stack *stack_a, char **av, int ac);
long	ft_atol(const char *nptr);
void	set_index(t_stack *stack);
t_node	*add_node(int n, t_stack *p, int i);
int		is_sorted(t_stack *list);
void	sort_list(t_stack *stack_a);
void	put_in_order(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack_a);
void	radix_sort(t_stack *a, t_stack *b);
int		rra(t_stack *stack_a);
int		has_duplicate(int num, char **argv, int i);
void	check_args(char **av, int ac);
void	small_to_top(t_stack *a, t_stack *b);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	rra3(t_stack *stack_a);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
int		sa(t_stack *stack_a);
int		ra(t_stack *stack_a);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_b, t_stack *stack_a);

#endif
