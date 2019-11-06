/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/11/05 18:01:59 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	char		buf[BUFF_SIZE + 1];
	int ret;
	char *tmp1;
	char *tmp2;
	int len;
	int heg;

	if (argc != 1 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		write("usage: ./fillit [file name]\n");
		exit();
	}

//	if (read(fd, 1, 0)) < 0)
//	{
//		write("error\n");
//		exit();
//	}
	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp2 = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
		tmp = tmp2;
	}
	ret = 0;
	len = 0;
	heg = 0;
	while(tmp[ret])
	{
		if (tmp[ret] == '.' || tmp[ret] == '#' || (tmp[ret] == '\n' && ((len + 1)mod5 == 0)))
		{
			if (tmp[ret] = '\n' && tmp[ret + 1] == '\n' && heg == 3)
			{
				ret++;
				heg = 0;
			}
			heg++;
			ret++;
			len++;
		}
		else
		{
			write("error\n");
			exit();
		}
	}

	return (0);
}
