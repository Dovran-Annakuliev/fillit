/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:45:07 by rfork             #+#    #+#             */
/*   Updated: 2019/12/01 17:09:59 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_change_arr(char *tmp, int count)
{
	int heg;
	int len;
	int x_min;
	int y_min;
	char **arr;

	heg = -1;
	len = -1;
	x_min = 0;
	y_min = 0;
	arr = ft_chenge_arr_2(tmp, count, heg, len);
	arr = ft_change_arr_3(arr, x_min, y_min);
	return (arr);
}

char	**ft_chenge_arr_2(char *tmp, int count, int heg, int len)
{
	int ret;
	char **arr;

	ret = -1;
	arr = (char**)malloc(sizeof(char*) * (count + 1));
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
				if (tmp[++ret] == '\n' && tmp[ret + 1] == '\n')
					arr[heg][len] = '\0';
				arr[heg][len] = tmp[ret];
			}
		}
	}
	return (arr);
}

char	**ft_change_arr_3(char **arr, int x_min, int y_min)
{
	int i;
	int j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == '#')
			{
				if ((j / 5) < y_min)
					y_min = (j / 5);
				if ((j / 5) < x_min)
					x_min = (j % 5);
			}
		}
	}
	arr = ft_change_arr_4(arr, x_min, y_min);
	return (arr);
}

char	**ft_change_arr_4(char **arr, int x_min, int y_min)
{
	int i;
	int j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == '#')
			{
				arr[i][j - (y_min * 5) - x_min] = '#';
				arr[i][j] = '.';
			}
		}
	}
	return (arr);
}

/*
** ft_chenge_arr_2:
** 		создание массива строк, где строки это карты с тетрамино
**
** ft_chenge_arr_2:
** 		первый if: нахождение минимальных координат
** 		           иначе смещение по минимальным координатам
*/
