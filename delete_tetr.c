/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltammie <ltammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:55:05 by ltammie           #+#    #+#             */
/*   Updated: 2019/12/21 20:02:38 by ltammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//static t_tetr	*pop_tetr(t_tetr **head)
//{
//
//}

void	delete_tetr(t_tetr **head)
{
	while ((*head)->next)
	{
		free((*head));
		(*head) = (*head)->next;
	}
}
