/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:30:23 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/23 14:22:52 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	new_tetr(t_tetr **head, int i, int *coords)
{
	t_tetr *tmp;
	t_tetr *new;

	tmp = *head;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	if (!(new = (t_tetr *)malloc(sizeof(t_tetr))))
		ft_error(1);
	if (*head)
		tmp->next = new;
	else
		*head = new;
	new->y1 = coords[i];
	new->x1 = coords[++i];
	new->y2 = coords[++i];
	new->x2 = coords[++i];
	new->y3 = coords[++i];
	new->x3 = coords[++i];
	new->y4 = coords[++i];
	new->x4 = coords[++i];
	new->placed = 0;
	new->next = NULL;
	return (i);
}
