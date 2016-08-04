/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_zone_for.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 23:14:43 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 00:21:37 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"
#include "list.h"
#include "malloc.h"
#include <sys/mman.h>

void		print_zone(const t_zone *zone);

t_zone		*create_zone_for(t_zone_type type)
{
	t_zone			*zone;
	bool			*is_frees;
	void			*data;
	struct s_size	size;

	size = size_for_zone_type(type);
	data = mmap(0, size.page_size, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	if (data)
	{
//		malloc_bzero(data, sizeof(t_zone)
//					+ (size.number_of_elems * MEMBER_SIZE(t_zone, is_frees)));
		malloc_bzero(data, size.page_size);
		zone = (t_zone *)data;
		zone->size = size;
		zone->free_elems = zone->size.number_of_elems;
		zone->is_frees = (bool *)(zone + 1);
		zone->type = type;
		init_list(&(zone->list));
		is_frees = zone->is_frees;
		malloc_memset(is_frees, true, zone->size.number_of_elems);
	}
	else
		zone = NULL;
	return (zone);
}

///////////////
// free_elems where e_zone_type_large == size
///////////////

/////////
// free(ptr)
//   ((start_data) - ptr) % size_of_elem == 0 // OK
//   ----------------------------------- != 0 // NOT in this zone
/////////
