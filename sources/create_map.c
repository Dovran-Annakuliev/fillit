/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:00:56 by ltammie           #+#    #+#             */
/*   Updated: 2020/05/25 18:50:18 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** creating a NxN map (dim  = N)
*/

char	**create_map(int dim)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * dim)))
		ft_error(0);
	while (++i < dim)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * dim)))
			ft_error(0);
	}
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			map[i][j] = '.';
	}
	return (map);
}
