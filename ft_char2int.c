/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:27:21 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/21 13:27:21 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void			ft_add_len(unsigned int *arr, int i, size_t len)
{
	while (len)
	{
		arr[i] = arr[i] | len << 0;
		len = len >> 8;
		arr[i] = arr[i] | len << 8;
		len = len >> 8;
		arr[i] = arr[i] | len << 16;
		len = len >> 8;
		arr[i] = arr[i] | len << 24;
		len = len >> 8;
		i++;
	}
}

unsigned int *ft_new_msg(unsigned char *str, size_t nlen, size_t len)
{
	unsigned int	*arr;
	int				i;
	int				new_len;

	i = 0;
	new_len = nlen / 4;
	arr = (unsigned int *)malloc(sizeof(unsigned int) * new_len);
	while (i < new_len)
		arr[i++] = 0;
	i = new_len - 2;
	nlen--;
	new_len--;
	while (new_len >= 0)
	{
		arr[new_len] = arr[new_len] | str[nlen--] << 24;
		arr[new_len] = arr[new_len] | str[nlen--] << 16;
		arr[new_len] = arr[new_len] | str[nlen--] << 8;
		arr[new_len] = arr[new_len] | str[nlen--] << 0;
		new_len--;
	}
	ft_add_len(arr, i, len);
	return (arr);
}
