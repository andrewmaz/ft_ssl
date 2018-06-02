/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:26:17 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/02 17:16:20 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_hash_md5(t_md5 *a)
{
	unsigned char	*tmp;
	int				i;
	int				j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		tmp = (unsigned char *)&a->old;
		while (j < 4)
			ft_printf("%.2x", tmp[j++]);
		a = a->next;
		i++;
	}
}

void	ft_print_res_md5(t_md5 *a, t_kkey *key, int k)
{
	if (k && !key->q && !key->r)
	{
		ft_printf("MD5 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	ft_print_hash_md5(a);
	if (k && !key->q && key->r)
	{
		key->is < ft_num_word(key->s, '\n') ? ft_printf(" \"%s\"", \
		key->ns[key->is]) : ft_printf(" %s", key->nfn[key->ifn]);
	}
	if (k)
		key->is < ft_num_word(key->s, '\n') ? key->is++ : key->ifn++;
	ft_printf("\n");
}

void	ft_print_res_sha(t_uint *hash, t_kkey *key, int k)
{
	int			i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		key->sha256 ? ft_printf("SHA256 (") : ft_printf("SHA224 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < (key->sha256 ? 8 : 7))
	{
		ft_printf("%.8x", hash[i]);
		i++;
	}
	if (k && !key->q && key->r)
	{
		key->is < ft_num_word(key->s, '\n') ? ft_printf(" \"%s\"", \
		key->ns[key->is]) : ft_printf(" %s", key->nfn[key->ifn]);
	}
	if (k)
		key->is < ft_num_word(key->s, '\n') ? key->is++ : key->ifn++;
	ft_printf("\n");
}

void	ft_print_res_sha512(t_ulint *hash, t_kkey *key, int k)
{
	int			i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		key->sha512 ? ft_printf("SHA512 (") : ft_printf("SHA284 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < (key->sha512 ? 8 : 6))
	{
		ft_printf("%z.16x", hash[i]);
		i++;
	}
	if (k && !key->q && key->r)
	{
		key->is < ft_num_word(key->s, '\n') ? ft_printf(" \"%s\"", \
		key->ns[key->is]) : ft_printf(" %s", key->nfn[key->ifn]);
	}
	if (k)
		key->is < ft_num_word(key->s, '\n') ? key->is++ : key->ifn++;
	ft_printf("\n");
}
