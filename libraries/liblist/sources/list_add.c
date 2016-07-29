/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:40:39 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 14:41:22 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "private_list.h"

void		list_add(t_list *new, t_list *head)
{
	private_list_add(new, head, head->next);
}
