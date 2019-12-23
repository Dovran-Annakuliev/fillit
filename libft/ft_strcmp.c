/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:26:37 by rfork             #+#    #+#             */
/*   Updated: 2019/12/23 14:02:22 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int f;

	i = 0;
	f = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (f == 0))
	{
		f = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (((s1[i] != '\0') && (s2[i] == '\0')) || ((s1[i] == '\0')
	&& (s2[i] != '\0')))
		f = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (f);
}
