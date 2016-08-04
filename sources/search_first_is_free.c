/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_first_is_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 16:46:13 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/03 18:05:09 by niccheva         ###   ########.fr       */
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
			if (zone->is_frees[i] == true)
				return (i);
			++i;
		}
	}
	return (i);
}
