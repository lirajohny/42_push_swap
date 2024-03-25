/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:37 by jlira             #+#    #+#             */
/*   Updated: 2024/03/25 11:52:38 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_free(void **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

void	init_stack(t_stack *stack_a, char **av, int ac)
{
	t_node	*new;
	char	**args;
	int		i;

	i = 1;
	args = av;
	while (args[i])
	{
		new = add_node(ft_atol(args[i]), stack_a, i - 1);
		if (new == NULL)
		{
			free_stack(stack_a);
			return ;
		}
		i++;
	}
	if (ac == 2)
		ft_free((void **)args);
	put_in_order(stack_a);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	return ((long)(res * sign));
}

t_node	*add_node(int n, t_stack *p, int i)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = n;
	new_node->simple = -1;
	if (p->head == NULL)
	{
		p->head = new_node;
		p->tail = new_node;
		new_node->next = NULL;
		new_node->index = i;
	}
	else
	{
		p->tail->next = new_node;
		p->tail = new_node;
		new_node->next = NULL;
		new_node->index = i;
	}
	p->size++;
	return (new_node);
}
