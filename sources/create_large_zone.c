/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_large_zone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 14:32:33 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/02 15:24:39 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"
#include "list.h"
#include <sys/mman.h>

t_zone				*create_large_zone(size_t size)
{
	t_large_zone	*zone;
	void			*data;

	data = mmap(0, sizeof(*zone) + sizeof(*(zone->is_frees)) + size,
				PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	zone = NULL;
	if (data)
	{
		malloc_bzero(data, (sizeof(*zone) + 1));
		zone = (t_large_zone *)data;
		zone->free_elems = 1;
		zone->size.page_size = size;
		zone->size.number_of_elems = 1;
		zone->type = e_zone_type_large;
		init_list(&(zone->list));
		zone->is_frees = (bool *)(zone + 1);
		*(zone->is_frees) = true;
	}
	return ((t_zone *)zone);
}
