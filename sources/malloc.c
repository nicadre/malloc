/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:56:50 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 00:10:38 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <unistd.h>

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
		+ (MEMBER_SIZE(t_zone, is_frees) * zone->size.number_of_elems)
		+ (first_free * size_for_elem_in_zone(zone->type));
	zone->is_frees[first_free] = false;
	--(zone->free_elems);
	return (data);
}
