/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:26:17 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/10 16:52:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_printf("%c", ft_toupper(str[i++]));
}

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
		ft_print_upper(key->alg->name);
		key->f ? ft_printf(" (%s) = ", key->s): ft_printf(" (\"%s\") = ", key->s);
	}
	ft_print_hash_md5(a);
	if (k && !key->q && key->r)
	{
		 key->f ? ft_printf(" %s", key->s) : ft_printf(" \"%s\"", key->s);
	}
	ft_printf("\n");
}

void	ft_print_res_sha(t_uint *hash, t_kkey *key, int k)
{
	int			i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_print_upper(key->alg->name);
		key->f ? ft_printf(" (%s) = ", key->s): ft_printf(" (\"%s\") = ", key->s);
	}
	while (i < key->alg->word)
		ft_printf("%.8x", hash[i++]);
	if (k && !key->q && key->r)
		key->f ? ft_printf(" %s", key->s) : ft_printf(" \"%s\"", key->s);
	ft_printf("\n");
}

void	ft_print_res_sha512(t_ulint *hash, t_kkey *key, int k)
{
	int			i;

	i = 0;
	if (k && !key->q && !key->r)
	{
		ft_print_upper(key->alg->name);
		key->f ? ft_printf(" (%s) = ", key->s): ft_printf(" (\"%s\") = ", key->s);
	}
	while (i < key->alg->word)
		ft_printf("%z.16x", hash[i++]);
	if (k && !key->q && key->r)
		key->f ? ft_printf(" %s", key->s) : ft_printf(" \"%s\"", key->s);
	ft_printf("\n");
}
