/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   govnokod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:36:22 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/21 21:09:51 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ftt_sqrt(int nb)
{
	int counter;

	counter = 1;
	while (counter < nb)
	{
		if (counter * counter >= nb)
			return (counter);
		counter++;
	}
	return (0);
}

static void		print_map(char **map, int dim)
{
	int i;
	int j;

	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}

static void		ft_free_map(char **map, int dim)
{
	int i;

	i = -1;
	while (++i < dim)
		free(map[i]);
	free(map);
}

void			govnokod(t_tetr **head, int count)
{
	int		dim;
	char	letter;
	char	**map;

	dim = ftt_sqrt(count * 4);
	letter = 'A';
	while (1)
	{
		map = create_map(dim);
		if ((solver(map, head, letter, dim)) == 1)
		{
			print_map(map, dim);
			ft_free_map(map, dim);
			break ;
		}
		ft_free_map(map, dim);
		dim++;
	}
}
