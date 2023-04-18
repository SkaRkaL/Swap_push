# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 03:20:23 by sakarkal          #+#    #+#              #
#    Updated: 2023/04/18 03:25:08 by sakarkal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRC = ft_atoi.c \
		ft_isdigit.c \
		ft_split.c \
		helper.c \
		helper_0.c \
		helper_1.c \
		helper_2.c \
		helper_3.c \
		helper_4.c \
		helper_5.c \
		helper_6.c \
		main.c \
		main_helper.c \
		parcer.c \
		push.c \
		push_b_to_a.c \
		rotate.c \
		rvrse-rotate.c \
		sort_3.c \
		sort_3_helper.c \
		swap.c

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = $(BONUS_SRC:.c=.o) 

all: $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o checker

$(NAME): $(OBJ)
	$(CC) $(OBJ) -g -o $(NAME)
	
	
%.o: %.c push_swap.h
	$(CC) -Wall -Wextra -Werror -g -c $< -o $@
	
clean :
	@rm -rf $(OBJ) $(BONUS_OBJ) 
	
fclean : clean
	@rm -rf $(NAME) push_swap push_swap_bonus

re : fclean all
