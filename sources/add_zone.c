/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 23:40:12 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/30 23:41:50 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "t_zones.h"

void		add_zone(t_zone *zone)
{
	if (zone)
	{
		list_add_tail(&(zone->list), &(g_zones[zone->type].list));
	}
}
