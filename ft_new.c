/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:28:50 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/21 16:48:09 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

t_md5	*ft_new_const(void)
{
	t_md5 *new;

	new = (t_md5 *)malloc(sizeof(t_md5));
	new->next = NULL;
	new->prev = NULL;
	new->old = 0;
	new->v = 0;
	return (new);
}

void	ft_addend_md5(t_md5 *head, t_md5 *end, unsigned int val)
{
	while (head->next)
		head = head->next;
	head->next = end;
	end->prev = head;
	end->old = val;
}

t_md5	*ft_new_md5(void)
{
	t_md5 *a;

	a = ft_new_const();
	ft_addend_md5(a, ft_new_const(), 0xefcdab89);
	ft_addend_md5(a, ft_new_const(), 0x98badcfe);
	ft_addend_md5(a, ft_new_const(), 0x10325476);
	ft_addend_md5(a, a, 0x67452301);
	return (a);
}

t_sha256	*ft_new_buf(void)
{
	t_sha256 *new;

	new = (t_sha256 *)malloc(sizeof(t_sha256));
	new->next = NULL;
	new->prev = NULL;
	new->old = 0;
	new->v = 0;
	return (new);
}

void	ft_addend_sha256(t_sha256 *head, t_sha256 *end, unsigned int val)
{
	while (head->next)
		head = head->next;
	head->next = end;
	end->prev = head;
	end->old = val;
}

t_sha256	*ft_new_sha256(void)
{
	t_sha256 *a;

	a = ft_new_buf();
	ft_addend_sha256(a, ft_new_buf(), 0xBB67AE85);
	ft_addend_sha256(a, ft_new_buf(), 0x3C6EF372);
	ft_addend_sha256(a, ft_new_buf(), 0xA54FF53A);
	ft_addend_sha256(a, ft_new_buf(), 0x510E527F);
	ft_addend_sha256(a, ft_new_buf(), 0x9B05688C);
	ft_addend_sha256(a, ft_new_buf(), 0x1F83D9AB);
	ft_addend_sha256(a, ft_new_buf(), 0x5BE0CD19);
	ft_addend_sha256(a, a, 0x6A09E667);

	return (a);
}