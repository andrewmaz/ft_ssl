/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/05 15:24:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_my_read(int fd, t_kkey *key)
{
	char	buf[101];
	char	*str;
	ssize_t	ret;

	if (fd < 0)
	{
		ft_printf("ft_ssl: %s: %s: No such file or directory\n", \
		key->alg->name, key->nfn[key->ifn++]);
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

int		main(int c, char **v)
{
	size_t	len;
	int		i;
	char	*line;
	t_kkey	key;

	i = 0;
	ft_read_key(c, v, &key);
	key.h ? ft_help(&key) : 0;
	if (!key.al)
		ft_usage_ssl(&key, NULL);
	if ((!key.s && !key.n_fd) || key.p)
	{
		line = ft_my_read(0, &key);
		key.p ? ft_printf("%s", line) : 0;
		line ? ft_algo(line, ft_strlen(line), &key, 0) : 0;
	}
	while (key.is < ft_num_word(key.s, 1) || i < key.n_fd)
	{
		line = (key.is < ft_num_word(key.s, 1)) ? key.ns[key.is] : \
				ft_my_read(key.fd[i++], &key);
		len = ft_strlen(line);
		line ? ft_algo(line, len, &key, 1) : 0;
		ft_strdel(&line);
	}
	ft_delkey(&key, 0);
}
