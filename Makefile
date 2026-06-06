NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = \
    src/main.c \
    src/lexer/lexer.c \
    src/parser/parser.c \
    src/executor/executor.c \
    src/builtins/cd.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) = $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o = %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
