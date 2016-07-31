/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_for_elem_in_zone.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 00:14:14 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/31 17:43:59 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"
#include "malloc.h"

size_t		size_for_elem_in_zone(t_zone_type type)
{
	static const int	tab[2] = {
		TINY,
		SMALL
	};

	return (tab[type]);
}
