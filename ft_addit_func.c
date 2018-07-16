/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:09:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/07/16 15:11:43 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_algo	*ft_go2head(t_algo *alg)
{
	while (alg->prev)
		alg = alg->prev;
	return (alg);
}

t_algo	*ft_add_algo(void)
{
	t_algo			*tmp;
	int				i;
	const t_cr_alg	alg[] = {ft_create_md5, ft_create_sha224, ft_create_sha256,
			ft_create_sha384, ft_create_sha512, ft_create_base64, NULL};

	i = 0;
	tmp = NULL;
	while (alg[i])
	{
		if (!tmp)
			tmp = ft_newalgo();
		else
			tmp->next = ft_newalgo();
		if (tmp->next)
			tmp->next->prev = tmp;
		tmp = tmp->next ? tmp->next : tmp;
		alg[i++](tmp);
	}
	return (ft_go2head(tmp));
}

size_t	ft_newlen_base(size_t len)
{
	ssize_t			len1;
	size_t			k;

	k = 0;
	len1 = len;
	while (len1 > 0)
	{
		len1 -= 3;
		k++;
	}
	len += k;
	return (len);
}

size_t	ft_newlen_256(size_t len)
{
	size_t			len1;

	len1 = len + 1;
	while (len1 % 512 != 448)
		len1++;
	len1 /= BIT;
	len1 += LEN_BLCK_256;
	return (len1);
}

size_t	ft_newlen_512(size_t len)
{
	size_t			len1;

	len1 = len + 1;
	while (len1 % 1024 != 896)
		len1++;
	len1 /= BIT;
	len1 += LEN_BLCK_512;
	return (len1);
}
