# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 10:40:29 by dsylvain          #+#    #+#              #
#    Updated: 2023/11/02 11:13:10 by dsylvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_print_funcs.c ft_print_funcs_2.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:_bonus.c=_bonus.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs	$(NAME)	$(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm	-f	$(OBJ) $(OBJ_BONUS)

fclean: clean
	rm	-f	$(NAME) 

re:	fclean	all

