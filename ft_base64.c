/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:50:33 by amazurok          #+#    #+#             */
/*   Updated: 2018/07/16 17:17:14 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_encrypt_base64(t_uchar *mg, size_t len)
{
	int i;
	int j;
	char	*encrypt_msg;

	i = 0;
	j = 0;
	encrypt_msg = ft_strnew(len);
	while (i < len)
	{
		encrypt_msg[i++] = (t_uchar)mg[j] >> 2;
		encrypt_msg[i] = (t_uchar)(0b00110000 & mg[j++] << 4);
		encrypt_msg[i] = (t_uchar)(encrypt_msg[i] | mg[j] >> 4);
		encrypt_msg[++i] = (t_uchar)(0b00111100 & mg[j++] << 2);
		encrypt_msg[i] =  (t_uchar)(encrypt_msg[i] | mg[j] >> 6);
		i++;
		encrypt_msg[i++] = (t_uchar)(0b00111111 & mg[j++]);
	}
	return (encrypt_msg);
}

void	ft_base64_enc(t_kkey *key, t_uchar *mg, size_t len, int k)
{
	const char	alp[] = \
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char	*encrypt_msg;
	size_t	nlen;
	int		i;

	i = 0;
	nlen = key->alg->len(len);
	encrypt_msg = ft_encrypt_base64(mg, nlen);
	while (i < nlen)
		ft_printf ("%c", alp[encrypt_msg[i++]]);
	while (nlen++ % 4 != 0)
		ft_printf("=");
}

char	*ft_decrypt_base64(t_uchar *mg, size_t len)
{
	const char	alp[] = \
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int i;
	int j;
	char	*decrypt_msg;

	i = 0;
	j = 0;
	decrypt_msg = ft_strnew(len);
	while (i < len)
	{
		decrypt_msg[i] = (t_uchar)(ft_strchr(alp, mg[j++]) - alp) << 2;
		decrypt_msg[i++] |= (t_uchar)(ft_strchr(alp, mg[j]) - alp) >> 4;
		if (i >= len)
			break ;
		decrypt_msg[i] = (t_uchar)(ft_strchr(alp, mg[j++]) - alp) << 4;
		decrypt_msg[i++] |= (t_uchar)(ft_strchr(alp, mg[j]) - alp) >> 2;
		if (i >= len)
			break ;
		decrypt_msg[i] = (t_uchar)(ft_strchr(alp, mg[j++]) - alp) << 6;
		decrypt_msg[i++] |= (t_uchar)(ft_strchr(alp, mg[j++]) - alp);
	}
	return (decrypt_msg);
}

void	ft_base64_dec(t_kkey *key, t_uchar *mg, size_t len, int k)
{

	char	*encrypt_msg;
	size_t	nlen;

	nlen = len;
	while (nlen >= 0)
	{
		if (mg[nlen - 1] == '=')
			nlen--;
		else
			break ;
	}
	nlen -= nlen / 3;
	encrypt_msg = ft_decrypt_base64(mg, nlen);
	ft_printf("%s\n", encrypt_msg);
}