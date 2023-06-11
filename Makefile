# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 15:49:16 by smagniny          #+#    #+#              #
#    Updated: 2023/06/11 16:54:36 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

##INCLUDES
LIBFT = ./inc/libft/
INC = ./inc/libft/libft.a

##COMP
CC = gcc -Wall -Wextra -Werror -fsanitize=address -g

SRC = src/pusushuape.c \
		src/mv.c src/mv_norm.c \
		src/Lfunc.c src/Lfunc__.c \
		src/init.c \
		src/dupli.c src/index.c \
		src/cpystack.c \
		src/chainfilter.c \
		src/radix.c
	
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