# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlira <jlira@student.42.rio>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 14:30:51 by jlira             #+#    #+#              #
#    Updated: 2023/12/07 14:54:23 by jlira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = format_check.c ft_putchar.c ft_putsunbr.c ft_putstr.c ft_putnbr.c ft_printf.c ft_puthex.c ft_strchr.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER = ft_printf.h

all:	$(NAME)

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)
	
$(NAME): $(OBJS)
	
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

