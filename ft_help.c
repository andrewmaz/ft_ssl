/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:42:41 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/05 13:47:44 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_pint_name_c(t_algo *alg, char c)
{
	alg = ft_go2head(alg);
	while (alg)
	{
		ft_printf("%s%c", alg->name, c);
		alg = alg->next;
	}
}

void	ft_help(t_kkey *key)
{
	char *s;

	s = "____________________________________";
	ft_printf("%sHELP%s\n", s, s);
	ft_printf("| {red}%-73s{eoc}|\n", \
	"usage: ./ft_ssl [command opts] [keys]");
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
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", str);
		ft_printf("\nStandard commands:\n");
		ft_printf("\nMessage Digest commands:\n");
		ft_pint_name_c(key->alg, '\n');
		ft_printf("\nCipher commands:\n\n");
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
