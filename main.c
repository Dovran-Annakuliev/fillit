/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/12/11 18:34:00 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*arr;
	int 	*arr2;
	int		i;
//	int		j;
	int		count;

	i = -1;
	arr = ft_read(argc, argv);
	count = ft_check(arr);
	printf("%s", arr);
	printf("\ncount = %d\n", count);
	printf("\n\n\n\n\n");
	arr2 = (int*)malloc(sizeof(int) * (count * 8));
	arr2 = ft_new_change_arr(arr, count, arr2);
	while (++i != (count * 8))
		printf("%d\n", arr2[i]);
//	arr2 = ft_change_arr(arr, count);
//	while (arr2[++i])
//	{
//		j = -1;
//		while (arr2[i][++j])
//			printf("%s", arr2[i]);
//	}
	ft_strdel(&arr);
	return (0);
}
