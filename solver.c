/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:32:43 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/14 19:28:23 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	change_coords(t_tetr **current_piece, int shift_i, int shift_j)
{
	(*current_piece)->x1 = (*current_piece)->x1 + shift_i;
	(*current_piece)->y1 = (*current_piece)->y1 + shift_j;
	(*current_piece)->x2 = (*current_piece)->x2 + shift_i;
	(*current_piece)->y2 = (*current_piece)->y2 + shift_j;
	(*current_piece)->x3 = (*current_piece)->x3 + shift_i;
	(*current_piece)->y3 = (*current_piece)->y3 + shift_j;
	(*current_piece)->x4 = (*current_piece)->x4 + shift_i;
	(*current_piece)->y4 = (*current_piece)->y4 + shift_j;
}

static int		place_piece(char **map, t_tetr **current_piece, char letter)
{
	if (map[(*current_piece)->x1][(*current_piece)->y1] == '.'
		&& map[(*current_piece)->x2][(*current_piece)->y2] == '.'
		&& map[(*current_piece)->x3][(*current_piece)->y3] == '.'
		&& map[(*current_piece)->x4][(*current_piece)->y4] == '.')
	{
		map[(*current_piece)->x1][(*current_piece)->y1] = letter;
		map[(*current_piece)->x2][(*current_piece)->y2] = letter;
		map[(*current_piece)->x3][(*current_piece)->y3] = letter;
		map[(*current_piece)->x4][(*current_piece)->y4] = letter;
		(*current_piece)->placed = 1;
		return (1);
	}
	return (0);
}

void 	solver(char **map, t_tetr **current_piece, char letter, int dim)
{
	int		i;
	int		j;
	int 	shift_i;
	int		shift_j;

	printf("here");
	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (map[i][j] == '.')
			{
				shift_i = i - (*current_piece)->x1;
				shift_j = j - (*current_piece)->x2;
				change_coords(current_piece, shift_i, shift_j);
				if (place_piece(map, current_piece, letter) == 1)
					solver(map, &(*current_piece)->next, letter + 1, dim);
				else
					j++;
			}
			else
				j++;
		}
		i++;
	}
}
