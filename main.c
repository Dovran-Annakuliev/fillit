/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/12/01 17:07:53 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*arr;
	char 	**arr2;
	int		i;
	int		count;

	i = 0;
	arr = ft_read(argc, argv);
	count = ft_check(arr);
	arr2 = ft_change_arr(arr, count);
	while (arr[i])
	{
		printf("%c", arr[i]);
		i++;
	}
	ft_strdel(&arr);
	return (0);
}
