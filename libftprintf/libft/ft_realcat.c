/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 12:42:21 by amazurok          #+#    #+#             */
/*   Updated: 2018/06/03 17:27:08 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realcat(char *input, char *str)
{
	input = ft_realloc(input, (ft_strlen(input) + ft_strlen(str)));
	input = ft_strcat(input, str);
	return (input);
}

char	*ft_realcatendl(char *input, char *str)
{
	input = ft_realloc(input, (ft_strlen(input) + ft_strlen(str) + 1));
	input = ft_strcat(input, str);
	input = ft_strcat(input, "\n");
	return (input);
}

char	*ft_realcatendl_s(char *input, char *str, char s)
{
	char buf[2];

	buf[0] = s;
	buf[1] = '\0';
	input = ft_realloc(input, (ft_strlen(input) + ft_strlen(str) + 1));
	input = ft_strcat(input, str);
	input = ft_strcat(input, buf);
	return (input);
}
