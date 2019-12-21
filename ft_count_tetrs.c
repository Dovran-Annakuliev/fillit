/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:14:46 by rfork             #+#    #+#             */
/*   Updated: 2019/12/21 21:04:04 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetrs(char *arr, int i, int count)
{
	int n;

	n = 0;
	while (arr[++i])
	{
		if (arr[i] == '\n')
			n++;
		if (n == 4)
		{
			count++;
			n = 0;
			if (arr[i + 1] == '\n')
				i++;
		}
	}
	if (count == 0 || count > 26)
		ft_error(0);
	return (count);
}
