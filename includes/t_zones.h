/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_zones.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 21:35:00 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/31 17:41:04 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ZONES_H
# define T_ZONES_H

# include "list.h"
# include <stddef.h>

typedef struct s_zone		t_zone;
typedef struct s_large_zone	t_large_zone;
typedef enum e_zone_type	t_zone_type;

enum						e_zone_type
{
	e_zone_type_tiny = 0,
	e_zone_type_small,
	e_zone_type_large
};

struct						s_size
{
	size_t					page_size;
	size_t					number_of_elems;
};

struct						s_zone
{
	size_t					free_elems;
	struct s_size			size;
	char					*is_frees;
	t_zone_type				type;
	t_list					list;
};

struct						s_large_zone
{
	size_t					free_elems;
	struct s_size			size;
	char					*is_frees;
	t_zone_type				type;
	t_list					list;
};

t_zone						g_zones[3];

t_zone						*create_large_zone(size_t size);
t_zone						*create_zone_for(t_zone_type type);

struct s_size				size_for_zone_type(t_zone_type type);
size_t						size_for_elem_in_zone(t_zone_type type);

void						add_zone(t_zone *zone);
void						del_zone(t_zone *zone);

void						malloc_bzero(void *s, size_t n);
void						*malloc_memset(void *b, int c, size_t len);

#endif