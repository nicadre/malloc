/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_type_for_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 16:12:32 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/02 17:02:08 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "t_zones.h"

t_zone_type		zone_type_for_size(size_t size)
{
	if (size <= TINY)
		return (e_zone_type_tiny);
	if (size <= SMALL)
		return (e_zone_type_small);
	return (e_zone_type_large);
}
