/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_encryp_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:48:53 by amazurok          #+#    #+#             */
/*   Updated: 2018/07/16 17:04:29 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_create_base64(t_algo *alg)
{
	alg->name = "base64";
	alg->alg = ft_base64_dec;
	alg->word = 0;
	alg->len = ft_newlen_base;
}