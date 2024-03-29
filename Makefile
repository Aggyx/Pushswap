# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 15:49:16 by smagniny          #+#    #+#              #
#    Updated: 2023/06/21 12:51:11 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

##INCLUDES
LIBFT = ./inc/libft/
INC = ./inc/libft/libft.a

##COMP
CC = gcc -Wall -Wextra -Werror -pedantic

SRC = src/main.c \
		src/mv.c src/mv_norm.c \
		src/stackfunc.c src/stackfunc_.c src/stackfunc__.c \
		src/init.c \
		src/dupli.c src/index.c \
		src/cpystack.c \
		src/chainfilter.c \
		src/chunks.c src/chunks_.c \
	
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling libft..."
	@make -sC $(LIBFT)
	$(CC) $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@echo "Deleting objects..."
	rm -rf $(OBJ)

fclean: clean
	@echo "Deleting libft..."
	@make fclean -sC $(LIBFT)
	rm -f $(NAME)

re: fclean all