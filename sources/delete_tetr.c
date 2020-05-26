/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:55:05 by ltammie           #+#    #+#             */
/*   Updated: 2020/05/25 18:51:11 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
