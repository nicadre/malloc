/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_putaddr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 19:39:51 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/03 21:39:21 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"

static ssize_t	malloc_putsize_t(const size_t nbr)
{
	static const char	*base = "0123456789ABCDEF";
	int					ret;

	if (nbr < 16)
		return (malloc_putchar(base[nbr]));
	ret = malloc_putsize_t(nbr / 16);
	ret += malloc_putsize_t(nbr % 16);
	return (ret);
}

ssize_t		malloc_putaddr(const void *p)
{
	return (malloc_putstr("0x") + malloc_putsize_t((size_t)p));
}
