/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:54:58 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/02 17:58:42 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t	ft_newlen_256(size_t len)
{
	size_t			len1;

	len1 = len + 1;
	while (len1 % 512 != 448)
		len1++;
	len1 /= BIT;
	len1 += LEN_BLCK_256;
	return (len1);
}

size_t	ft_newlen_512(size_t len)
{
	size_t			len1;

	len1 = len + 1;
	while (len1 % 1024 != 896)
		len1++;
	len1 /= BIT;
	len1 += LEN_BLCK_512;
	return (len1);
}

void	ft_algo_mand(t_kkey *key, t_uchar *mg, size_t len, int k)
{
	t_uint			*msg;
	t_md5			*m_hash;
	t_uint			*s_hash;
	size_t			nlen;

	s_hash = NULL;
	nlen = ft_newlen_256(len);
	m_hash = key->md5 ? ft_new_md5() : NULL;
	msg = key->md5 ? ft_msg_md5(mg, nlen, len) : ft_msg_sha(mg, nlen, len);
	key->md5 ? ft_rounds_md5(m_hash, msg, nlen) : \
		ft_rounds_sha256(key, msg, nlen, &s_hash);
	key->md5 ? ft_print_res_md5(m_hash, key, k) : \
		ft_print_res_sha(s_hash, key, k);
	free(msg);
	s_hash ? free(s_hash) : 0;
	ft_del_m(m_hash);
}

void	ft_algo_bonus(t_kkey *key, t_uchar *mg, size_t len, int k)
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

void	ft_algo(const char *str, size_t len, t_kkey *key, int k)
{
	size_t	nlen;
	t_uchar	*mg;

	nlen = key->sha512 || key->sha384 ? ft_newlen_512(len * BIT) : \
		ft_newlen_256(len * BIT);
	mg = (t_uchar *)malloc(sizeof(t_uchar) * nlen);
	ft_bzero(mg, nlen);
	mg = ft_memcpy(mg, str, len);
	mg[len] = 0x80;
	len *= BIT;
	key->sha512 || key->sha384 ? ft_algo_bonus(key, mg, len, k) : \
		ft_algo_mand(key, mg, len, k);
	free(mg);
}
