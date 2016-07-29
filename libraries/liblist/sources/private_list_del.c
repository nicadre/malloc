/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_list_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:37:02 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 14:37:52 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_list.h"

void		private_list_del(t_list *prev, t_list *next)
{
	next->prev = prev;
	prev->next = next;
}
