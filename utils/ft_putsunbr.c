/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:41:40 by jlira             #+#    #+#             */
/*   Updated: 2023/12/08 11:41:42 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int num)
{
	static unsigned int		count;
	unsigned int			sign;

	sign = 0;
	count = 0;
	if (num >= 10)
		ft_putunbr(num / 10);
	count += ft_putchar((num % 10) + 48);
	return (count + sign);
}
