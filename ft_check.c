/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:56:09 by rfork             #+#    #+#             */
/*   Updated: 2019/11/03 16:43:43 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check(char **argv)
{
	int fd;
	char		buf[BUFF_SIZE + 1];
	int ret;
	char *tmp1;
	char *tmp2;

	if ((fd = open("wap_small.txt", O_RDONLY)) < 3)
	{
		write("error\n");
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
	return (ft_check2(tmp1));
}
