# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarazicchieri <sarazicchieri@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 23:36:43 by sarazicchie       #+#    #+#              #
#    Updated: 2022/11/01 15:48:53 by sarazicchie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
NAME	= push_swap

OBJ_PATH = obj/

SRC		= check_main.c check_input.c utils_check_input.c \
		start.c stack.c swap.c push.c rotate.c reverse_rotate.c \
		sorting_small_nb.c sorting.c \
		position.c cost.c do_move.c \
		utils.c ft_split.c

OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re