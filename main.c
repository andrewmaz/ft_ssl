/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:54:31 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/16 18:36:09 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include <math.h>

unsigned int k[] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

unsigned int f_f(unsigned int x, unsigned int y, unsigned int z)
{
	//f (X AND Y ) OR (NOT X AND Z)
	return (x & y) | (~x & z);
}

unsigned int f_g(unsigned int x, unsigned int y, unsigned int z)
{
	//G(X,Y,Z) = (X AND Z ) OR (Y AND NOT Z)
	return (x & z) | (y & ~z);
}

unsigned int f_h(unsigned int x, unsigned int y, unsigned int z)
{
	//	H(X,Y,Z) = X XOR Y XOR Z
	return (x ^ y ^ z);
}

unsigned int f_i(unsigned int x, unsigned int y, unsigned int z)
{
	//	I(X,Y,Z) = Y XOR (X OR NOT Z)
	return  y ^ (x | ~z);
}

void 	r1(t_const *h, unsigned unsigned int word, int s, int i, unsigned int (*f1)(unsigned int, unsigned int, unsigned int))
{
	h->v = h->next->v + ((h->v + f1(h->next->v, h->next->next->v, h->next->next->next->v) + word + k[i]) << s);
}

void	ft_md5(const char *str, size_t len)
{
	size_t len1;
	unsigned char *msg;
	int i;
	int k = 0;
	t_const a;
	t_const b;
	t_const c;
	t_const d;

	a.v = 0x67452301;
	b.v = 0xefcdab89;
	c.v = 0x98badcfe;
	d.v = 0x10325476;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &a;

	len1 = len * BYTE;
	while (len1 % 512 != 448)
		len1++;
	len1 /= BYTE;
	msg = (unsigned char *)malloc(sizeof(unsigned char) * (len1 + LEN));
	ft_bzero(msg, len1 + LEN);
	ft_memcpy(msg, str, len);
	msg[len] = 0x80;
	i = len1 + LEN - 1;
	int asd = len;
	while (len)
	{
		msg[i] = msg[i] | len;
		i--;
		len = len >> BYTE;
	}
	unsigned int qwe = 0;

	qwe = qwe | msg[0] << 24;
	qwe = qwe | msg[1] << 16;
	qwe = qwe | msg[2] << 8;
	qwe = qwe | msg[3] << 0;
	r1(&a, qwe, 7, 1, &f_f);
	qwe = qwe | msg[4] << 24;
	qwe = qwe | msg[5] << 16;
	qwe = qwe | msg[6] << 8;
	qwe = qwe | msg[7] << 0;
	r1(&d, qwe, 12, 2, &f_f);
	qwe = qwe | msg[8] << 24;
	qwe = qwe | msg[9] << 16;
	qwe = qwe | msg[10] << 8;
	qwe = qwe | msg[11] << 0;
	r1(&c, qwe, 17, 3, &f_f);
	qwe = qwe | msg[12] << 24;
	qwe = qwe | msg[13] << 16;
	qwe = qwe | msg[14] << 8;
	qwe = qwe | msg[15] << 0;
	r1(&b, qwe, 22, 4, &f_f);
	qwe = qwe | msg[16] << 24;
	qwe = qwe | msg[17] << 16;
	qwe = qwe | msg[18] << 8;
	qwe = qwe | msg[19] << 0;
	r1(&a, qwe, 7, 5, &f_f);
	qwe = qwe | msg[20] << 24;
	qwe = qwe | msg[21] << 16;
	qwe = qwe | msg[22] << 8;
	qwe = qwe | msg[23] << 0;
	r1(&d, qwe, 12, 6, &f_f);
	qwe = qwe | msg[24] << 24;
	qwe = qwe | msg[25] << 16;
	qwe = qwe | msg[26] << 8;
	qwe = qwe | msg[27] << 0;
	r1(&c, qwe, 17, 7, &f_f);
	qwe = qwe | msg[28] << 24;
	qwe = qwe | msg[29] << 16;
	qwe = qwe | msg[30] << 8;
	qwe = qwe | msg[31] << 0;
	r1(&b, qwe, 22, 8, &f_f);
	r1(&a, msg + 32, 7, 9, &f_f);
	r1(&d, msg + 36, 12, 10, &f_f);
	r1(&c, msg + 40, 17, 11, &f_f);
	r1(&b, msg + 44, 22, 12, &f_f);
	r1(&a, msg + 48, 7, 13, &f_f);
	r1(&d, msg + 52, 12, 14, &f_f);
	r1(&c, msg + 56, 17, 15, &f_f);
	r1(&b, msg + 60, 22, 16, &f_f);

//	R2(A,B,C,D,X[ 1], 5,17)
//	R2(D,A,B,C,X[ 6], 9,18)
//	R2(C,D,A,B,X[11],14,19)
//	R2(B,C,D,A,X[ 0],20,20)
//	R2(A,B,C,D,X[ 5], 5,21)
//	R2(D,A,B,C,X[10], 9,22)
//	R2(C,D,A,B,X[15],14,23)
//	R2(B,C,D,A,X[ 4],20,24)
//	R2(A,B,C,D,X[ 9], 5,25)
//	R2(D,A,B,C,X[14], 9,26)
//	R2(C,D,A,B,X[ 3],14,27)
//	R2(B,C,D,A,X[ 8],20,28)
//	R2(A,B,C,D,X[13], 5,29)
//	R2(D,A,B,C,X[ 2], 9,30)
//	R2(C,D,A,B,X[ 7],14,31)
//	R2(B,C,D,A,X[12],20,32)
//
	r1(&a, msg + 4, 5, 17, &f_g);
	r1(&d, msg + 24, 9, 18, &f_g);
	r1(&c, msg + 44, 14, 19, &f_g);
	r1(&b, msg + 0, 20, 20, &f_g);
	r1(&a, msg + 20, 5, 21, &f_g);
	r1(&d, msg + 40, 9, 22,  &f_g);
	r1(&c, msg + 60, 14, 23, &f_g);
	r1(&b, msg + 16, 20, 24, &f_g);
	r1(&a, msg + 36, 5, 25, &f_g);
	r1(&d, msg + 56, 9, 26, &f_g);
	r1(&c, msg + 12, 14, 27, &f_g);
	r1(&b, msg + 32, 20, 28, &f_g);
	r1(&a, msg + 52, 5, 29, &f_g);
	r1(&d, msg + 8, 9, 30,  &f_g);
	r1(&c, msg + 28, 14, 31, &f_g);
	r1(&b, msg + 48, 20, 32, &f_g);
//	/* Round 3. Do 16 operations. */
//	R3(A,B,C,D,X[ 5], 4,33)
//	R3(D,A,B,C,X[ 8],11,34)
//	R3(C,D,A,B,X[11],16,35)
//	R3(B,C,D,A,X[14],23,36)
//	R3(A,B,C,D,X[ 1], 4,37)
//	R3(D,A,B,C,X[ 4],11,38)
//	R3(C,D,A,B,X[ 7],16,39)
//	R3(B,C,D,A,X[10],23,40)
//	R3(A,B,C,D,X[13], 4,41)
//	R3(D,A,B,C,X[ 0],11,42)
//	R3(C,D,A,B,X[ 3],16,43)
//	R3(B,C,D,A,X[ 6],23,44)
//	R3(A,B,C,D,X[ 9], 4,45)
//	R3(D,A,B,C,X[12],11,46)
//	R3(C,D,A,B,X[15],16,47)
//	R3(B,C,D,A,X[ 2],23,48)
	r1(&a, msg + 20, 4, 33, &f_h);
	r1(&d, msg + 32, 11, 34, &f_h);
	r1(&c, msg + 44, 16, 35, &f_h);
	r1(&b, msg + 56, 23, 36, &f_h);
	r1(&a, msg + 4, 4, 37, &f_h);
	r1(&d, msg + 16, 11, 38,  &f_h);
	r1(&c, msg + 28, 16, 39, &f_h);
	r1(&b, msg + 40, 23, 40, &f_h);
	r1(&a, msg + 52, 4, 41, &f_h);
	r1(&d, msg + 0, 11, 42, &f_h);
	r1(&c, msg + 12, 16, 43, &f_h);
	r1(&b, msg + 24, 23, 44, &f_h);
	r1(&a, msg + 36, 4, 45, &f_h);
	r1(&d, msg + 48, 11, 46,  &f_h);
	r1(&c, msg + 60, 16, 47, &f_h);
	r1(&b, msg + 8, 23, 48, &f_h);
//	/* Round 4. Do 16 operations. */
//	R4(A,B,C,D,X[ 0], 6,49)
//	R4(D,A,B,C,X[ 7],10,50)
//	R4(C,D,A,B,X[14],15,51)
//	R4(B,C,D,A,X[ 5],21,52)
//	R4(A,B,C,D,X[12], 6,53)
//	R4(D,A,B,C,X[ 3],10,54)
//	R4(C,D,A,B,X[10],15,55)
//	R4(B,C,D,A,X[ 1],21,56)
//	R4(A,B,C,D,X[ 8], 6,57)
//	R4(D,A,B,C,X[15],10,58)
//	R4(C,D,A,B,X[ 6],15,59)
//	R4(B,C,D,A,X[13],21,60)
//	R4(A,B,C,D,X[ 4], 6,61)
//	R4(D,A,B,C,X[11],10,62)
//	R4(C,D,A,B,X[ 2],15,63)
//	R4(B,C,D,A,X[ 9],21,64)

	r1(&a, msg + 4, 6, 49, &f_i);
	r1(&d, msg + 24, 10, 50, &f_i);
	r1(&c, msg + 44, 15, 51, &f_i);
	r1(&b, msg + 0, 21, 52, &f_i);
	r1(&a, msg + 20, 6, 53, &f_i);
	r1(&d, msg + 40, 10, 54,  &f_i);
	r1(&c, msg + 60, 15, 55, &f_i);
	r1(&b, msg + 16, 21, 56, &f_i);
	r1(&a, msg + 36, 6, 57, &f_i);
	r1(&d, msg + 56, 10, 58, &f_i);
	r1(&c, msg + 12, 15, 59, &f_i);
	r1(&b, msg + 32, 21, 60, &f_i);
	r1(&a, msg + 52, 6, 61, &f_i);
	r1(&d, msg + 8, 10, 62,  &f_i);
	r1(&c, msg + 28, 15, 63, &f_i);
	r1(&b, msg + 48, 21, 64, &f_i);
	while (k < len1 + LEN)
		ft_printf("n%d - %b\n", k, msg[k++]);
	ft_printf("l - %b\n", ~asd);


	//  //e07910a06a086c83ba41827aa00b26ed
	//my//d34db1b983d099b923f099b972a899b9
	ft_printf("\n%x%x%x%x\n", a.v, b.v, c.v, d.v);




}

int		main(int c, char **v)
{
	size_t len;

	//x градусов = x * pi/180
	double q = (sin(2) > 0.0 ? sin(2) : -sin(2)) * pow(2, 32);
	ft_printf("%d", 0xd76aa478);
	if (c == 2)
	{
		len = ft_strlen(v[1]);
		ft_md5(v[1], len);
	}
}
