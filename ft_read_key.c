/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/10 16:40:38 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_read_nonmin(t_kkey *key, char **v, int i)
{
	while (!key->al && !ft_strequ(v[i], key->alg->name) && key->alg->next)
		key->alg = key->alg->next;
	if (ft_strequ(v[i], key->alg->name))
		key->al = 1;
	else
	{
			if (!key->al)
				ft_usage_ssl(key, v[i]);
			key->f = 1;
	}
	return (i + !key->f);
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
