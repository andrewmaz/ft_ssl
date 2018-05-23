/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:22:23 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/23 15:02:52 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

unsigned int	*ft_to_arr(unsigned int a, unsigned int b, unsigned int c)
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
	unsigned int r[4];

	r[0] = 0;
	r[1] = 1;
	r[2] = 5;
	r[3] = 0;
	while (r[0] < 64)
	{
		if (r[0] < 16)
			ft_r(a, ft_to_arr(msg[r[0]], s[r[0]], r[0]), &f_f);
		else if (r[0] < 32)
			ft_r(a, ft_to_arr(msg[r[1]], s[r[0]], r[0]), &f_g);
		else if (r[0] < 48)
			ft_r(a, ft_to_arr(msg[r[2]], s[r[0]], r[0]), &f_h);
		else if (r[0] < 64)
			ft_r(a, ft_to_arr(msg[r[3]], s[r[0]], r[0]), &f_i);
		a = a->prev;
		r[1] = r[0] >= 16 && r[0] < 32 ? (r[1] + 5) % 16 : r[1];
		r[2] = r[0] >= 32 && r[0] < 48 ? (r[2] + 3) % 16 : r[2];
		r[3] = r[0] >= 48 && r[0] < 64 ? (r[3] + 7) % 16 : r[3];
		r[0]++;
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
