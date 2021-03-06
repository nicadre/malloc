/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:58:07 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 12:24:48 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "t_zones.h"
#include "list.h"

void				init_malloc(void)
{
	g_zones[e_zone_type_tiny].free_elems = 0;
	g_zones[e_zone_type_tiny].elems = NULL;
	g_zones[e_zone_type_tiny].type = e_zone_type_tiny;
	init_list(&(g_zones[e_zone_type_tiny].list));
	g_zones[e_zone_type_small].free_elems = 0;
	g_zones[e_zone_type_small].elems = NULL;
	g_zones[e_zone_type_small].type = e_zone_type_small;
	init_list(&(g_zones[e_zone_type_small].list));
	g_zones[e_zone_type_large].free_elems = 0;
	g_zones[e_zone_type_large].elems = NULL;
	g_zones[e_zone_type_large].type = e_zone_type_large;
	init_list(&(g_zones[e_zone_type_large].list));
}
