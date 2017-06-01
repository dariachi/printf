#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 13:14:13 by dchirkin          #+#    #+#              #
#    Updated: 2017/06/01 16:35:37 by dchirkin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRC = ft_16.c ft_d.c ft_f_p.c ft_flag.c ft_itoa_base.c ft_print_integ.c ft_printf_dop.c ft_printf.c ft_protsent.c ft_sc.c ft_uni_s.c \
	ft_unic.c ft_uxo.c
all : $(NAME)
$(NAME) : $(OBJ)
	make -C libft
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)
%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<
clean:
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all