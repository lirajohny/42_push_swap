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
