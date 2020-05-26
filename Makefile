# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 17:29:02 by rfork             #+#    #+#              #
#    Updated: 2020/05/26 11:57:55 by dovran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror
NAME = fillit
SRCS = sources/main.c\
		sources/ft_read.c\
		sources/ft_check_new.c\
		sources/ft_count_tetrs.c\
		sources/ft_change_arr.c\
		sources/start.c\
		sources/new_tetr.c\
		sources/delete_tetr.c\
		sources/solver.c\
		sources/create_map.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I includes/fillit.h
LIB = -L libft -lft

all: $(NAME)

(sources)%.o: %.c
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
