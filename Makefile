NAME = minishell

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SRC_DIR = srcs
LEXER_DIR = $(SRC_DIR)/lexer
PARSER_DIR = $(SRC_DIR)/parser
BUILTIN_DIR = $(SRC_DIR)/builtin
EXECUTER_DIR = $(SRC_DIR)/executer
EXPANDER_DIR = $(SRC_DIR)/expander
SIGNAL_DIR = $(SRC_DIR)/signal

SRCS = $(SRC_DIR)/main.c \
       $(LEXER_DIR)/lexer.c \
       $(LEXER_DIR)/lexer_util.c \
       $(PARSER_DIR)/parser.c \
       $(PARSER_DIR)/parser_util.c \
       $(BUILTIN_DIR)/builtin.c \
       $(BUILTIN_DIR)/builtin_cd.c \
       $(BUILTIN_DIR)/builtin_echo.c \
       $(BUILTIN_DIR)/builtin_env.c \
       $(BUILTIN_DIR)/builtin_exit.c \
       $(BUILTIN_DIR)/builtin_export.c \
       $(BUILTIN_DIR)/builtin_pwd.c \
       $(BUILTIN_DIR)/builtin_unset.c \
       $(EXECUTER_DIR)/executer.c \
       $(EXECUTER_DIR)/path.c \
       $(EXECUTER_DIR)/pipe.c \
       $(EXECUTER_DIR)/redirect.c \
       $(EXPANDER_DIR)/expander.c \
       $(SIGNAL_DIR)/signals.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -I$(LIBFT_DIR)
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,undefined -fno-omit-frame-pointer -Iinclude -I$(LIBFT_DIR)

LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

# debug: $(NAME)
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./$(NAME)

.PHONY: all clean fclean re
