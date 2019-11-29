/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:36 by rfork             #+#    #+#             */
/*   Updated: 2019/11/25 00:17:14 by null             ###   ########.fr       */
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

int	main(int argc, char **argv);
void	ft_error(int err);
void	ft_check(char *tmp);
int		ft_check_2(int ret, char *tmp, int dve_grani, int kol_resh);
int		ft_check_3(char *tmp, int ret, int count);


#endif
