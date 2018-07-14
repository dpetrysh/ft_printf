#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 17:14:10 by dpetrysh          #+#    #+#              #
#    Updated: 2018/03/06 17:14:11 by dpetrysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
LIB_DIR = ./libft/

LIBFT = $(addprefix libft/, ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o	\
ft_memmove.o ft_memchr.o ft_memcmp.o ft_memalloc.o ft_memdel.o ft_strlen.o	\
ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o	\
ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o	\
ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o	\
ft_toupper.o ft_tolower.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o	\
ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o	\
ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o	\
ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o		\
ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o			\
ft_lstiter.o ft_lstmap.o)

_SRC = ft_printf.c \
		definer.c \
		spec_maker.c \
		atoi_base.c \
		atoi_base_uns.c \
		type_d.c \
		type_o.c \
		type_x.c \
		type_u.c \
		type_s.c \
		type_c.c \
		type_p.c \
		type_pers.c \
		prec_user.c \
		sign_maker.c \
		bracer.c 

SRC = $(_SRC:%.c=$(SRC_DIR)%.c)$
OBJ = $(_SRC:%.c=%.o)$

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	ar rc $@ $^ $(LIBFT)
	ranlib $(NAME)

%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -I ./libft -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all