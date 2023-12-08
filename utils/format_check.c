/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:27:25 by jlira             #+#    #+#             */
/*   Updated: 2023/12/07 16:47:31 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(const char *arg, int i, va_list ap)
{
	if (arg[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (arg[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (arg[i + 1] == 'd' || arg[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (arg[i + 1] == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (arg[i + 1] == 'p')
		return (ft_puthex(va_arg(ap, unsigned long), 'p') + 2);
	else if (arg[i + 1] == 'x' || arg[i + 1] == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), arg[i + 1]));
	else if (arg[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}
