/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_putendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 19:37:54 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/03 19:39:26 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puts.h"

ssize_t		malloc_putendl(const char *s)
{
	return (malloc_putstr(s) + malloc_putchar('\n'));
}
