/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:55:05 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/21 21:03:28 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_tetr(t_tetr **head)
{
	t_tetr *prev;

	prev = NULL;
	while ((*head)->next)
	{
		prev = *head;
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}
