/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:56:50 by niccheva          #+#    #+#             */
/*   Updated: 2016/07/31 17:52:20 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*malloc(size_t size)
{
	static char	is_init = 0;
	void		*data;

	if (!is_init)
	{
		init_malloc();
		is_init = 1;
		(void)size;
	}
	data = NULL;
	return (data);
}
