/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:42:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/02 17:19:27 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

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
	"usage: ./ft_ssl [md5/sha224/sha256/sha384/sha512] [keys]");
	ft_printf("| %-14s %-58s|\n", "", "Keys:");
	ft_printf("| %-14s %-58s|\n", "-h", "<help>");
	ft_printf("| %-14s %-58s|\n", "-p", \
	"<echo STDIN to STDOUT and append the checksum to STDOUT>");
	ft_printf("| %-14s %-58s|\n", "-q", "<quiet mode>");
	ft_printf("| %-14s %-58s|\n", "-r", "<reverse the format of the output>");
	ft_printf("| %-14s %-58s|\n", "-s \"line\"", \
	"<print the sum of the given string>");
	ft_printf("|%s__%s|\n", s, s);
	ft_delkey(key, 1);
	exit(1);
}

void	ft_usage_ssl(t_kkey *key, char *str)
{
	if (!str)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", str);
		ft_printf("Standard commands:\n\n");
		ft_printf("Message Digest commands:\n");
		ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n\n");
		ft_printf("Cipher commands:\n\n");
	}
	ft_delkey(key, 1);
	exit(1);
}

void	ft_help_key(t_kkey *key, char *str)
{
	ft_printf("unknown option '%s'\n", str);
	ft_printf("options are\n");
	ft_printf("%-10s %-s\n", "-h", "help");
	ft_printf("%-10s %-s\n", "-p", \
	"echo STDIN to STDOUT and append the checksum to STDOUT");
	ft_printf("%-10s %-s\n", "-q", "quiet mode");
	ft_printf("%-10s %-s\n", "-r", "reverse the format of the output");
	ft_printf("%-10s %-s\n", "-s \"line\"", \
	"print the sum of the given string");
	ft_delkey(key, 1);
	exit(1);
}
