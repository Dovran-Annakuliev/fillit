/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:55:05 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/21 20:18:42 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_tetr(t_tetr **head)
{
	t_tetr *prev = NULL;

	while ((*head)->next)
	{
		prev = *head;
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}
