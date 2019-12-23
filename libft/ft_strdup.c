/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:30:43 by rfork             #+#    #+#             */
/*   Updated: 2019/12/23 14:02:22 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*des;

	len = ft_strlen(src);
	if (!(des = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		des[i] = src[i];
	des[i] = '\0';
	return (des);
}
