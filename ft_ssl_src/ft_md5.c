/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:22:23 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/03 17:48:31 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_uint			*ft_to_arr(unsigned int a, unsigned int b, unsigned int c)
{
	unsigned int *res;

	res = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	res[0] = a;
	res[1] = b;
	res[2] = c;
	return (res);
}

void			ft_in_md5(t_md5 *a, unsigned int *msg, const unsigned int *s)
{
	unsigned int	r;
	static t_func	qwe[64] = {f_f, f_f, f_f, f_f, f_f, f_f, f_f, f_f, f_f, \
		f_f, f_f, f_f, f_f, f_f, f_f, f_f, f_g, f_g, f_g, f_g, f_g, f_g, f_g, \
		f_g, f_g, f_g, f_g, f_g, f_g, f_g, f_g, f_g, f_h, f_h, f_h, f_h, f_h, \
		f_h, f_h, f_h, f_h, f_h, f_h, f_h, f_h, f_h, f_h, f_h, f_i, f_i, f_i, \
		f_i, f_i, f_i, f_i, f_i, f_i, f_i, f_i, f_i, f_i, f_i, f_i, f_i};
	static t_uint	ar[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,\
		15, 1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 5, 8, 11, 14,\
		1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2, 0, 7, 14, 5, 12, 3, 10, 1, 8,\
		15, 6, 13, 4, 11, 2, 9};

	r = 0;
	while (r < 64)
	{
		ft_r(a, ft_to_arr(msg[ar[r]], s[r], r), qwe[r]);
		a = a->prev;
		r++;
	}
}

void			ft_rounds_md5(t_md5 *a, unsigned int *msg, size_t len1)
{
	size_t				i;
	int					b;
	const unsigned int	r[] = {
			7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
			5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
			4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
			6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
	};

	i = 0;
	b = 0;
	while (i < len1)
	{
		a->v = a->old;
		a->next->v = a->next->old;
		a->next->next->v = a->next->next->old;
		a->next->next->next->v = a->next->next->next->old;
		ft_in_md5(a, msg + b, r);
		a->old += a->v;
		a->next->old += a->next->v;
		a->next->next->old += a->next->next->v;
		a->next->next->next->old += a->next->next->next->v;
		i += 64;
		b += 16;
	}
}
