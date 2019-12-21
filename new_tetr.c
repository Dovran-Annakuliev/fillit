/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:30:23 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/21 21:13:00 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*new_tetr(t_tetr **head)
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
	new->x1 = 0;
	new->y1 = 0;
	new->x2 = 0;
	new->y2 = 0;
	new->x3 = 0;
	new->y3 = 0;
	new->x4 = 0;
	new->y4 = 0;
	new->placed = 0;
	new->next = NULL;
	return (new);
}
