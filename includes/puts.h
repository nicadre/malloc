/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niccheva <niccheva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 19:25:53 by niccheva          #+#    #+#             */
/*   Updated: 2016/08/03 19:27:53 by niccheva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTS_H
# define PUTS_H

# include <unistd.h>

ssize_t		malloc_putchar(const char c);
ssize_t		malloc_putstr(const char *s);
ssize_t		malloc_putendl(const char *s);
ssize_t		malloc_putaddr(const void *p);

#endif
