/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:53:34 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/26 11:16:16 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void		ft_set_v5(t_ulint *des, t_ulint *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		des[i] = src[i];
		i++;
	}
}

void		ft_add_v5(t_ulint *des, t_ulint *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		des[i] += src[i];
		i++;
	}
}

void		ft_add_len_sha512(t_ulint *arr, ssize_t i, size_t len)
{
	arr[i] = arr[i] | len;
}

t_ulint		*ft_msg_sha512(t_uchar *mg, size_t nlen, size_t len)
{
	size_t	*arr;
	ssize_t	i;
	ssize_t	new_len;
	t_ulint a;
	int		k;

	i = 0;
	new_len = nlen / 8;
	arr = (t_ulint *)malloc(sizeof(t_ulint) * new_len);
	while (i < new_len)
		arr[i++] = 0;
	i = --new_len;
	while (new_len >= 0)
	{
		k = 0;
		while (k < 64)
		{
			a = mg[--nlen];
			arr[new_len] = arr[new_len] | a << k;
			k += 8;
		}
		new_len--;
	}
	ft_add_len_sha512(arr, i, len);
	return (arr);
}
