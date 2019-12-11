/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:01:02 by rfork             #+#    #+#             */
/*   Updated: 2019/12/11 17:30:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int argc, char **argv)
{
	int		fd;
	char	buf[546];
	int		ret;
	char	*arr;

	fd = 0;
	if (argc != 2 || (((fd = open(argv[1], O_RDONLY)) < 0)
		&& (read(fd, buf, 0)) < 0))
		ft_error(1);
	ret = read(fd, buf, 546);
	printf("ret = %d\n", ret);
	if (ret < 20 || ret > 545)
		ft_error(0);
	buf[ret] = '\0';
	if(!(arr = ft_strdup(buf)))
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
