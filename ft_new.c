/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:28:50 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/10 16:39:36 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_algo		*ft_newalgo(void)
{
	t_algo *algo;

	algo = (t_algo*)malloc(sizeof(t_algo));
	algo->name = NULL;
	algo->alg = NULL;
	algo->cr_lbuf = NULL;
	algo->cr_buf = NULL;
	algo->len = NULL;
	algo->next = NULL;
	algo->prev = NULL;
	algo->word = 0;
	return (algo);
}

void		ft_bzero_key(t_kkey *key)
{
	key->al = 0;
	key->flag = 0;
	key->q = 0;
	key->r = 0;
	key->h = 0;
	key->f = 0;
	key->s = NULL;
	key->alg = ft_add_algo();
}

t_md5		*ft_new_const(void)
{
	t_md5 *new;

	new = (t_md5 *)malloc(sizeof(t_md5));
	new->next = NULL;
	new->prev = NULL;
	new->old = 0;
	new->v = 0;
	return (new);
}

void		ft_addend_md5(t_md5 *head, t_md5 *end, unsigned int val)
{
	while (head->next)
		head = head->next;
	head->next = end;
	end->prev = head;
	end->old = val;
}

t_md5		*ft_new_md5(void)
{
	t_md5	*a;

	a = ft_new_const();
	ft_addend_md5(a, ft_new_const(), 0xefcdab89);
	ft_addend_md5(a, ft_new_const(), 0x98badcfe);
	ft_addend_md5(a, ft_new_const(), 0x10325476);
	ft_addend_md5(a, a, 0x67452301);
	return (a);
}
