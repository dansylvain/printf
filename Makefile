# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 07:30:24 by dsylvain          #+#    #+#              #
#    Updated: 2023/10/31 10:06:43 by dsylvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# version to create executable

NAME = printf

CC = gcc

CFLAGS = -Ilibft

LDFLAGS = -Llibft -lft

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f	$(OBJ)

fclean: clean
	rm	-f	$(NAME) 

re:	fclean	all

#version to create .a file

# NAME = printf.a

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -Ilibft

# LDFLAGS = -Llibft -lft

# SRC = main.c

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