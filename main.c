/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/11/24 17:05:35 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	char		buf[BUFF_SIZE + 1];
	int ret;
	char *tmp;
	char *tmp2;
	int len;
	int heg;

	if (argc != 1 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "usage: ./fillit [file name]\n, 29");
		exit(1);
	}
	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp2 = ft_strjoin(tmp, buf)))
		{
			write("error\n");
			exit(1);
		}
		free(tmp);
		tmp = tmp2;
	}
	ret = 0;
	len = 0;
	heg = 0;
	while(tmp[ret])
	{
		if (tmp[ret] == '.' || tmp[ret] == '#' || (tmp[ret] == '\n' && ((len + 1)%5 == 0)))
		{
			if (tmp[ret] == '#')
				if (!(tmp[ret - 1] == '#' || tmp[ret + 1] == '#' || tmp[ret - 5] == '#' || tmp[ret + 5] == '#'))
				{
					write("error\n");
					exit(1);
				}
			if (tmp[ret] == '\n' && tmp[ret + 1] == '\n' && heg == 3)
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
			exit(1);
		}
	}
	return (0);
}
