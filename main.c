/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:03:03 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 19:34:54 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "puts.h"
#include "t_zones.h"

int main(void)
{
	char	*s;

	s = (char *)malloc(42);
	free(s);

	show_alloc_mem();
	return (0);
}
