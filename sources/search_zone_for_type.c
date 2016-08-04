/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_zone_for_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 15:57:48 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/02 17:01:47 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"

t_zone		*search_zone_for_type(t_zone_type type)
{
	t_zone	*entry;
	t_list	*pos;

	if (type == e_zone_type_large)
		return (NULL);
	pos = g_zones[type].list.next;
	while (pos != &(g_zones[type].list))
	{
		entry = LIST_ENTRY(pos, t_zone, list);
		if (entry->free_elems > 0)
			return (entry);
		pos = pos->next;
	}
	return (NULL);
}
