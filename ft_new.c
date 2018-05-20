/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:28:50 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/20 17:28:50 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

t_const	*ft_new_const(void)
{
	t_const *new;

	new = (t_const *)malloc(sizeof(t_const));
	new->next = NULL;
	new->prev = NULL;
	new->old = 0;
	new->v = 0;
	return (new);
}

t_const	*ft_new_abcd(void)
{
	t_const *a;

	a = ft_new_const();
	a->old = 0x67452301;
	a->name = 'a';
	a->next = ft_new_const();
	a->next->prev = a;
	a->next->old = 0xefcdab89;
	a->next->name = 'b';
	a->next->next = ft_new_const();
	a->next->next->prev = a->next;
	a->next->next->old = 0x98badcfe;
	a->next->next->name = 'c';
	a->next->next->next = ft_new_const();
	a->next->next->next->old = 0x10325476;
	a->next->next->next->name = 'd';
	a->next->next->next->prev = a->next->next;
	a->next->next->next->next = a;
	a->prev = a->next->next->next;
	return (a);
}
