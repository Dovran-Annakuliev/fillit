/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:00:56 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/14 18:20:01 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** creating a NxN map (dim  = N)
*/

char **create_map(int dim)
{
	int i;
	int j;
	char **map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * dim)))
		ft_error(1);
	while (i < dim)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * dim)))
			ft_error(1);
		i++;
	}
	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}