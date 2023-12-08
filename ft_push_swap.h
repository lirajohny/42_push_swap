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
