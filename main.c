/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:23:28 by rfork             #+#    #+#             */
/*   Updated: 2019/11/02 16:54:20 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		write("error\n");
		exit();
	}
	if ((fd = open("wap_small.txt", O_RDONLY)) < 3)
	{
		write("error\n");
		exit();
	}
	if (!ft_check())
	{
		write("error\n");
		exit();
	}
	return (0);
}
