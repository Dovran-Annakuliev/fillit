/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/12/14 17:46:04 by ltammie          ###   ########.fr       */
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


	i = -1;
	arr = ft_read(argc, argv);
	count = ft_check(arr);
	printf("%s", arr);
	printf("\ncount = %d\n", count);
	arr2 = (int*)malloc(sizeof(int) * (count * 8));
	arr2 = ft_change_arr(arr, count, arr2);
	while (++i != (count * 8))
	{
		if (i % 8 == 0)
			printf("\n\n");
		printf("%d", arr2[i]);
		if (i % 2 == 0)
			printf(" ", arr2[i]);
//		else
//			printf("y = %d\n", arr2[i]);
	}
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
	free(arr);
	free(arr2);

	//printing list
	printf("\nprinting list\n");
	t_tetr *tmp = head;
	while(tmp)
	{
		printf(".....................\n");
		printf("%d - %d\n", tmp->x1, tmp->y1);
		printf("%d - %d\n", tmp->x2, tmp->y2);
		printf("%d - %d\n", tmp->x3, tmp->y3);
		printf("%d - %d\n", tmp->x4, tmp->y4);
		tmp = tmp->next;
	}
	return (0);
}
