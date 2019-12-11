/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_change_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:49:48 by rfork             #+#    #+#             */
/*   Updated: 2019/12/11 19:04:18 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int *ft_new_change_arr(char *tmp, int count, int *arr2)
{
	int i;
	int ret;
	int ret2;
	int *arr;
	int count2;

	i = -1;
	ret = 0;
	count2 = 0;
	arr = (int*)malloc(sizeof(int) * (count * 2));
	while (++i < (count * 2))
		arr[i] = 7;
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
		{
			if (((i - count2) % 5) < arr[ret])
				arr[ret] = ((i - count2) % 5);
			if ((((i - count2) % 20) / 5) < arr[ret + 1])
				arr[ret + 1] = (((i - count2) % 20) / 5);
		}
		if (tmp[i] == '\n' && tmp[i + 1] =='\n')
		{
			ret = ret + 2;
			count2++;
		}
	}
	i = -1;
	while (++i != (count * 2))
		printf("%d\n", arr[i]);
	printf("\n\n\n\n\n\n\n");
	i = -1;
	ret2 = 0;
	ret = 0;
	count2 = 0;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
		{
			arr2[ret2] = (((i - count2) % 5) - arr[ret]);
			arr2[ret2 + 1] = ((((i - count2) % 20) / 5) - arr[ret + 1]);
			ret2 = ret2 + 2;
		}
		if (tmp[i] == '\n' && tmp[i + 1] =='\n')
		{
			ret = ret + 2;
			count2++;
		}
	}
	return (arr2);
}
