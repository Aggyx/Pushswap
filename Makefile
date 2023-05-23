# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 15:49:16 by smagniny          #+#    #+#              #
#    Updated: 2023/05/23 17:34:12 by smagniny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

##INCLUDES
LIBFT = ./inc/libft/
INC = ./inc/libft/libft.a

##COMP
CC = gcc -Wall -Wextra -Werror

SRC = main.c mv.c mv_norm.c parse_params.c Lfunc.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC $(LIBFT)
	$(CC) $(OBJ) $(INC) -o $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
