/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:00:28 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/03 17:47:07 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define LEN_BLCK_256 8
# define LEN_BLCK_512 16
# define BIT 8
# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7

# define T1 5
# define T2 2

# include "./libftprintf/libft/libft.h"

typedef unsigned int		t_uint;
typedef unsigned char		t_uchar;
typedef unsigned long int	t_ulint;
typedef t_uint	(*t_func)(t_uint, t_uint, t_uint);

typedef struct	s_md5
{
	t_uint			v;
	t_uint			old;
	struct s_md5	*next;
	struct s_md5	*prev;
}				t_md5;

typedef struct	s_kkey
{
	int		md5;
	int		sha224;
	int		sha256;
	int		sha384;
	int		sha512;
	int		p;
	int		q;
	int		r;
	int		h;
	char	*s;
	char	**ns;
	int		is;
	int		*fd;
	char	*fn;
	char	**nfn;
	int		ifn;
	int		n_fd;
}				t_kkey;

void			ft_bzero_key(t_kkey *key);
t_uint			ft_rotr(t_uint x, int s);
t_ulint			ft_rotr5(t_ulint x, int s);
void			ft_set_v5(t_ulint *des, t_ulint *src);
void			ft_add_v5(t_ulint *des, t_ulint *src);
t_md5			*ft_new_md5(void);
t_uint			f_f(t_uint x, t_uint y, t_uint z);
t_uint			f_g(t_uint x, t_uint y, t_uint z);
t_uint			f_h(t_uint x, t_uint y, t_uint z);
t_uint			f_i(t_uint x, t_uint y, t_uint z);
void			ft_r(t_md5 *h, t_uint *w, t_uint (*f1)(t_uint, t_uint, t_uint));
t_uint			*ft_msg_md5(unsigned char *str, size_t nlen, size_t len);
t_uint			*ft_msg_sha(unsigned char *str, size_t nlen, size_t len);
t_ulint			*ft_msg_sha512(t_uchar *mg, size_t nlen, size_t len);
void			ft_rounds_md5(t_md5 *a, t_uint *msg, size_t len1);
void			ft_rounds_sha256(t_kkey *key, t_uint *msg, size_t len, \
					t_uint **in);
void			ft_rounds_sha512(t_kkey *key, t_ulint *msg, size_t	nlen, \
					t_ulint **hash);
void			ft_print_res_md5(t_md5 *a, t_kkey *key, int k);
void			ft_print_res_sha(t_uint *hash, t_kkey *key, int k);
void			ft_print_res_sha512(t_ulint *hash, t_kkey *key, int k);
int				ft_read_key(int c, char **v, t_kkey *key);
t_uint			*ft_gen_addwords(t_uint *msg);
t_ulint			*ft_gen_addwords512(t_ulint *msg);
void			ft_algo(const char *str, size_t len, t_kkey *key, int k);
void			ft_help(t_kkey *key);
void			ft_delkey(t_kkey *key, int k);
void			ft_del_m(t_md5 *lst);
t_uint			*ft_create_buf(void);
t_uint			*ft_create_buf224(void);
t_ulint			*ft_create_buf384(void);
t_ulint			*ft_create_buf512(void);
void			ft_usage_ssl(t_kkey *key, char *str);
void			ft_help_key(t_kkey *key, char *str);

#endif