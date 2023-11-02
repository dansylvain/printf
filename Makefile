# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 07:30:24 by dsylvain          #+#    #+#              #
#    Updated: 2023/11/02 08:54:11 by dsylvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# version to create executable

NAME = ft_printf

CC = gcc

CFLAGS = -Ilibft

SRC = ft_printf.c ft_printf_utils.c print_funcs.c print_funcs_2.c .testermain.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f	$(OBJ)

fclean: clean
	rm	-f	$(NAME) 

re:	fclean	all

# version to create .a file

# NAME = ft_printf.a

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -Ilibft

# LDFLAGS = -Llibft -lft

# SRC = ft_printf.c ft_printf_utils.c print_funcs.c print_funcs_2.c

# OBJ = $(SRC:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	ar rcs $(NAME) $(OBJ)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm	-f	$(OBJ)

# fclean: clean
# 	rm	-f	$(NAME) 

# re:	fclean	all