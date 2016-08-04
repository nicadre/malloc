/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_zone_for.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 23:14:43 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 12:29:06 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"
#include "list.h"
#include "malloc.h"
#include <sys/mman.h>

static void	init_elems(struct s_elem *elems, size_t size)
{
	while (size--)
	{
		elems[size].is_free = true;
		elems[size].size = 0;
	}
}

t_zone		*create_zone_for(t_zone_type type)
{
	t_zone			*zone;
	struct s_elem	*elems;
	void			*data;
	struct s_size	size;

	size = size_for_zone_type(type);
	data = mmap(0, size.page_size, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	if (data)
	{
		malloc_bzero(data, sizeof(t_zone)
					+ (size.number_of_elems * MEMBER_SIZE(t_zone, elems)));
		zone = (t_zone *)data;
		zone->size = size;
		zone->free_elems = zone->size.number_of_elems;
		zone->elems = (struct s_elem *)(zone + 1);
		zone->type = type;
		init_list(&(zone->list));
		elems = zone->elems;
		init_elems(elems, zone->size.number_of_elems);
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
