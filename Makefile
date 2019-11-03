# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfork <rfork@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 17:29:02 by rfork             #+#    #+#              #
#    Updated: 2019/11/02 16:39:51 by rfork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Wextra -Werror
NAME = fillit
SRCS = main.c
OBJS = $(SRCS:.c=.o)
HEAD = -c -I fillit.h
LIB = -L libft -lft

all: $(NAME)

%.o: %.c
		$(GCC) -c $<

$(NAME): $(OBJS)
		make -C libft
		$(GCC) $(OBJS) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
        make -C libft fclean

re: fclean all
