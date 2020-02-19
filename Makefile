# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquence <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 18:41:39 by tquence           #+#    #+#              #
#    Updated: 2020/02/19 18:41:43 by tquence          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= ft_push_swap.c ft_valid.c ft_atoi_sw.c ft_solution.c ft_some_digits.c ft_push_swap_2.c ft_sort.c

SRC2 	= ft_push_swap.c ft_valid2.c ft_atoi_sw.c ft_checker.c ft_sort.c

OBJSFD 	= temporary

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	make -C ./includes/libft

$(NAME1): $(OBJS1) $(LIBFT)
	gcc -g $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2) $(LIBFT)
	gcc -g $(OBJS2) $(LIB_BINARY) -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJSFD)
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./includes/libft fclean

re: fclean all

