/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:03:03 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/04 00:46:36 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "puts.h"

int main(void)
{
	char	*s;

	s = (char *)malloc(42);
	show_alloc_mem();
	return (0);
}
