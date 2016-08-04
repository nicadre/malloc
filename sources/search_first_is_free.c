/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_first_is_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 16:46:13 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 12:31:31 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"

#include <stdio.h>

size_t		search_first_is_free(t_zone *zone)
{
	size_t	i;

	i = 0;
	if (zone)
	{
		while (i < zone->size.number_of_elems)
		{
			if (zone->elems[i].is_free == true)
				return (i);
			++i;
		}
	}
	return (i);
}
