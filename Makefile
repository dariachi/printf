#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 13:14:13 by dchirkin          #+#    #+#              #
#    Updated: 2017/05/29 11:59:05 by dchirkin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
LIB_PATH = ./libft/
LIB =	ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memccpy.o \
	ft_memmove.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_strlen.o \
	ft_strdup.o \
	ft_strcpy.o \
	ft_strncpy.o \
	ft_strcat.o \
	ft_strncat.o \
	ft_strlcat.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_strstr.o \
	ft_strnstr.o \
	ft_strcmp.o \
	ft_strncmp.o \
	ft_atoi.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_toupper.o \
	ft_tolower.o \
		ft_strtrim.o \
		ft_strsub.o \
		ft_strsplit.o \
		ft_strnew.o \
		ft_strmapi.o \
		ft_strmap.o \
		ft_strjoin.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_putnbr.o \
		ft_putnbr_fd.o \
		ft_putendl.o \
		ft_putendl_fd.o \
		ft_putchar_fd.o \
		ft_putchar.o \
		ft_memdel.o \
		ft_memalloc.o \
		ft_itoa.o \
		ft_lstdelone.o \
		ft_lstnew.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o 
SRC_LIB = $(addprefix $(LIB_PATH), $(LIB))
SRC_NAME = ft_printf.o \
	ft_flag.o \
	ft_d.o \
	ft_itoa_base.o \
	ft_uxo.o \
	ft_16.o \
	ft_f_p.o \
	ft_sc.o \
	ft_protsent.o \
	ft_unic.o \
	ft_uni_s.o \
	ft_print_integ.o \
	ft_printf_dop.o
OBJ = $(SRC_LIB) $(SRC_NAME)
FLAGS = 
all: $(NAME)
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
$(LIB): %.o: $(LIB_PATH)%.c
		@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@
$(SRC_NAME): %.o: %.c
		@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@
clean:
		rm -f $(OBJ) ft_printf.h.gch $(LIB_PATH)libft.a
fclean:	clean
		rm -f $(NAME)
re:	fclean all