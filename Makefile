NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
BONUS =  _bonus.{c/h}

${NAME}:

all:

clean:

fclean:

re:

test:
	clear && echo "norminette" && norminette -R CheckForbiddenSourceHeader ft_*
	clear && echo "tests" && gcc libft.h ft_*.c tests.c && ./a.out

.PHONY: all clean fclean re test