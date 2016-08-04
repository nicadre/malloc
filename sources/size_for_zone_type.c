/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_for_zone_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 00:03:26 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/02 15:48:31 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"
#include <unistd.h>

struct s_size			size_for_zone_type(t_zone_type type)
{
	const int			page_size = getpagesize();
	struct s_size		size;
	int					tmp_size;
	size_t				coef;
	size_t				number;

	coef = 1;
	number = 100;
	tmp_size = ((page_size * coef) - sizeof(t_zone)
				- (number * MEMBER_SIZE(t_zone, is_frees)));
	while ((size_t)tmp_size < number * size_for_elem_in_zone(type))
	{
		++coef;
		tmp_size = ((page_size * coef) - sizeof(t_zone)
					- (number * MEMBER_SIZE(t_zone, is_frees)));
	}
	size.page_size = page_size * coef;
	while ((int)(tmp_size - (number * MEMBER_SIZE(t_zone, is_frees))
				- (number * size_for_elem_in_zone(type))) >= 0)
	{
		++number;
	}
	size.number_of_elems = number - 1;
	return (size);
}
