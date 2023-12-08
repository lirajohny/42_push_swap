/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:28:38 by jlira             #+#    #+#             */
/*   Updated: 2023/12/07 14:32:53 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_nbrs(unsigned long n, int arg, int *count)
{
	const char	*alpha_up = "0123456789ABCDEF";
	const char	*alpha_low = "0123456789abcdef";
	char		hex;

	if (arg == 'X')
		hex = alpha_up[n % 16];
	else if (arg == 'x')
		hex = alpha_low[n % 16];
	else if (arg == 'p')
		hex = alpha_low[n % 16];
	write (1, &hex, 1);
	(*count)++;
}

static int	ft_pointer(unsigned long d)
{
	if (d == 0)
	{
		ft_putstr("(nil)");
		return (3);
	}
	else
		return (0);
}

int	ft_puthex(unsigned long num, int arg)
{
	int	count;
	int	nbrs[16];
	int	i;

	count = 0;
	if (num == 0)
	{
		if (arg == 'p')
			return (ft_pointer(num));
		print_nbrs(num, arg, &count);
	}
	if (arg == 'p' && num != 0)
		ft_putstr("0x");
	i = 0;
	while (num > 0)
	{
		nbrs[i++] = num % 16;
		num /= 16;
	}
	while (--i >= 0)
		print_nbrs(nbrs[i], arg, &count);
	return (count);
}
