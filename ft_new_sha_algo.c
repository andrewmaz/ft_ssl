/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_algo_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:42:22 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/05 13:09:29 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_create_md5(t_algo *alg)
{
	alg->name = "md5";
	alg->alg = ft_md5;
	alg->word = 8;
	alg->len = ft_newlen_256;
}

void	ft_create_sha224(t_algo *alg)
{
	alg->name = "sha224";
	alg->alg = ft_sha256_224;
	alg->word = 7;
	alg->cr_buf = ft_create_buf224;
	alg->len = ft_newlen_256;
}

void	ft_create_sha256(t_algo *alg)
{
	alg->name = "sha256";
	alg->alg = ft_sha256_224;
	alg->word = 8;
	alg->cr_buf = ft_create_buf256;
	alg->len = ft_newlen_256;
}

void	ft_create_sha384(t_algo *alg)
{
	alg->name = "sha384";
	alg->alg = ft_sha512_384;
	alg->word = 6;
	alg->cr_lbuf = ft_create_buf384;
	alg->len = ft_newlen_512;
}

void	ft_create_sha512(t_algo *alg)
{
	alg->name = "sha512";
	alg->alg = ft_sha512_384;
	alg->word = 8;
	alg->cr_lbuf = ft_create_buf512;
	alg->len = ft_newlen_512;
}
