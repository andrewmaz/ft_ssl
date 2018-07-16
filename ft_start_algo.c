/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:54:58 by amazurok          #+#    #+#             */
/*   Updated: 2018/07/16 15:02:44 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_sha512_384(t_kkey *key, t_uchar *mg, size_t len, int k)
{
	size_t	nlen;
	t_ulint *msg;
	t_ulint *hash;

	nlen = ft_newlen_512(len);
	msg = ft_msg_sha512(mg, nlen, len);
	ft_rounds_sha512(key, msg, nlen, &hash);
	ft_print_res_sha512(hash, key, k);
	free(msg);
	free(hash);
}

void	ft_md5(t_kkey *key, t_uchar *mg, size_t len, int k)
{
	t_uint			*msg;
	t_md5			*hash;
	size_t			nlen;

	nlen = ft_newlen_256(len);
	hash = ft_new_md5();
	msg = ft_msg_md5(mg, nlen, len);
	ft_rounds_md5(hash, msg, nlen);
	ft_print_res_md5(hash, key, k);
	free(msg);
	ft_del_m(hash);
}

void	ft_sha256_224(t_kkey *key, t_uchar *mg, size_t len, int k)
{
	t_uint			*msg;
	t_uint			*hash;
	size_t			nlen;

	hash = NULL;
	nlen = ft_newlen_256(len);
	msg = ft_msg_sha(mg, nlen, len);
	ft_rounds_sha256(key, msg, nlen, &hash);
	ft_print_res_sha(hash, key, k);
	free(msg);
	hash ? free(hash) : 0;
}

void	ft_hash(const char *str, size_t len, t_kkey *key, int k)
{
	size_t	nlen;
	t_uchar	*mg;

	nlen = key->alg->len(len * BIT);
	mg = (t_uchar *)malloc(sizeof(t_uchar) * nlen);
	ft_bzero(mg, nlen);
	mg = ft_memcpy(mg, str, len);
	mg[len] = 0x80;
	len *= BIT;
	key->alg->alg(key, mg, len, k);
	free(mg);
}

void	ft_algo(const char *str, size_t len, t_kkey *key, int k)
{
	if (key->alg->word > 0)
		ft_hash(str, len, key, k);
	else
		key->alg->alg(key, (t_uchar*)str, len, k);
}
