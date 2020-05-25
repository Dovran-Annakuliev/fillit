/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/12/23 14:26:26 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*arr;
	int		*coords;
	int		i;
	int		count;
	t_tetr	*head;

	arr = ft_read(argc, argv, 0, 0);
	count = ft_count_tetrs(arr, -1, 0);
	coords = (int*)malloc(sizeof(int) * (count * 8));
	coords = ft_change_arr(arr, count, coords);
	ft_strdel(&arr);
	i = -1;
	head = NULL;
	while (++i < (count * 8))
		i = new_tetr(&head, i, coords);
	free(coords);
	govnokod(&head, count);
	delete_tetr(&head);
	return (0);
}
