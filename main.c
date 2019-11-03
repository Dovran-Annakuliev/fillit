/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/11/03 17:02:54 by rfork            ###   ########.fr       */
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
	tmp1 = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp2 = ft_strjoin(tmp1, buf)))
			return (-1);
		free(tmp1);
		tmp1 = tmp2;
	}

	return (0);
}
