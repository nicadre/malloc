/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:51:23 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 14:53:55 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "private_list.h"

int		list_empty(const t_list *head)
{
	return (head->next == head && head->next == head->prev);
}
