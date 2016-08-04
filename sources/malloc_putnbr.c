/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:34:43 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 12:36:10 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"

ssize_t		malloc_putnbr(const size_t nbr)
{
	static const char	*base = "0123456789";
	int					ret;

	if (nbr < 10)
		return (malloc_putchar(base[nbr]));
	ret = malloc_putnbr(nbr / 10);
	ret += malloc_putnbr(nbr % 10);
	return (ret);
}
