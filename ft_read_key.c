/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/05 13:41:02 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

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
		key->s = ft_realcatendl_s(key->s, v[++i], 1);
	else
		ft_help_key(key, v[i]);
	return (i);
}

int		ft_read_nonmin(t_kkey *key, char **v, int i)
{
	while (!key->al && !ft_strequ(v[i], key->alg->name) && key->alg->next)
		key->alg = key->alg->next;
	if (ft_strequ(v[i], key->alg->name))
	{
		key->al = 1;
		return (i);
	}
	else
		while (v[i])
		{
			if (!key->al)
				ft_usage_ssl(key, v[i]);
			key->fd = ft_intrealloc(key->fd, key->n_fd);
			key->fd[key->n_fd++] = open(v[i], O_RDONLY);
			key->fn = ft_realcatendl_s(key->fn, v[i++], 1);
		}
	return (i);
}

char	*ft_newword(char *str, int *i)
{
	char	buf[101];
	char	*res;
	char	s;
	size_t	j;

	j = 0;
	res = NULL;
	s = (char)(str[*i] == '\"' ? '\"' : ' ');
	*i += s == '\"' ? 1 : 0;
	while (str[*i] && str[*i] != s)
	{
		buf[j++] = str[*i];
		buf[j] = '\0';
		if (j == 100)
		{
			res = ft_realcat(res, buf);
			j = 0;
		}
		++*i;
	}
	*i += s == '\"' ? 1 : 0;
	return (ft_realcat(res, buf));
}

char	**ft_read_sdtin(void)
{
	ssize_t	ret;
	char	buf[101];
	char	*str;
	char	**res;
	int		i;

	i = 0;
	str = NULL;
	while ((ret = read(0, buf, 100)) > 0)
	{
		buf[ret] = '\0';
		str = ft_realcat(str, buf);
	}
	ret = 0;
	res = (char **)malloc(sizeof(char *) * (ft_num_word(str, ' ') + 1));
	while (str && str[i])
	{
		res[ret] = ft_newword(str, &i);
		while (str[i] == ' ' || str[i] == '\n')
			i++;
		ret++;
	}
	res[ret] = NULL;
	ft_strdel(&str);
	return (res);
}

int		ft_read_key(int c, char **v, t_kkey *key)
{
	int		i;
	int		stdin;

	stdin = c == 1;
	i = c == 1 ? 0 : 1;
	ft_bzero_key(key);
	v = c == 1 ? ft_read_sdtin() : v;
	c = (c == 1 ? (int)ft_dstrlen(v) : c);
	while (i < c)
	{
		if (v[i][0] == '-' && ft_isalpha(v[i][1]) && key->al)
			i = ft_set_key(key, i, v, c);
		else
			i = ft_read_nonmin(key, v, i);
		i++;
	}
	key->ns = ft_strsplit(key->s, 1);
	key->nfn = ft_strsplit(key->fn, 1);
	stdin ? ft_dstrdel(&v) : 0;
	return (i - 1);
}
