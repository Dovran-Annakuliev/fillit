/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:45:07 by rfork             #+#    #+#             */
/*   Updated: 2019/12/09 16:49:45 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_change_arr(char *tmp, int count)
{
	int heg;
	int len;
	int ret;
	int *arr2;
	char **arr;

	heg = -1;
	len = -1;
	ret = 0;
	arr2 = (int*)malloc(sizeof(int) * 52);
	arr = ft_chenge_arr_2(tmp, count, heg, len);
	arr = ft_change_arr_3(arr, ret, arr2);
	free(arr2);
	arr2 = NULL;
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

char	**ft_change_arr_3(char **arr, int ret, int *arr2)
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
				if ((j % 5) < arr2[ret])
					arr2[ret] = (j % 5);
				if ((j / 5) < arr2[ret + 1])
					arr2[ret + 1] = (j / 5);
			}
		}
		ret = ret + 2;
	}
	ret = 0;
	arr = ft_change_arr_4(arr, ret, arr2);
	return (arr);
}

char	**ft_change_arr_4(char **arr, int ret, int *arr2)
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
				arr[i][j - (arr2[ret + 1] * 5) - arr2[ret]] = '#';
				arr[i][j] = '.';
			}
		}
		ret = ret + 2;
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
