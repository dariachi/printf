/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:08:46 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/02 09:50:14 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_c(t_print *pr, va_list *all)
{
	wchar_t	letter;
	char	*d;

	letter = va_arg(*all, wchar_t);
	if (pr->width > 1)
	{
		d = ft_strnew(pr->width - 1);
		if (pr->nol == 1)
			ft_memset(d, '0', pr->width - 1);
		else
			ft_memset(d, ' ', pr->width - 1);
	}
	else
		d = ft_strnew(0);
	if (pr->minus == 1 && pr->width > 1)
	{
		ft_putchar(letter);
		ft_putstr(d);
	}
	else
	{
		ft_putstr(d);
		ft_putchar(letter);
	}
}

char		*ft_next_width_chars(t_print *pr, char *d)
{
	if (pr->width > pr->str.u)
	{
		d = ft_strnew(pr->width - pr->str.u);
		if (pr->nol == 1 && pr->minus != 1)
			ft_memset(d, '0', pr->width - pr->str.u);
		else
			ft_memset(d, ' ', pr->width - pr->str.u);
	}
	else
		d = ft_strnew(0);
	return (d);
}

void		ft_type_s(t_print *pr, va_list *all)
{
	char	*str;
	char	*d;
	char	*dl;

	d = NULL;
	str = va_arg(*all, char *);
	if (str == NULL && pr->width == 0)
	{
		ft_putstr("(null)");
		return ;
	}
	if (str != NULL)
		pr->str.u = (int)ft_strlen(str);
	else
		pr->str.u = 0;
	if (pr->format < pr->str.u && pr->format != -1)
	{
		dl = ft_strnew(pr->format);
		ft_strncat(dl, str, pr->format);
		pr->str.u = pr->format;
	}
	else
	{
		if (str != NULL)
			dl = ft_strdup(str);
		else
			dl = NULL;
	}
	d = ft_next_width_chars(pr, d);
	ft_print_s(dl, pr, d);
}

void		ft_unicode_c(intmax_t uc)
{
	if (uc <= 0x0000007F)
		ft_putchar((char)uc);
	else if (uc <= 0x000007FF)
		ft_transl_two(uc);
	else if (uc <= 0x0000FFFF)
		ft_transt_three(uc);
	else if (uc <= 0x001FFFFF)
		ft_trans_four(uc);
	else if (uc <= 0x03FFFFFF)
		ft_trans_five(uc);
	else if (uc <= 0x7FFFFFFF)
		ft_trans_six(uc);
}

void		ft_unic_char_c(va_list *all)
{
	intmax_t	uc;
//	int			bit;

	uc = 0;
	uc = va_arg(*all, wchar_t);
	if (uc <= 0x0000007F)
		ft_putchar(uc);
	else if (uc <= 0x000007FF)
		ft_transl_two(uc);
	else if (uc <= 0x0000FFFF)
		ft_transt_three(uc);
	else if (uc <= 0x001FFFFF)
		ft_trans_four(uc);
	else if (uc <= 0x03FFFFFF)
		ft_trans_five(uc);
	else if (uc <= 0x7FFFFFFF)
		ft_trans_six(uc);
}

void		ft_sc(t_print *pr, va_list *all)
{
	if (pr->type == 'C' || (pr->type == 'c' && pr->l == 1))
	{
		ft_unic_char_c(all);
	}
	else if (pr->type == 'c')
		ft_type_c(pr, all);
	else if (pr->type == 's' && pr->l == 0)
	{
		ft_type_s(pr, all);
	}
	else if (pr->type == 'S' || (pr->type == 's' && pr->l == 1))
		ft_type_unis(pr, all);
}
