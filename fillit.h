/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:36 by rfork             #+#    #+#             */
/*   Updated: 2019/12/01 17:07:21 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 10000

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

int		main(int argc, char **argv);
char	*ft_read(int argc, char **argv);
void	ft_error(int err);
int		ft_check(char *tmp);
int		ft_check_2(char *tmp, int ret, int count, int dve_grani);
int		ft_check_3(int ret, char *tmp, int dve_grani, int count);
int		check_4(char *tmp, int ret, int count, int check);
char	**ft_change_arr(char *tmp, int count);
char	**ft_chenge_arr_2(char *tmp, int count, int heg, int len);
char	**ft_change_arr_3(char **arr, int x_min, int y_min);
char	**ft_change_arr_4(char **arr, int x_min, int y_min);

#endif
