/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:40:44 by rfork             #+#    #+#             */
/*   Updated: 2019/12/21 19:11:40 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_check_new(char *buf, int i)
{
	int sharps;
	int edges;

	sharps = 0;
	edges = 0;
	while(buf[++i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			ft_error(0);
		if ((i + 1) % 5 == 0 && i != 20 && buf[i] != '\n')
			ft_error(0);
		if (buf[i] == '#')
		{
			sharps++;
			if ((i + 1) < 20 && buf[i + 1] == '#')
				edges += 2;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				edges += 2;
		}
	}
	if (sharps != 4 || (edges != 6 && edges != 8) || i < 20)
		return (0);
	return (1);
}
