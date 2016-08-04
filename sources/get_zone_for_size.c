/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_zone_for_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 16:10:48 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/02 16:17:47 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"

t_zone			*get_zone_for_size(size_t size)
{
	t_zone		*zone;
	t_zone_type	type;

	type = zone_type_for_size(size);
	zone = search_zone_for_type(type);
	if (!zone)
	{
		if (type == e_zone_type_large)
		{
			zone = create_large_zone(size);
		}
		else
		{
			zone = create_zone_for(type);
		}
		add_zone(zone);
	}
	return (zone);
}
