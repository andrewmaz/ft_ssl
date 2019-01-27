# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <amazurok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by amazurok          #+#    #+#              #
#    Updated: 2019/01/27 20:35:20 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC = ft_addit_func.c ft_char2int.c ft_create_buf.c ft_del.c ft_help.c ft_md5.c \
	ft_new.c ft_new_sha_algo.c ft_print.c ft_read_key.c \
	ft_rounds_md5.c ft_rounds_sha512.c ft_rounds_sha.c ft_sha256.c ft_sha512.c \
	ft_start_algo.c main.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	$(MLIB) 
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)
	
clean:
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all
