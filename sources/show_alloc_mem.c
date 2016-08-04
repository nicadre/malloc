/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:29:06 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 00:32:54 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"
#include "t_zones.h"

void		print_zone(const t_zone *zone)
{
	static const char *type[] = {
		"TINY",
		"SMALL",
		"LARGE"
	};
	size_t				i;
	void				*data;

	malloc_putstr(type[zone->type]);
	malloc_putstr(" : ");
	malloc_putaddr(zone);
	malloc_putchar('\n');
	i = 0;
	data = (void *)(zone + sizeof(*zone))
		+ (zone->size.number_of_elems * MEMBER_SIZE(t_zone, is_frees));
	while (i < zone->size.number_of_elems)
	{
		if (zone->is_frees[i] == false)
		{
			malloc_putaddr(data + (i * size_for_elem_in_zone(zone->type)));
			malloc_putstr(" - ");
			malloc_putaddr(data + (i * size_for_elem_in_zone(zone->type))
						   + size_for_elem_in_zone(zone->type));
			malloc_putchar('\n');
		}
		++i;
	}
}

void		show_tiny_zones(void)
{
	t_zone	*zone;
	t_list	*pos;
	t_zone	*head;

	head = &(g_zones[e_zone_type_tiny]);
	pos = head->list.next;
	while (pos != &(head->list))
	{
		zone = LIST_ENTRY(pos, t_zone, list);
		print_zone(zone);
		pos = pos->next;
	}
}

void		show_small_zones(void)
{
	t_zone	*zone;
	t_list	*pos;
	t_zone	*head;

	head = &(g_zones[e_zone_type_small]);
	pos = head->list.next;
	while (pos != &(head->list))
	{
		zone = LIST_ENTRY(pos, t_zone, list);
		print_zone(zone);
		pos = pos->next;
	}
}

void		show_large_zones(void)
{
	t_zone	*zone;
	t_list	*pos;
	t_zone	*head;

	head = &(g_zones[e_zone_type_large]);
	pos = head->list.next;
	while (pos != &(head->list))
	{
		zone = LIST_ENTRY(pos, t_zone, list);
		print_zone(zone);
		pos = pos->next;
	}
}

void		show_alloc_mem(void)
{
	show_tiny_zones();
	show_small_zones();
	show_large_zones();
}
