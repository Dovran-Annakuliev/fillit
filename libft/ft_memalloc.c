/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:03:09 by rfork             #+#    #+#             */
/*   Updated: 2019/12/23 14:02:22 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*arr;

	i = -1;
	if (!(arr = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (++i < size)
		arr[i] = '\0';
	return (arr);
}
