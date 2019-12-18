/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:32:43 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/14 21:47:53 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	change_coords(t_tetr **current_piece, int shift_i, int shift_j)
{
	if ((*current_piece)->placed == 0)
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
}

/*
 * Чекаем, не вылезает ли фигурка за границы карты
 */

static int 		check_coords(t_tetr **current_piece, int dim)
{
	if (((*current_piece)->x1 >= dim) || ((*current_piece)->x2 >= dim)
		|| ((*current_piece)->x3 >= dim) || ((*current_piece)->x4 >= dim))
		return 0;
	else if ((*current_piece)->y1 < 0 || (*current_piece)->y1 >= dim)
		return 0;
	else if ((*current_piece)->y2 < 0 || (*current_piece)->y2 >= dim)
		return 0;
	else if ((*current_piece)->y3 < 0 || (*current_piece)->y3 >= dim)
		return 0;
	else if ((*current_piece)->y4 < 0 || (*current_piece)->y4 >= dim)
		return 0;
	return 1;
}

static int		place_piece(char **map, t_tetr **current_piece, char letter)
{
	if ((*current_piece)->placed == 0
		&& map[(*current_piece)->x1][(*current_piece)->y1] == '.'
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

static void		remove_piece(char **map, t_tetr **current_piece)
{
	map[(*current_piece)->x1][(*current_piece)->y1] = '.';
	map[(*current_piece)->x2][(*current_piece)->y2] = '.';
	map[(*current_piece)->x3][(*current_piece)->y3] = '.';
	map[(*current_piece)->x4][(*current_piece)->y4] = '.';
	(*current_piece)->placed = 0;
}

int 	solver(char **map, t_tetr **current_piece, char letter, int dim)
{
	int		i;
	int		j;
	int 	shift_i;
	int		shift_j;

	//ft_putchar(letter);
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if (map[i][j] == '.')
			{
				shift_i = i - (*current_piece)->x1;
				shift_j = j - (*current_piece)->y1;
				change_coords(current_piece, shift_i, shift_j);
				if (check_coords(current_piece, dim) == 1)
				{
					if (place_piece(map, current_piece, letter) == 1)
					{
						if ((*current_piece)->next != NULL)
						{
							if ((solver(map, &(*current_piece)->next, letter + 1, dim)) == 0)
								remove_piece(map, current_piece);
						} else if ((*current_piece)->placed == 1)
							return (1);
					}
				}
			}
		}
	}
	if ((*current_piece)->placed == 0)
		return (0);
	else
		return (1);
}
