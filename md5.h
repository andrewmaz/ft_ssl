/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:00:28 by amazurok          #+#    #+#             */
/*   Updated: 2018/05/16 16:44:35 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# define LEN 8
# define BYTE 8

# include "./libftprintf/libft/libft.h"

typedef struct	s_const
{
  	unsigned int	v;
  	struct s_const	*next;
}				t_const;

#endif
