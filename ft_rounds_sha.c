/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounds_sha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:18:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/26 12:14:50 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

t_uint		ft_rotr(t_uint x, int s)
{
	t_uint	res;

	res = ((x) >> s) | ((x) << (32 - s));
	return (res);
}

t_uint		*ft_gen_addwords(t_uint *msg)
{
	t_uint	*res;
	t_uint	s0;
	t_uint	s1;
	int		i;

	i = 0;
	res = (t_uint *)malloc(sizeof(t_uint) * 64);
	while (i < 16)
	{
		res[i] = msg[i];
		i++;
	}
	while (i < 64)
	{
		s0 = (t_uint)(ft_rotr(res[i - 15], 7) ^ ft_rotr(res[i - 15], 18) \
			^ (res[i - 15] >> 3));
		s1 = (t_uint)(ft_rotr(res[i - 2], 17) ^ ft_rotr(res[i - 2], 19) \
			^ (res[i - 2] >> 10));
		res[i] = res[i - 16] + s0 + res[i - 7] + s1;
		i++;
	}
	return (res);
}

t_ulint		*ft_gen_addwords512(t_ulint *msg)
{
	t_ulint	*res;
	t_ulint	s0;
	t_ulint	s1;
	int		i;

	i = 0;
	res = (t_ulint *)malloc(sizeof(t_ulint) * 80);
	while (i < 16)
	{
		res[i] = msg[i];
		i++;
	}
	while (i < 80)
	{
		s0 = (ft_rotr5(res[i - 15], 1) ^ ft_rotr5(res[i - 15], 8) \
			^ (res[i - 15] >> 7));
		s1 = (ft_rotr5(res[i - 2], 19) ^ ft_rotr5(res[i - 2], 61) \
			^ (res[i - 2] >> 6));
		res[i] = res[i - 16] + s0 + res[i - 7] + s1;
		i++;
	}
	return (res);
}
