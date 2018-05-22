/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/22 18:20:29 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "md5.h"




char *ft_my_read(int fd)
{
	char buf[101];
	char *str;
	ssize_t	ret;

	str = NULL;
	while ((ret = read(fd, buf, 100)) > 0)
	{
		buf[ret] = '\0';
		str = ft_realcat(str, buf);
	}
	return (str);
}

int		main(int c, char **v)
{
	size_t len;
	int i;
	char *line;
	t_kkey key;

	i = 0;
	ft_read_key(c, v, &key);
	if (!key.md5 && !key.sha256)
		return (0); //usage
	if ((!key.s && !key.n_fd) || key.p)
	{
		line = ft_my_read(0);
		key.p ? ft_printf("%s", line) : 0;
		len = ft_strlen(line);
		len > 0 ? ft_algo(line, len, key) : 0;
	}
	while (key.s || i < key.n_fd)
	{
		if (key.s)
		{
			line = key.s;
			key.s = NULL;
		}
		else
			line = ft_my_read(key.fd[i++]);
		len = ft_strlen(line);
		len > 0 ? ft_algo(line, len, key) : 0;
		ft_strdel(&line);
	}
}
