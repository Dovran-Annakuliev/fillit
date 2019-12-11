/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/12/11 20:06:29 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*arr;
	int		*arr2;
	int		i;
	int		count;

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
		if (i % 2 == 0)
			printf("x = %d\n", arr2[i]);
		else
			printf("y = %d\n", arr2[i]);
	}
	free(arr);
	free(arr2);
	return (0);
}
