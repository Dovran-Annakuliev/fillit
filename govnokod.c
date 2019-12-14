/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   govnokod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:36:22 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/14 19:36:22 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

static void	print_map(char **map, int dim)
{
	int i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		i++;
	}
}

void	gonokod(t_tetr **head)
{
	int		dim;
	char	letter;
	char	**map;

	dim = 5;
	letter = 'A';
	map = create_map(dim);
	solver(map, head, letter, dim);
	print_map(map, dim);

}
