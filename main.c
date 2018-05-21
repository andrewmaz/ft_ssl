/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/21 19:41:10 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

unsigned int k[] = {
		0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
		0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
		0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
		0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
		0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
		0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
		0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
		0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

void	ft_set_v(unsigned int *des, unsigned int *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		des[i] = src[i];
		i++;
	}
}

void	ft_add_v(unsigned int *des, unsigned int *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		des[i] += src[i];
		i++;
	}
}

unsigned int	ft_rotr(unsigned int x, int s)
{
	unsigned int res;

	res = (x >> s) | (x << (32 - s));
	return (res);
}

unsigned int *ft_create_buf(void)
{
	unsigned int	*buf;

	buf = (unsigned int *)malloc(sizeof(unsigned int) * 8);
	buf[0] = 0x6A09E667;
	buf[1] = 0xBB67AE85;
	buf[2] = 0x3C6EF372;
	buf[3] = 0xA54FF53A;
	buf[4] = 0x510E527F;
	buf[5] = 0x9B05688C;
	buf[6] = 0x1F83D9AB;
	buf[7] = 0x5BE0CD19;
	return (buf);
}

unsigned int *ft_gen_addwords(unsigned int *msg)
{
	unsigned int	*res;
	unsigned int	s0;
	unsigned int	s1;
	int 			i;

	i = 0;
	res = (unsigned int *)malloc(sizeof(unsigned int) * 64);
	while (i < 16)
	{
		res[i] = msg[i];
		i++;
	}
	while (i < 64)
	{
		s0 = ft_rotr(res[i - 15], 7) ^ ft_rotr(res[i - 15], 18) ^ (res[i - 15] >> 3);
		s1 = ft_rotr(res[i - 2], 17) ^ ft_rotr(res[i - 2], 19) ^ (res[i - 2] >> 10);
		res[i] = res[i - 16] + s0 + res[i - 7] + s1;
		i++;
	}
	return (res);
}

void	ft_rounds_sha256(t_sha256 *s, unsigned int *msg, size_t len)
{
	int i;
	int j;
	unsigned int *nmsg;
	unsigned int	*bf;
	unsigned int	*bn;
	unsigned int t[6];

	int b;

	b = 0;
	i = 0;
	bf = ft_create_buf();
	bn = ft_create_buf();
	while (i < len)
	{
		nmsg = ft_gen_addwords(msg + b);
		//ft_set_v(s);
		ft_set_v(bf, bn);
		j = 0;
		while (j < 64)
		{
			t[0] = ft_rotr(bf[0], 2) ^ ft_rotr(bf[0], 13) ^ ft_rotr(bf[0], 22);
			t[1] = (bf[0] & bf[1]) ^ (bf[0] & bf[2]) ^ (bf[1] & bf[2]);
			t[2] = t[0] + t[1];
			t[3] = ft_rotr(bf[4], 6) ^ ft_rotr(bf[4], 11) ^ ft_rotr(bf[4], 25);
			t[4] = (bf[4] & bf[5]) ^ ((~bf[4]) & bf[6]);
			t[5] = bf[7] + t[3] + t[4] + k[i] + nmsg[i];

			bf[7] = bf[6];
			bf[6] = bf[5];
			bf[5] = bf[4];
			bf[4] = bf[3] + t[2];
			bf[3] = bf[2];
			bf[2] = bf[1];
			bf[1] = bf[0];
			bf[0] = t[2] + t[5];
			j++;
		}
		ft_add_v(bn, bf);
		//ft_add_v(s);
		b += 16;
		i += 64;
	}
	unsigned char *sdf;

	sdf = (unsigned char*)&bn[0];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[1];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[2];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[3];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[4];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[5];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[6];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);
	sdf = (unsigned char*)&bn[7];
	ft_printf("%.2x%.2x%.2x%.2x", sdf[0], sdf[1], sdf[2], sdf[3]);

}

void	ft_algo(const char *str, size_t len)
{
	size_t			len1;
	unsigned char	*mg;
	unsigned int	*msg;
	t_md5			*m;
	t_sha256		*s;

	m = ft_new_md5();
	s = ft_new_sha256();
	len1 = len * BYTE;
	while (len1 % 512 != 448)
		len1++;
	len1 /= BYTE;
	len1 += LEN;
	mg = (unsigned char *)malloc(sizeof(unsigned char) * (len1));
	ft_bzero(mg, len1);
	ft_memcpy(mg, str, len);
	mg[len] = 0x80;
	len *= BYTE;
	msg = ft_new_msg(mg, len1, len);

	//ft_rounds_md5(m, msg, len1);
	ft_rounds_sha256(s, msg, len1);


	//ft_print_result(m);
}

int		main(int c, char **v)
{
	size_t len;
	char *line = v[1];
	char *nl;
	//get_next_line(0, &line);

	nl = ft_strjoin(line, "\n");
	//if (c == 2)
	//{
		len = ft_strlen("abc\n");
		ft_algo("abc\n", len);
	//}
}
