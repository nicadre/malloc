/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 21:27:51 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/03 23:46:40 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "t_zones.h"

# define TINY 64
# define SMALL 1024

void		init_malloc(void);
void		show_alloc_mem(void);

#endif
