/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/12/21 18:22:59 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*arr;
	int		*arr2;
	int		i;
	int		count;
	t_tetr	*head;

	arr = ft_read(argc, argv);
	count = ft_count_tetrs(arr, -1, 0);
//	printf("\ncount = %d\n", count);
	arr2 = (int*)malloc(sizeof(int) * (count * 8));
	arr2 = ft_change_arr(arr, count, arr2);
	ft_strdel(&arr);
	i = -1;
	head = NULL;
	while (++i < (count * 8))
	{
		t_tetr *new;
		new = new_tetr(&head);
		new->y1 = arr2[i];
		new->x1 = arr2[++i];
		new->y2 = arr2[++i];
		new->x2 = arr2[++i];
		new->y3 = arr2[++i];
		new->x3 = arr2[++i];
		new->y4 = arr2[++i];
		new->x4 = arr2[++i];
	}
	free(arr2);
	govnokod(&head, count);
	delete_tetr(&head);
	return (0);
}
