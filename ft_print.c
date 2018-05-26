/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:26:17 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/26 14:26:42 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_print_hash_md5(t_md5 *a, t_kkey *key)
{
	unsigned char	*tmp;
	int				i;
	int				j;
	char			*c;
	int				p;

	i = 0;
	c = ":";
	p = key->c ? 1 : 0;
	while (i < 4)
	{
		j = -1;
		tmp = (unsigned char *)&a->old;
		if (key->b)
			while (++j < 4)
				ft_printf("%.8b%.*s", tmp[j], (j == 3 && i == 3 ? 0 : p), c);
		else
			while (++j < 4)
				ft_printf("%.2x%.*s", tmp[j], (j == 3 && i == 3 ? 0 : p), c);
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
	ft_print_hash_md5(a, key);
	if (k && !key->q && key->r)
	{
		key->is < ft_num_word(key->s, '\n') ? ft_printf(" \"%s\"", \
		key->ns[key->is]) : ft_printf(" %s", key->nfn[key->ifn]);
	}
	if (k)
		key->is < ft_num_word(key->s, '\n') ? key->is++ : key->ifn++;
	ft_printf("\n");
}

void	ft_print_hash_sha(int i, t_uchar *t, t_kkey *key, int b)
{
	int				j;
	char			*c;
	int				p;

	j = b;
	c = ":";
	p = key->c ? 1 : 0;
	while (j >= 0)
	{
		if (key->b)
			ft_printf("%.8b%.*s", t[j], (j == 0 && i == 7 ? 0 : p), c);
		else
			ft_printf("%.2x%.*s", t[j], (j == 0 && i == 7 ? 0 : p), c);
		j--;
	}
}

void	ft_print_res_sha(t_uint *hash, t_kkey *key, int k)
{
	int			i;
	t_uchar		*tmp;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_printf("SHA256 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < 8)
	{
		tmp = (t_uchar *)&hash[i];
		ft_print_hash_sha(i, tmp, key, 3);
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
	t_uchar		*tmp;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_printf("SHA512 (");
		key->is < ft_num_word(key->s, '\n') ? ft_printf("\"%s\") = ", \
		key->ns[key->is]) : ft_printf("%s) = ", key->nfn[key->ifn]);
	}
	while (i < 8)
	{
		tmp = (t_uchar *)&hash[i];
		ft_print_hash_sha(i, tmp, key, 7);
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
