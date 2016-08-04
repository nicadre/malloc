/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:56:50 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 19:38:55 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*malloc(size_t size)
{
	static char	is_init = 0;
	void		*data;
	t_zone		*zone;
	size_t		first_free;

	if (!is_init)
	{
		init_malloc();
		is_init = 1;
	}
	if (size == 0)
		return (NULL);
	data = NULL;
	zone = get_zone_for_size(size);
	first_free = search_first_is_free(zone);
	data = ((char *)(zone + 1))
		+ (MEMBER_SIZE(t_zone, elems) * zone->size.number_of_elems)
		+ (first_free * size_for_elem_in_zone(zone->type));
	zone->elems[first_free].is_free = false;
	zone->elems[first_free].size = size;
	--(zone->free_elems);
	return (data);
}
