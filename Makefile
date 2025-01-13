NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = cmd_operation.c path_operation.c  pipex.c  pipex_utils2.c error_check.c  part_of_exec.c  pipex_utils.c check_in_first.c

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
