# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaegusa <ksaegusa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 16:21:27 by enkwak            #+#    #+#              #
#    Updated: 2025/03/18 11:24:06 by ksaegusa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/free_main.c \
       $(LEXER_DIR)/lexer.c \
       $(LEXER_DIR)/lexer_util.c \
       $(PARSER_DIR)/parser.c \
       $(PARSER_DIR)/parser_here.c\
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
       $(EXECUTER_DIR)/cmd_exec.c  \
       $(EXECUTER_DIR)/path.c \
       $(EXECUTER_DIR)/pipe.c \
       $(EXECUTER_DIR)/redirect.c \
       $(EXECUTER_DIR)/heredoc.c \
       $(EXECUTER_DIR)/manage_heredoc.c\
       $(EXPANDER_DIR)/expander.c \
       $(EXPANDER_DIR)/expander_utils.c \
       $(SIGNAL_DIR)/signals.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -I$(LIBFT_DIR)
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

.PHONY: all clean fclean re
