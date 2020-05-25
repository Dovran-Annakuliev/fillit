/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:01:02 by rfork             #+#    #+#             */
/*   Updated: 2019/12/21 21:08:23 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int argc, char **argv, int fd, int ret)
{
	char	buf[21];
	char	*arr;
	char	*temp;

	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)
		&& (read(fd, buf, 0)) < 0))
		ft_error(1);
	if (!(arr = ft_strnew(0)))
		ft_error(0);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (buf[ret - 1] != '\n' || ret < 20)
			ft_error(0);
		if (!ft_check_new(buf, -1))
			ft_error(0);
		if (!(temp = ft_strjoin(arr, buf)))
			ft_error(0);
		free(arr);
		arr = temp;
	}
	if (arr[ft_strlen(arr) - 2] == '\n')
		ft_error(0);
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
