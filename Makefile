NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c pipex_utils.c cmd_operation.c path_operation.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
