/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounds_sha512.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:51:43 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/02 16:33:52 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ulint		ft_rotr5(t_ulint x, int s)
{
	t_ulint	res;

	res = ((x) >> s) | ((x) << (64 - s));
	return (res);
}

t_ulint		ft_const_table_h(int i)
{
	const t_ulint k[] = {0xa2bfe8a14cf10364,\
	0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,\
	0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a,\
	0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,\
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63,\
	0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,\
	0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72,\
	0x8cc702081a6439ec, 0x90befffa23631e28, 0xa4506cebde82bde9,\
	0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,\
	0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,\
	0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae,\
	0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493,\
	0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c, 0x4cc5d4becb3e42b6,\
	0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

	return (k[i]);
}

t_ulint		ft_const_table512(int i)
{
	const t_ulint k[] = {0x428a2f98d728ae22, 0x7137449123ef65cd,
	0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
	0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,\
	0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c,\
	0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1,\
	0x9bdc06a725c71235, 0xc19bf174cf692694, 0xe49b69c19ef14ad2,\
	0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,\
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4,\
	0x76f988da831153b5, 0x983e5152ee66dfab, 0xa831c66d2db43210,\
	0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2,\
	0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,\
	0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,\
	0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8,\
	0x81c2c92e47edaee6, 0x92722c851482353b, };

	return (i < 40 ? k[i] : ft_const_table_h(i - 40));
}

void		ft_in_rounds_sha512(t_ulint *bf, t_ulint *msg, int b)
{
	int		j;
	t_ulint	t[6];
	t_ulint	*nmsg;

	j = 0;
	nmsg = ft_gen_addwords512(msg + b);
	while (j < 80)
	{
		t[0] = ft_rotr5(bf[A], 28) ^ ft_rotr5(bf[A], 34) ^ ft_rotr5(bf[A], 39);
		t[1] = (bf[A] & bf[B]) ^ (bf[A] & bf[C]) ^ (bf[B] & bf[C]);
		t[T2] = t[0] + t[1];
		t[3] = ft_rotr5(bf[E], 14) ^ ft_rotr5(bf[E], 18) ^ ft_rotr5(bf[E], 41);
		t[4] = (bf[E] & bf[F]) ^ ((~bf[E]) & bf[G]);
		t[T1] = bf[H] + t[3] + t[4] + ft_const_table512(j) + nmsg[j];
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

void		ft_rounds_sha512(t_kkey *key, t_ulint *msg, size_t nln, t_ulint **h)
{
	size_t	i;
	t_ulint	*bf;
	t_ulint	*bn;
	int		b;

	b = 0;
	i = 0;
	bf = key->sha512 ? ft_create_buf512() : ft_create_buf384();
	bn = key->sha512 ? ft_create_buf512() : ft_create_buf384();
	while (i < nln)
	{
		ft_set_v5(bf, bn);
		ft_in_rounds_sha512(bf, msg, b);
		ft_add_v5(bn, bf);
		b += 16;
		i += 128;
	}
	free(bf);
	*h = bn;
}
