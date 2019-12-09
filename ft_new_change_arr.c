/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_change_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:49:48 by rfork             #+#    #+#             */
/*   Updated: 2019/12/09 17:51:40 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int *ft_new_change_arr(char *tmp, int count, int *arr2)
{
	int i;
	int ret;
//	int ret2;
	int *arr;
//	int *arr2;

	i = -1;
	ret = 0;
	arr = (int*)malloc(sizeof(int) * (count * 2));
//	arr2 = (int*)malloc(sizeof(int) * (count * 8));
	while (tmp[++i])
	{
		if (tmp[i] == '#')
		{
			if ((i % 5) < arr[ret])
				arr[ret] = (i % 5);
			if (((i % 21) / 5) < arr[ret + 1])
				arr[ret + 1] = ((i % 21) / 5);
			if (tmp[i] == '\n' && tmp[i + 1] =='\n')
				ret = ret + 2;
		}
	}
	i = -1;
	while (i++ != (count + 8))
		printf("%d\n", arr[i]);
//	while (tmp[++i])
//	{
//		if (tmp[i] == '#')
//		{
//			arr2[ret2] = ((i % 5) - arr[ret]);
//			arr2[ret2 + 1] = ((i / 5) - arr[ret + 1]);
//		}
//		if (tmp[i] == '\n' && tmp[i + 1] =='\n')
//		{
//			ret = ret + 2;
//			ret2 = ret2 + 2;
//		}
//	}
	return (arr2);
}
