/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 23:42:11 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/30 23:44:43 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "t_zones.h"

void		del_zone(t_zone *zone)
{
	if (zone)
	{
		list_del(&(zone->list));
		// munmap (zone)
	}
}
