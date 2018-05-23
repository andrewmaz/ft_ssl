/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:28:50 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/23 15:00:06 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

t_md5		*ft_new_const(void)
{
	t_md5 *new;

	new = (t_md5 *)malloc(sizeof(t_md5));
	new->next = NULL;
	new->prev = NULL;
	new->old = 0;
	new->v = 0;
	return (new);
}

void		ft_addend_md5(t_md5 *head, t_md5 *end, unsigned int val)
{
	while (head->next)
		head = head->next;
	head->next = end;
	end->prev = head;
	end->old = val;
}

t_md5		*ft_new_md5(void)
{
	t_md5	*a;

	a = ft_new_const();
	ft_addend_md5(a, ft_new_const(), 0xefcdab89);
	ft_addend_md5(a, ft_new_const(), 0x98badcfe);
	ft_addend_md5(a, ft_new_const(), 0x10325476);
	ft_addend_md5(a, a, 0x67452301);
	return (a);
}

t_uint		*ft_create_buf(void)
{
	t_uint	*buf;

	buf = (t_uint *)malloc(sizeof(t_uint) * 8);
	buf[0] = 0x6A09E667;
	buf[1] = 0xBB67AE85;
	buf[2] = 0x3C6EF372;
	buf[3] = 0xA54FF53A;
	buf[4] = 0x510E527F;
	buf[5] = 0x9B05688C;
	buf[6] = 0x1F83D9AB;
	buf[7] = 0x5BE0CD19;
	return (buf);
}
