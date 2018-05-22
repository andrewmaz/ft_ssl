/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/22 17:06:26 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_bzero_key(t_kkey *key)
{
	key->p = 0;
	key->q = 0;
	key->r = 0;
	key->s = NULL;
	key->fd = NULL;
	key->n_fd = 0;
	key->md5 = 0;
	key->sha256 = 0;
}

int		ft_set_key(t_kkey *key, int i, char **v)
{
	if (v[i][1] == 'p')
		key->p = 1;
	else if (v[i][1] == 'q')
		key->q = 1;
	else if (v[i][1] == 'r')
		key->r = 1;
	else if (v[i][1] == 's')
		key->s = !key->s ? ft_strdup(v[++i]) : key->s;
	else
	{
		//free(key);
		//ft_help(1);
		exit(6);
	}
	return (i);
}

int		ft_read_nonmin(t_kkey *key, char **v, int i)
{
	if (ft_strequ(v[i], "md5"))
		key->md5 = 1;
	else if (ft_strequ(v[i], "sha256"))
		key->sha256 = 1;
	else
		while (v[i])
		{
			key->fd = ft_intrealloc(key->fd, key->n_fd);
			key->fd[key->n_fd++] = open(v[i++], O_RDONLY);
		}
	return (i);
}

int		ft_read_key(int c, char **v, t_kkey *key)
{
	int i;

	i = 1;
	ft_bzero_key(key);
	while (i < c)
	{
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			i = ft_set_key(key, i, v);
		else
			i = ft_read_nonmin(key, v, i);
		i++;
	}
	return (i - 1);
}