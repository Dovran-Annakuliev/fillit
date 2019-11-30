/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:01:02 by rfork             #+#    #+#             */
/*   Updated: 2019/11/30 16:49:36 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*arr;
	char	*tmp2;

	fd = 0;
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)
		&& (read(fd, buf, 0)) < 0))
		ft_error(1);
	arr = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp2 = ft_strjoin(arr, buf)))
			ft_error(0);
		free(arr);
		arr = tmp2;
	}
	return (arr);
}

void	ft_error(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./fillit target_file\n", 29);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
