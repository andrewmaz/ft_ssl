# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <amazurok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 11:59:18 by amazurok          #+#    #+#              #
#    Updated: 2019/01/27 21:46:17 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SSL_SRC = ./ft_ssl_src/ft_char2int.c ./ft_ssl_src/ft_del.c  ./ft_ssl_src/ft_md5.c \
	./ft_ssl_src/ft_print.c ./ft_ssl_src/ft_rounds_md5.c ./ft_ssl_src/ft_rounds_sha.c \
	./ft_ssl_src/ft_rounds_sha512.c ./ft_ssl_src/ft_sha256.c ./ft_ssl_src/ft_sha512.c \
	./ft_ssl_src/ft_create_buf.c ./ft_ssl_src/ft_new_sha_algo.c

MAIN_SRC = ft_help.c ft_new.c ft_read_key.c  main.c ft_start_algo.c ft_addit_func.c ft_new_encryp_algo.c\
	ft_base64.c 

INC = ./inc

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

SRC = $(SSL_SRC) $(MAIN_SRC)

all: $(NAME)
#-Wall -Wextra -Werror
$(NAME): $(SRC)
	$(MLIB) 
	gcc  $(SRC) $(LIB) -I $(INC)  -o $(NAME)
	
clean:
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
	$(MLIB) fclean

re: fclean all
