/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:10:53 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 19:36:07 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "puts.h"
#include "t_zones.h"

static t_zone	*search_zone_for_ptr(const void *ptr)
{
	t_zone		*zone;
	t_zone		global_zone;
	t_list		*pos;
	size_t		i;

	i = e_zone_type_tiny;
	while (i <= e_zone_type_large)
	{
		global_zone = g_zones[i];
		pos = global_zone.list.next;
		while (pos != &(global_zone.list))
		{
			zone = LIST_ENTRY(pos, t_zone, list);
			if (ptr > (void *)zone && ptr <= (void *)zone + zone->size.page_size)
				return (zone);
			pos = pos->next;
		}
		++i;
	}
	return (NULL);
}

static void		free_error(void *ptr)
{
	malloc_putstr("malloc error for object ");
	malloc_putaddr(ptr);
	malloc_putendl(": pointer being freed was not allocated");
}

void		free(void *ptr)
{
	t_zone	*zone;
	void	*data;
	size_t	i;

	if (ptr)
	{
		zone = search_zone_for_ptr(ptr);
		if (zone)
		{
			data = ((char *)(zone + 1))
				+ (zone->size.number_of_elems * MEMBER_SIZE(t_zone, elems));
			i = 0;
			while (i < zone->size.number_of_elems
				&& ptr <= data + (i * size_for_elem_in_zone(zone->type)))
			{
				if (ptr == data + (i * size_for_elem_in_zone(zone->type))
					&& zone->elems[i].is_free == false)
				{
					zone->elems[i].is_free = true;
					zone->elems[i].size = 0;
					return ;
				}
				++i;
			}
			free_error(ptr);
		}
		else
		{
			free_error(ptr);
		}
	}
}
