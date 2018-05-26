/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:42:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/26 14:24:35 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	ft_delkey(t_kkey *key, int k)
{
	ft_dstrdel(&key->nfn);
	k ? ft_dstrdel(&key->ns) : free(key->ns);
	ft_strdel(&key->s);
	ft_strdel(&key->fn);
	key->fd ? free(key->fd) : 0;
}

void	ft_help(t_kkey *key)
{
	char *s;

	s = "____________________________________";
	ft_printf("%sHELP%s\n", s, s);
	ft_printf("| {red}%-73s{eoc}|\n", \
	"usage: ./ft_ssl [md5/sha256/sha512] [keys]");
	ft_printf("| %-14s %-58s|\n", "", "Keys:");
	ft_printf("| %-14s %-58s|\n", "-h", "<help>");
	ft_printf("| %-14s %-58s|\n", "-p", \
	"<echo STDIN to STDOUT and append the checksum to STDOUT>");
	ft_printf("| %-14s %-58s|\n", "-q", "<quiet mode>");
	ft_printf("| %-14s %-58s|\n", "-r", "<reverse the format of the output>");
	ft_printf("| %-14s %-58s|\n", "-s \"line\"", \
	"<print the sum of the given string>");
	ft_printf("| %-14s %-58s|\n", "-b", "<output in binary form>");
	ft_printf("| %-14s %-58s|\n", "-c", \
	"<to output the digest with separating colons>");
	ft_printf("|%s__%s|\n", s, s);
	ft_delkey(key, 1);
	exit(1);
}
