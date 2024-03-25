# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlira <jlira@student.42.rio>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 11:53:07 by jlira             #+#    #+#              #
#    Updated: 2024/03/25 11:53:08 by jlira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)
PUSH_SWAP = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a

all: $(NAME) $(PUSH_SWAP)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(PUSH_SWAP):
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(SRCS) $(NAME)

clean:
	$(RM) $(OBJS) $(SERVER) $(PUSH_SWAP)

fclean: clean
	$(RM) $(NAME) $(PUSH_SWAP)

re: fclean all
