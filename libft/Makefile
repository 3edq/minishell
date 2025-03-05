# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:15:57 by enkwak            #+#    #+#              #
#    Updated: 2024/10/26 21:14:33 by enkwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = .
INC_DIR = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_strlcpy.c \
		$(SRC_DIR)/ft_strlcat.c \
		$(SRC_DIR)/ft_strchr.c \
		$(SRC_DIR)/ft_strrchr.c \
		$(SRC_DIR)/ft_strnstr.c \
		$(SRC_DIR)/ft_strncmp.c \
		$(SRC_DIR)/ft_memset.c \
		$(SRC_DIR)/ft_bzero.c \
		$(SRC_DIR)/ft_memcpy.c \
		$(SRC_DIR)/ft_memchr.c \
		$(SRC_DIR)/ft_memmove.c \
		$(SRC_DIR)/ft_memcmp.c \
		$(SRC_DIR)/ft_atoi.c \
		$(SRC_DIR)/ft_isalpha.c \
		$(SRC_DIR)/ft_isdigit.c \
		$(SRC_DIR)/ft_isalnum.c \
		$(SRC_DIR)/ft_isascii.c \
		$(SRC_DIR)/ft_isprint.c \
		$(SRC_DIR)/ft_toupper.c \
		$(SRC_DIR)/ft_tolower.c \
		$(SRC_DIR)/ft_calloc.c \
		$(SRC_DIR)/ft_strdup.c \
		$(SRC_DIR)/ft_substr.c \
		$(SRC_DIR)/ft_strjoin.c \
		$(SRC_DIR)/ft_strtrim.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/ft_itoa.c \
		$(SRC_DIR)/ft_strmapi.c \
		$(SRC_DIR)/ft_striteri.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_putendl_fd.c \
		$(SRC_DIR)/ft_putnbr_fd.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re