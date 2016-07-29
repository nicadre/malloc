/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_list_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:35:41 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 14:36:50 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_list.h"

void		private_list_add(t_list *new, t_list *prev, t_list *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
