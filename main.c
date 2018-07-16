/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/10 17:05:38 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_my_read(t_kkey *key)
{
	int		fd;
	char	buf[101];
	char	*str;
	ssize_t	ret;

	if ((fd = key->flag == 'p' ? 0 : open(key->s, O_RDONLY)) < 0)
	{
		ft_printf("ft_ssl: %s: %s: No such file or directory\n", \
		key->alg->name, key->s);
		return (NULL);
	}
	str = ft_strnew(0);
	while ((ret = read(fd, buf, 100)) > 0)
	{
		buf[ret] = '\0';
		str = ft_realcat(str, buf);
	}
	return (str);
}

char	*ft_do_flag(t_kkey *key, int c, char **v, int *i)
{
	if (key->flag == 'p')
		return (ft_my_read(key));
	else if (key->flag == 'q')
		key->q = 1;
	else if (key->flag =='r')
		key->r = 1;
	else if (key->flag == 'h')
		key->h = 1;
	else if (key->flag == 's' && (*i + 1 < c))
		return (ft_strdup(v[++*i]));
	else if (key->f)
		return (ft_my_read(key));
	else
		ft_help_key(key, v[*i]);
	return (NULL);
}

int		main(int c, char **v)
{
	int		i;
	char	*line;
	t_kkey	key;
	int		stdin;

	stdin = c == 1;
	ft_bzero_key(&key);
	v = c == 1 ? ft_read_sdtin() : v;
	c = (c == 1 ? (int)ft_dstrlen(v) : c);
	i = !stdin;
	while (i < c)
	{
		if (key.flag || key.f)
		{
			key.s = key.f ? v[i] : NULL;
			if ((line = ft_do_flag(&key, c, v, &i)))
			{
				key.flag == 'p' ? ft_printf("%s", line) : 0;
				key.s = key.f ? key.s : line;
				ft_algo(line, ft_strlen(line), &key, (key.flag != 'p'));
				ft_strdel(&line);
			}
			key.flag = 0;
			i++;
		}
		else if (v[i][0] == '-' && ft_isalpha(v[i][1]) && !v[i][2] && key.al)
			key.flag = v[i][1];
		else if (v[i][0] != '-')
			i = ft_read_nonmin(&key, v, i);
		else
			ft_help_key(&key, v[i]);
	}
	ft_delkey(&key);
}
