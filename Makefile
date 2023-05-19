# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 15:49:16 by smagniny          #+#    #+#              #
#    Updated: 2023/05/19 16:31:25 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

##INCLUDES
LIBFT = ./inc/libft/
INC = ./inc/libft/libft.a

##COMP
CC = gcc -Wall -Wextra -Werror

SRC = main.c mv.c mv_norm.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC $(LIBFT)
	$(CC) $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	@$(CC) -Linc -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
	