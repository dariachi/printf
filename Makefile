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

NAME =				libftprintf.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

FT_SRC_DIR =		./libft
PRINTF_SRC_DIR =	./printf

HEADER =			$(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER =	$(PRINTF_SRC_DIR)ft_printf.h

FT_COMPILED =		ft_islower.o \
					ft_isupper.o \
					ft_tolower.o \
					ft_toupper.o \
					ft_isdigit.o \
					ft_isalpha.o \
					ft_isalnum.o \
					ft_isascii.o \
					ft_strtolower.o \
					ft_strtoupper.o \
					ft_strlen.o \
					ft_strnlen.o \
					ft_strchr.o \
					ft_strchr_last.o \
					ft_strcmp.o \
					ft_strncmp.o \
					ft_strstr.o \
					ft_strnstr.o \
					ft_strcpy.o \
					ft_strncpy.o \
					ft_strdup.o \
					ft_strcat.o \
					ft_strncat.o \
					ft_strlcat.o \
					ft_memcpy.o \
					ft_memccpy.o \
					ft_memmove.o \
					ft_memcmp.o \
					ft_memset.o \
					ft_memchr.o \
					ft_bzero.o \
					ft_atoi.o \
					ft_memalloc.o \
					ft_memdel.o \
					ft_strnew.o \
					ft_strdel.o \
					ft_strclr.o \
					ft_striter.o \
					ft_striteri.o \
					ft_strmap.o \
					ft_strmapi.o \
					ft_strequ.o \
					ft_strnequ.o \
					ft_strsub.o \
					ft_strjoin.o \
					ft_strtrim.o \
					ft_strsplit.o \
					ft_itoa.o \
					ft_putchar.o \
					ft_putcharn_fd.o \
					ft_putstr.o 


PRINTF_COMPILED =	ft_printf.o \
					ft_flag.o \
					ft_d.o \
					ft_itoa_base.o \
					ft_uxo.o \
					ft_f_p.o \
					ft_sc.o \
					ft_protsent.o \
					ft_unic.o \
					ft_uni_s.o \
					ft_print_integ.o \
					ft_printf_dop.o

COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all