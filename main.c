/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/15 17:24:01 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_md5(char *str, size_t len)
{
	size_t len1;

	len1 = len;
	while (len % 512 != 448)
		len1++;
	ft_putnbr(len1);
}

int		main(int c, char **v)
{
	size_t len;

	if (c == 2)
	{
		len = ft_strlen(v[1]);
		ft_md5(v[1], len);
	}
}
