/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:26:17 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/23 15:00:58 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_print_res_md5(t_md5 *a, t_kkey *key, int k)
{
	unsigned char	*tmp;
	int				i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_printf("MD5 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < 4)
	{
		tmp = (unsigned char *)&a->old;
		ft_printf("%.2x%.2x%.2x%.2x", tmp[0], tmp[1], tmp[2], tmp[3]);
		a = a->next;
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

void	ft_print_res_sha(t_uint *hash, t_kkey *key, int k)
{
	int i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_printf("SHA256 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < 8)
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
	int i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_printf("SHA512 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < 8)
	{
		ft_printf("%.16zx", hash[i]);
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

