/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:36 by rfork             #+#    #+#             */
/*   Updated: 2019/12/21 13:54:42 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

typedef struct		s_tetr
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
	int placed;
	struct s_tetr *next;
}					t_tetr;

t_tetr	*new_tetr(t_tetr **head);

int		main(int argc, char **argv);
char	*ft_read(int argc, char **argv);
void	ft_error(int err);
//int		ft_check(char *tmp);
//int		ft_check_2(char *tmp, int ret, int count, int dve_grani);
//int		ft_check_3(int ret, char *tmp, int dve_grani, int count);
//int		check_4(char *tmp, int ret, int count, int check);
int		*ft_change_arr(char *tmp, int count, int *arr2);
int		*ft_change_arr_2(char *tmp, int *arr, int i, int ret);
int		*ft_change_arr_3(char *tmp, int *arr, int *arr2, int i);
char	**create_map(int dim);
void	govnokod(t_tetr **head, int count);
int 	solver(char **map, t_tetr **current_piece, char letter, int dim);
int		ft_count_tetrs(char *arr, int i, int count);
int		ft_check_new(char *buf, int i);

#endif
