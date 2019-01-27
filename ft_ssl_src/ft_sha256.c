/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:07:05 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/05 12:30:55 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_set_v(t_uint *des, t_uint *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		des[i] = src[i];
		i++;
	}
}

void	ft_add_v(t_uint *des, t_uint *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		des[i] += src[i];
		i++;
	}
}

t_uint	ft_const_table(int i)
{
	const t_uint	k[] = {0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
			0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5, 0xD807AA98,
			0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE,
			0x9BDC06A7, 0xC19BF174, 0xE49B69C1, 0xEFBE4786, 0x0FC19DC6,
			0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
			0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3,
			0xD5A79147, 0x06CA6351, 0x14292967, 0x27B70A85, 0x2E1B2138,
			0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E,
			0x92722C85, 0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
			0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070, 0x19A4C116,
			0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A,
			0x5B9CCA4F, 0x682E6FF3, 0x748F82EE, 0x78A5636F, 0x84C87814,
			0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2};

	return (k[i]);
}

void	ft_in_rounds_sha(t_uint *bf, t_uint *msg, int b)
{
	int		j;
	t_uint	t[6];
	t_uint	*nmsg;

	j = 0;
	nmsg = ft_gen_addwords(msg + b);
	while (j < 64)
	{
		t[0] = ft_rotr(bf[A], 2) ^ ft_rotr(bf[A], 13) ^ ft_rotr(bf[A], 22);
		t[1] = (bf[A] & bf[B]) ^ (bf[A] & bf[C]) ^ (bf[B] & bf[C]);
		t[T2] = t[0] + t[1];
		t[3] = ft_rotr(bf[E], 6) ^ ft_rotr(bf[E], 11) ^ ft_rotr(bf[E], 25);
		t[4] = (bf[E] & bf[F]) ^ ((~bf[E]) & bf[G]);
		t[T1] = bf[H] + t[3] + t[4] + ft_const_table(j) + nmsg[j];
		bf[H] = bf[G];
		bf[G] = bf[F];
		bf[F] = bf[E];
		bf[E] = bf[D] + t[T1];
		bf[D] = bf[C];
		bf[C] = bf[B];
		bf[B] = bf[A];
		bf[A] = t[T1] + t[T2];
		j++;
	}
	free(nmsg);
}

void	ft_rounds_sha256(t_kkey *key, t_uint *msg, size_t len, t_uint **in)
{
	size_t	i;
	t_uint	*bf;
	t_uint	*bn;
	int		b;

	b = 0;
	i = 0;
	bf = key->alg->cr_buf();
	bn = key->alg->cr_buf();
	while (i < len)
	{
		ft_set_v(bf, bn);
		ft_in_rounds_sha(bf, msg, b);
		ft_add_v(bn, bf);
		b += 16;
		i += 64;
	}
	free(bf);
	*in = bn;
}
