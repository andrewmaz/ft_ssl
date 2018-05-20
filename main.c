/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/20 17:38:09 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include <math.h>

unsigned int ft_toint(unsigned char *msg, int word)
{
	unsigned int res;

	res = 0;
	res = res | msg[word + 0] << 0;
	res = res | msg[word + 1] << 8;
	res = res | msg[word + 2] << 16;
	res = res | msg[word + 3] << 24;
	return (res);
}

unsigned int *ft_new_msg(unsigned char *str, size_t len)
{
	unsigned int *arr;
	int i;
	size_t new_len;

	i = 0;
	new_len = len / 4;
	arr = (unsigned int *)malloc(sizeof(unsigned int) * new_len);
	while (i < new_len)
		arr[i++] = 0;
	while (new_len >= 0)
	{
		arr[new_len] = str[len--] << 24;
		arr[new_len] = str[len--] << 16;
		arr[new_len] = str[len--] << 8;
		arr[new_len] = str[len--] << 0;
		new_len--;
	}
	return (arr);
}

void	ft_md5(const char *str, size_t len)
{
	size_t len1;
	unsigned char *mg;
	unsigned int *msg;
	int i;
	int k1 = 0;
	t_const *a;

	a = ft_new_abcd();
	len1 = len * BYTE;
	while (len1 % 512 != 448)
		len1++;
	len1 /= BYTE;
	len1 += LEN;
	mg = (unsigned char *)malloc(sizeof(unsigned char) * (len1));
	ft_bzero(mg, len1);
	ft_memcpy(mg, str, len);
	mg[len] = 0x80;

	msg = ft_new_msg(str, len1);
	i = len1 - 1;
	len *= 8;

	while (k1 < len1)
		ft_printf("n%d - %b\n", k1, msg[k1++]);

	unsigned int qwe = len1 + 8;

	while (i < qwe)
	{
		ft_printf("%D\n", msg[i++]);
	}
	i = 0;
	int q;
	int w;
	int e;
	int j;

	q = 1;
	w = 5;
	e = 0;
	while (i < len1)
	{
		a->v = a->old;
		a->next->v = a->next->old;
		a->next->next->v = a->next->next->old;
		a->next->next->next->v = a->next->next->next->old;
		j = 0;
		while (j < 64)
		{
			if (j < 16)
				r1(a, ft_toint(msg, (j * 4)), r[j], j, &f_f);
			else if (j < 32)
			{
				r1(a, ft_toint(msg, (q * 4)), r[j], j, &f_g);
				q = (q + 5) % 16;
			}
			else if (j < 48)
			{
				r1(a, ft_toint(msg, (w * 4)), r[j], j, &f_h);
				w = (w + 3) % 16;
			}
			else if (j < 64)
			{
				r1(a, ft_toint(msg, (e * 4)), r[j], j, &f_i);
				e = (e + 7) % 16;
			}
			a = a->prev;
			j++;
		}

		a->old += a->v;
		a->next->old += a->next->v;
		a->next->next->old += a->next->next->v;
		a->next->next->next->old += a->next->next->next->v;
		i += 64;
	}




	//  //e07910a06a086c83ba41827aa00b26ed
	//my//d34db1b983d099b923f099b972a899b9
	ft_printf("\nasd %D\n", ft_toint(msg, 60));
	ft_printf("\n%.2x\n", a->old);
	ft_printf("\n%.2x\n", a->next->old);
	ft_printf("\n%.2x\n", a->next->next->old);
	ft_printf("\n%.2x\n", a->next->next->next->old);





}

int		main(int c, char **v)
{
	size_t len;

	//x градусов = x * pi/180
	double q = (sin(2) > 0.0 ? sin(2) : -sin(2)) * pow(2, 32);
	//ft_printf("%d", 0xd76aa478);
	if (c == 2)
	{
		len = ft_strlen(v[1]);
		ft_md5(v[1], len);
	}
}
