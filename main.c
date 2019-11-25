/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/11/25 18:41:04 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int dve_grani;
	char **arr;
	int count;
	int x_min;
	int y_min;
	int i;
	int j;
	int smeshenie;

	if (argc != 1 || (fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "usage: ./fillit [file name]\n", 29);
		exit(0);
	}
	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp2 = ft_strjoin(tmp, buf)))
		{
			write(1, "error\n", 6);
			exit(0);
		}
		free(tmp);
		tmp = tmp2;
	}
	ret = 0;
	len = 0;
	heg = 0;
	count = 0;
	dve_grani = 0;
	while(tmp[ret])
	{
		if (tmp[ret] == '.' || tmp[ret] == '#' || (tmp[ret] == '\n' && ((len + 1)%5 == 0))) // проверка на правильность символов
		{
			if (tmp[ret] == '#')
			{
				if (!(tmp[ret - 1] == '#' || tmp[ret + 1] == '#' || tmp[ret - 5] == '#' || tmp[ret + 5] == '#')) // проверка на наличее соединений гранями
				{
					write(1, "error\n", 6);
					exit(0);
				}
				if ((tmp[ret - 1] == '#' && tmp[ret + 1] == '#') ||    // проверка на наличие нескольких соединений граней
						(tmp[ret - 5] == '#' && tmp[ret + 5] == '#') ||
						(tmp[ret - 5] == '#' || tmp[ret - 1] == '#') ||
						(tmp[ret - 5] == '#' || tmp[ret + 1] == '#') ||
						(tmp[ret - 1] == '#' || tmp[ret + 5] == '#') ||
						(tmp[ret + 1] == '#' || tmp[ret + 5] == '#'))
					dve_grani++;
				if (!(dve_grani && tmp[ret] == '\n' && tmp[ret + 1] == '\n' && heg == 3)) // вывод ошибки на грани
				{
					write(1, "error\n", 6);
					exit(0);
				}
			}
			if (tmp[ret] == '\n' && tmp[ret + 1] == '\n' && heg == 3)
			{
				ret++;
				heg = 0;
				dve_grani = 0;
				count++;
			}
			heg++;
			ret++;
			len++;
		}
		else
		{
			write(1, "error\n", 6);
			exit(0);
		}
	}
	if (count < 1 || count > 26)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	ret = 0;
	heg = 0;
	arr = (char**)malloc(sizeof(char*) * (count + 1)); // создание массива строк, где строки это карты с тетрамино
	while (heg != count + 1)
	{
		if (heg == count)
		{
			arr[heg] = NULL;
			ret++;
		}
		else
		{
			arr[heg] = (char*)malloc(sizeof(char) * 21);
			len = 0;
			while (len != 21)
			{
				if (tmp[ret] == '\n' && tmp[ret + 1] == '\n')
				{
					arr[heg][len] = '\0';
					ret++;
				}
				arr[heg][len] = tmp[ret];
				len++;
				ret++;
			}
			heg++;
		}
	}
	i = 0;
	while (arr[i])
	{
		j = 0;
		heg = 0;
		len = 0;
		x_min = 0;
		y_min = 0;
		while (arr[i][j])
		{
			if (!smeshenie) // нахождение минимальных координат
			{
				if (arr[i][j] == '\n')
				{
					len = 0;
					heg++;
				} else
				{
					if (arr[i][j] == '#')
					{
						if (i < y_min)
							y_min = i;
						if (j < x_min)
							x_min = j;
					}
					len++;
				}
				if (!arr[i][j])
					smeshenie = 1;
				j++;
			}
			else // смещение по координатам
			{
				j = 0;
				if (arr[i][j] == '#')
				{
					arr[i][j - (y_min * 5) - x_min] = '#';
					arr[i][j] = '.';
				}
				j++;
			}
		}
		i++;
	}
	i = 0; // test
	while (arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
	return (0);
}
