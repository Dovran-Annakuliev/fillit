# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 17:29:02 by rfork             #+#    #+#              #
#    Updated: 2019/12/18 14:09:29 by rfork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror -g
NAME = fillit
SRCS = main.c ft_read.c ft_check.c ft_change_arr.c govnokod.c new_tetr.c solver.c create_map.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I fillit.h
LIB = -L libft -lft

all: $(NAME)

%.o: %.c
		$(GCC) -c $<

lib:
        make -C libft

$(NAME): $(OBJS) lib
		$(GCC) $(OBJS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
        make -C libft fclean

re: fclean all
