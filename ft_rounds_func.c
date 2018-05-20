/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounds_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:27:18 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/20 17:28:46 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

unsigned int f_f(unsigned int x, unsigned int y, unsigned int z)
{
	return (x & y) | ((~x) & z);
}

unsigned int f_g(unsigned int x, unsigned int y, unsigned int z)
{
	return (x & z) | (y & (~z));
}

unsigned int f_h(unsigned int x, unsigned int y, unsigned int z)
{
	return (x ^ y ^ z);
}

unsigned int f_i(unsigned int x, unsigned int y, unsigned int z)
{
	return  y ^ (x | (~z));
}

void 	r1(t_const *h, unsigned int word, int s, int i, unsigned int (*f1)(unsigned int, unsigned int, unsigned int))
{
	unsigned int tmp;

	tmp = h->v + ((*f1)(h->next->v, h->next->next->v, h->next->next->next->v) + word + k[i]);
	tmp = (((tmp) << (s)) | ((tmp) >> (32 - (s))));
	h->v = h->next->v + tmp;
}