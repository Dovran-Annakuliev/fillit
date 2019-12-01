/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:45:07 by rfork             #+#    #+#             */
/*   Updated: 2019/12/01 16:33:38 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_change_arr(char *tmp, int count, char **arr)
{
	int heg;
	int len;
	int i;
	int x_min;
	int y_min;

	heg = -1;
	len = -1;
	i = -1;
	x_min = 0;
	y_min = 0;
	arr = ft_chenge_arr_2(tmp, count, heg, len);
	arr = ft_change_arr_3(arr, i, heg, len);
	i = 0;
	smeshenie = 0;
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
				}
				else
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
}

char **ft_chenge_arr_2(char *tmp, int count, int heg, int len)
{
	int ret;

	ret = 0;
	arr = (char**)malloc(sizeof(char*) * (count + 1)); // создание массива строк, где строки это карты с тетрамино
	while (++heg != count + 1)
	{
		if (heg == count)
		{
			arr[heg] = NULL;
			ret++;
		}
		else
		{
			arr[heg] = (char*)malloc(sizeof(char) * 21);
			while (++len != 20)
			{
				if (tmp[ret] == '\n' && tmp[ret + 1] == '\n')
				{
					arr[heg][len] = '\0';
					ret++;
				}
				arr[heg][len] = tmp[ret++];
			}
		}
	}
	return (arr);
}

char **ft_change_arr_3(char **arr, int i, int x_min, int y_min)
{
	int j;
	int smeshenie;

	smeshenie = 0;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (!smeshenie) // нахождение минимальных координат
			{
				if (arr[i][j] == '#')
				{
					if ((i / 5) < y_min)
						y_min = i;
					if ((j % 5) < x_min)
						x_min = j;
				}
				if (!arr[i][j + 1] && !arr[i + 1][j])
					smeshenie = 1;
			}
			else // смещение по координатам
			{
				if (arr[i][j] == '#')
				{
					arr[i - y_min][j - x_min] = '#';
					arr[i][j] = '.';
				}
			}
		}
	}
	return (arr);
}
