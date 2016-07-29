/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:30:54 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 14:32:33 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_LIST_H
# define PRIVATE_LIST_H

# include "list.h"

void		private_list_add(t_list *new, t_list *prev, t_list *next);

void		private_list_del(t_list *prev, t_list *next);
void		private_list_del_entry(t_list *entry);

#endif
