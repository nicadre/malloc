/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 17:24:46 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/31 17:28:05 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"

void		*malloc_memset(void *b, int c, size_t len)
{
	if (b)
	{
		while (--len)
			((char *)b)[len] = (unsigned char)c;
	}
	return (b);
}
