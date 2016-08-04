/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 21:53:47 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/03 21:54:53 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zones.h"

size_t		malloc_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (s)
	{
		while (s[size])
			++size;
	}
	return (size);
}
