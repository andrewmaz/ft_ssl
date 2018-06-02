/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/02 17:00:56 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_bzero_key(t_kkey *key)
{
	key->p = 0;
	key->q = 0;
	key->r = 0;
	key->h = 0;
	key->s = NULL;
	key->ns = NULL;
	key->is = 0;
	key->fd = NULL;
	key->fn = NULL;
	key->nfn = NULL;
	key->ifn = 0;
	key->n_fd = 0;
	key->md5 = 0;
	key->sha224 = 0;
	key->sha256 = 0;
	key->sha384 = 0;
	key->sha512 = 0;
}

int		ft_set_key(t_kkey *key, int i, char **v, int c)
{
	if (v[i][1] == 'p' && v[i][2] == '\0')
		key->p = 1;
	else if (v[i][1] == 'q' && v[i][2] == '\0')
		key->q = 1;
	else if (v[i][1] == 'r' && v[i][2] == '\0')
		key->r = 1;
	else if (v[i][1] == 'h' && v[i][2] == '\0')
		key->h = 1;
	else if (v[i][1] == 's' && v[i][2] == '\0' && (i + 1 < c))
		key->s = ft_realcatendl(key->s, v[++i]);
	else
		ft_help_key(key, v[i]);
	return (i);
}

int		ft_read_nonmin(t_kkey *key, char **v, int i)
{
	if (ft_strequ(v[i], "md5") && !key->sha256)
		key->md5 = 1;
	else if (ft_strequ(v[i], "sha256") && !key->md5)
		key->sha256 = 1;
	else if (ft_strequ(v[i], "sha224") && !key->md5)
		key->sha224 = 1;
	else if (ft_strequ(v[i], "sha512") && !key->md5)
		key->sha512 = 1;
	else if (ft_strequ(v[i], "sha384") && !key->md5)
		key->sha384 = 1;
	else
		while (v[i])
		{
			if (!key->sha512 && !key->sha256 && !key->md5 && !key->sha224 \
					&& !key->sha384)
				ft_usage_ssl(key, v[i]);
			key->fd = ft_intrealloc(key->fd, key->n_fd);
			key->fd[key->n_fd++] = open(v[i], O_RDONLY);
			key->fn = ft_realcatendl(key->fn, v[i++]);
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
		if (v[i][0] == '-' && ft_isalpha(v[i][1]) && (key->sha512 || \
			key->sha256 || key->md5 || key->sha224 || key->sha384))
			i = ft_set_key(key, i, v, c);
		else
			i = ft_read_nonmin(key, v, i);
		i++;
	}
	key->ns = ft_strsplit(key->s, '\n');
	key->nfn = ft_strsplit(key->fn, '\n');
	return (i - 1);
}
