/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:54:58 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/22 18:54:58 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_del_m(t_md5 *lst)
{
	int		i;
	t_md5	*tmp;

	i = 0;
	while (lst && i <= D)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
		i++;
	}
}

void	ft_algo(const char *str, size_t len, t_kkey key)
{
	size_t			len1;
	unsigned char	*mg;
	t_uint			*msg;
	t_md5			*m;
	t_uint			*s;

	len1 = len * BIT + 1;
	while (len1 % 512 != 448)
		len1++;
	len1 /= BIT;
	len1 += LEN_BLCK;
	mg = (unsigned char *)malloc(sizeof(unsigned char) * (len1));
	ft_bzero(mg, len1);
	ft_memcpy(mg, str, len);
	mg[len] = 0x80;
	len *= BIT;
	s = NULL;
	m = key.md5 ? ft_new_md5() : NULL;
	msg = key.md5 ? ft_msg_md5(mg, len1, len) : ft_msg_sha(mg, len1, len);
	key.md5 ? ft_rounds_md5(m, msg, len1) : ft_rounds_sha256(msg, len1, &s);
	key.md5 ? ft_print_res_md5(m, key) : ft_print_res_sha(s, key);
	free(mg);
	free(msg);
	s ? free(s) : 0;
	ft_del_m(m);
}
