/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:31:21 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/02 16:36:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_uint		*ft_create_buf(void)
{
	t_uint	*buf;

	buf = (t_uint *)malloc(sizeof(t_uint) * 8);
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

t_uint		*ft_create_buf224(void)
{
	t_uint	*buf;

	buf = (t_uint *)malloc(sizeof(t_uint) * 8);
	buf[0] = 0xc1059ed8;
	buf[1] = 0x367cd507;
	buf[2] = 0x3070dd17;
	buf[3] = 0xf70e5939;
	buf[4] = 0xffc00b31;
	buf[5] = 0x68581511;
	buf[6] = 0x64f98fa7;
	buf[7] = 0xbefa4fa4;
	return (buf);
}

t_ulint		*ft_create_buf384(void)
{
	t_ulint	*buf;

	buf = (t_ulint *)malloc(sizeof(t_ulint) * 8);
	buf[0] = 0xcbbb9d5dc1059ed8;
	buf[1] = 0x629a292a367cd507;
	buf[2] = 0x9159015a3070dd17;
	buf[3] = 0x152fecd8f70e5939;
	buf[4] = 0x67332667ffc00b31;
	buf[5] = 0x8eb44a8768581511;
	buf[6] = 0xdb0c2e0d64f98fa7;
	buf[7] = 0x47b5481dbefa4fa4;
	return (buf);
}

t_ulint		*ft_create_buf512(void)
{
	t_ulint	*buf;

	buf = (t_ulint *)malloc(sizeof(t_ulint) * 8);
	buf[0] = 0x6a09e667f3bcc908;
	buf[1] = 0xbb67ae8584caa73b;
	buf[2] = 0x3c6ef372fe94f82b;
	buf[3] = 0xa54ff53a5f1d36f1;
	buf[4] = 0x510e527fade682d1;
	buf[5] = 0x9b05688c2b3e6c1f;
	buf[6] = 0x1f83d9abfb41bd6b;
	buf[7] = 0x5be0cd19137e2179;
	return (buf);
}
