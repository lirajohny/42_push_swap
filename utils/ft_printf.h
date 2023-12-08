/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlira <jlira@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:28:14 by jlira             #+#    #+#             */
/*   Updated: 2023/12/07 16:47:59 by jlira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		format_check(const char *arg, int i, va_list ap);
int		ft_putchar(char c);
int		ft_putunbr(unsigned int nb);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_puthex(unsigned long num, int arg);
char	*ft_strchr(const char *s, int c);

#endif
