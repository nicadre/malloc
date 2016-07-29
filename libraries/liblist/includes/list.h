/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:19:31 by niccheva          #+#    #+#             */
/*   Updated: 2016/06/09 15:02:33 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# define OFFSETOF(type, member) ((size_t)&((type *)0)->member)

# define LIST_CAST(t, m) ((t *)((char *)mptr - OFFSETOF(t, m)))

# define LIST_PTR(ptr) const t_list *mptr = (ptr)

# define LIST_ENTRY(p, t, m) ({LIST_PTR(p); LIST_CAST(t, m);})

# define LIST_FIRST_ENTRY(p, t, m) LIST_ENTRY((p)->next, t ,m)

# define LIST_LAST_ENTRY(p, t, m) LIST_ENTRY((p)->prev, t, m)

typedef struct s_list	t_list;

struct					s_list
{
	t_list				*next;
	t_list				*prev;
};

void					init_list(t_list *list);

void					list_add(t_list *new, t_list *head);
void					list_add_tail(t_list *new, t_list *head);

void					list_del(t_list *entry);
void					list_del_init(t_list *entry);

int						list_empty(const t_list *list);
int						list_is_last(const t_list *list,
									const t_list *head);
int						list_is_singular(const t_list *head);

#endif
