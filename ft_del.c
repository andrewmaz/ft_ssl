/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:53:57 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/24 11:53:57 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_del_m(t_md5 *lst)
{
	int		i;
	t_md5	*tmp;

	i = 0;
	while (lst && i <= D)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
		i++;
	}
}

void	ft_del_algo(t_algo *algo)
{
	t_algo *tmp;

	algo = ft_go2head(algo);
	while (algo)
	{
		tmp = algo->next;
		free(algo);
		algo = tmp;
	}
}

void	ft_delkey(t_kkey *key, int k)
{
	ft_dstrdel(&key->nfn);
	k ? ft_dstrdel(&key->ns) : free(key->ns);
	ft_strdel(&key->s);
	ft_strdel(&key->fn);
	key->fd ? free(key->fd) : 0;
	ft_del_algo(key->alg);
}
