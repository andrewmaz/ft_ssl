/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:42:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/23 16:10:51 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_delkey(t_kkey *key, int k)
{
	ft_dstrdel(&key->nfn);
	k ? ft_dstrdel(&key->ns) : free(key->ns);
	ft_strdel(&key->s);
	ft_strdel(&key->fn);
	key->fd ? free(key->fd) : 0;
}

void	ft_help(t_kkey *key)
{
	ft_printf("usage: ./ft_ssl md5/sha256 [keys]\n");
	ft_delkey(key, 1);
	//system("leaks ft_ssl");
	exit(1);
}
