/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:26:17 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/22 17:58:36 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_print_res_md5(t_md5 *a, t_kkey key)
{
	unsigned char *tmp;
	int i;

	i = 0;
	while (i < 4)
	{
		tmp = (unsigned char *)&a->old;
		ft_printf("%.2x%.2x%.2x%.2x", tmp[0], tmp[1], tmp[2], tmp[3]);
		a = a->next;
		i++;
	}
	ft_printf("\n");
}

void	ft_print_res_sha(t_uint *hash, t_kkey key)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%.8x",hash[i]);
		i++;
	}
	ft_printf("\n");
}