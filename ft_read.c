/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:01:02 by rfork             #+#    #+#             */
/*   Updated: 2019/11/29 18:28:20 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_read(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*arr;
	char	*tmp2;

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

void	ft_check(char *tmp)
{
	int ret;
	int count;
	int dve_grani;
	int kol_resh;

	while (tmp[ret])
	{
		if (tmp[ret] == '.' || tmp[ret] == '#' || ft_check_3(tmp, ret, count))	// проверка на правильность символов
		{
			if (tmp[ret] == '#')
			{
				kol_resh++;
				dve_grani = ft_check_2(ret, tmp, dve_grani, kol_resh);
			}
			if (ft_check_3(tmp, ret, count))
			{
				ret = ret + 2;
				dve_grani = 0;
				kol_resh = 0;
				count++;
			}
			ret++;
		}
		else
			ft_error(0);
	}
	if (count < 1 || count > 26)
		ft_error(0);
}

int		ft_check_2(int ret, char *tmp, int dve_grani, int kol_resh)
{
	if (!(tmp[ret - 1] == '#' || tmp[ret + 1] == '#' || tmp[ret - 5] == '#'		// проверка на наличее соединений гранями
		|| tmp[ret + 5] == '#'))
		ft_error(0);
	if ((tmp[ret - 1] == '#' && tmp[ret + 1] == '#')							// проверка на наличие нескольких соединений граней
		|| (tmp[ret - 5] == '#' && tmp[ret + 5] == '#')
		|| (tmp[ret - 5] == '#' || tmp[ret - 1] == '#')
		|| (tmp[ret - 5] == '#' || tmp[ret + 1] == '#')
		|| (tmp[ret - 1] == '#' || tmp[ret + 5] == '#')
		|| (tmp[ret + 1] == '#' || tmp[ret + 5] == '#'))
		dve_grani++;
	if (!dve_grani && tmp[ret] == '\n' && ((ret - count + 1) % 5 == 0			// вывод ошибки по граням
		&& tmp[ret + 1] == '\n'))
		ft_error(0);
	if (kol_resh > 4)
		ft_error(0);
	return (dve_grani);
}

void	ft_error(int err)
{
	if (err == 1)
	{
		write(1, "usage: ./fillit [file name]\n", 29);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

int ft_check_3(char *tmp, int ret, int count)
{
	if (tmp[ret] == '\n' && (ret - count + 1) % 5 == 0 && tmp[ret + 1] == '\n')
		return (1);
	return (0);
}
