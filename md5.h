/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:00:28 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/21 17:18:44 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define LEN 8
# define BYTE 8

# include "./libftprintf/libft/libft.h"

typedef struct	s_md5
{
  	unsigned int	v;
  	unsigned int	old;
  	struct s_md5	*next;
  	struct s_md5	*prev;
}				t_md5;

typedef struct	s_sha256
{
  unsigned int	v;
  unsigned int	old;
  struct s_sha256	*next;
  struct s_sha256	*prev;
}				t_sha256;

typedef struct	s_kkey
{
  int		p;
  int		q;
  int		r;
  int		s;
}				t_kkey;


t_md5			*ft_new_md5(void);
t_sha256		*ft_new_sha256(void);
unsigned int	f_f(unsigned int x, unsigned int y, unsigned int z);
unsigned int	f_g(unsigned int x, unsigned int y, unsigned int z);
unsigned int	f_h(unsigned int x, unsigned int y, unsigned int z);
unsigned int	f_i(unsigned int x, unsigned int y, unsigned int z);
void			ft_r(t_md5 *h, unsigned int *wsi, unsigned int (*f1)(unsigned int, unsigned int, unsigned int));
unsigned int *ft_new_msg(unsigned char *str, size_t nlen, size_t len);
void	ft_rounds_md5(t_md5 *a, unsigned int *msg, size_t len1);
void	ft_print_result(t_md5 *a);

#endif
