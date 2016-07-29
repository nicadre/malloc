/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_list_del_entry.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:38:00 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 15:02:55 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_list.h"

void		private_list_del_entry(t_list *entry)
{
	private_list_del(entry->prev, entry->next);
}
