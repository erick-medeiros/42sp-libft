NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_bzero.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c
		# ft_split.c \
		# ft_itoa.c \
		# ft_strmapi.c \
		# ft_striteri.c \
		# ft_putchar_fd.c \
		# ft_putstr_fd.c \
		# ft_putendl_fd.c \
		# ft_putnbr_fd.c
OBJ = ${SRC:.c=.o}
BONUS =  _bonus.{c/h}

${NAME}:

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

all: ${NAME}

clean:
	rm -fr ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

norm:
	clear && echo "norminette" && norminette -R CheckForbiddenSourceHeader ft_*.c libft.h
test: norm
	clear && echo "tests" && gcc libft.h ft_*.c tests.c -lbsd && ./a.out

.PHONY: all clean fclean re test