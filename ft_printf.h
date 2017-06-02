/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:49:16 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/02 09:51:29 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <inttypes.h>
# include <wchar.h>

extern int g_all;

typedef struct          s_string
{
	char	resh[3];
	char *s;
//	char *d;
	char *t;
	char *q;
	char *p;
	int i;
	char z;
	char *arr;
	int u;
	int pred;
}						t_string;

typedef struct          s_print
{
    int minus;
	int plus;
	int probel;
	int reshotka;
	int nol;
	int	width;
	int format;
	int hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
	char type;
	t_string str;
}                       t_print;

int     ft_struct(char *format, t_print *pr);
void    ft_print_uxo(t_print *pr, char *t);
void    ft_printf_d(char z, char *arr, t_print *pr, intmax_t max);
void        ft_print_s(char *dl, t_print *pr, char *d);
void    ft_unicode_c( intmax_t uc);
void    ft_type_unis(t_print *pr, va_list *all);
void    ft_transl_two(intmax_t uc);
void    ft_transt_three(intmax_t uc);
void    ft_trans_four(intmax_t uc);
void    ft_trans_five(intmax_t uc);
void    ft_trans_six(intmax_t uc);
void    ft_protsent(t_print *pr);
void	ft_sc(t_print *pr, va_list *all);
void    ft_uxo(t_print *pr, va_list *all);
char            *ft_itoa_b(intmax_t n);
int     ft_struct(char *format, t_print *pr);
int     ft_width(char *format, t_print *pr);
char	*ft_tochnost(char *format, t_print *pr);
char     *ft_flag(char *format, t_print *pr);
void    ft_f_d(t_print *pr, va_list *all);
int     ft_printf(const char *format, ...);
char    *ft_itoa_new(uintmax_t k, char c);
void    ft_f_p(t_print *pr, va_list *all);
void    ft_cheak(t_print *pr, intmax_t max);
const char *ft_printf_dop(t_print *pr, const char *format);

#endif
