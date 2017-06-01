/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:17:34 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/01 16:33:19 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_s(char *dl, t_print *pr, char *d)
{
	if (pr->minus == 1 && pr->width > pr->str.u)
	{
		ft_putstr(dl);
		ft_putstr(d);
	}
	else
	{
		ft_putstr(d);
		ft_putstr(dl);
	}
}

void		ft_print_sc_uni(wchar_t *str, t_print *pr, char *d, int i)
{
	if (pr->minus == 1 && pr->width > pr->str.u)
	{
		while (*str != '\0' && i > 0)
		{
			ft_unicode_c(pr, *str);
			str++;
			i--;
		}
		ft_putstr(d);
	}
	else
	{
		ft_putstr(d);
		while (*str != '\0' && i > 0)
		{
			ft_unicode_c(pr, *str);
			str++;
			i--;
		}
	}
}

char		*ft_next_width(t_print *pr, char *d, wchar_t *str)
{
	if (pr->width > pr->str.u)
	{
		d = ft_strnew(pr->width - pr->str.u);
		if (pr->nol == 1)
			ft_memset(d, '0', pr->width - pr->str.u);
		else
			ft_memset(d, ' ', pr->width - pr->str.u);
	}
	else
		d = ft_strnew(0);
	ft_print_sc_uni(str, pr, d, pr->str.i);
	return (d);
}

void		ft_byte(wchar_t *dl, t_print *pr)
{
	if (*dl <= 0x0000007F)
		pr->str.u += 1;
	else if (*dl <= 0x000007FF)
		pr->str.u += 2;
	else if (*dl <= 0x0000FFFF)
		pr->str.u += 3;
	else if (*dl <= 0x001FFFFF)
		pr->str.u += 4;
}

wchar_t		*ft_str_s(va_list *all, t_print *pr, wchar_t *str)
{
	pr->str.i = 0;
	pr->str.pred = 0;
	pr->str.u = 0;
	str = va_arg(*all, wchar_t *);
	if (str == NULL)
		ft_putstr("(null)");
	return (str);
}

void		ft_type_unis(t_print *pr, va_list *all)
{
	wchar_t	*str;
	char	*d;
	wchar_t	*dl;

	d = NULL;
	str = NULL;
	str = ft_str_s(all, pr, str);
	if (str == NULL)
		return ;
	dl = str;
	while (*dl != '\0')
	{
		ft_byte(dl, pr);
		dl++;
		pr->str.i++;
		if ((pr->str.u >= pr->format) && pr->format != -1)
		{
			if (pr->str.u > pr->format)
			{
				pr->str.u = pr->str.pred;
				pr->str.i--;
			}
			break ;
		}
		pr->str.pred = pr->str.u;
	}
	d = ft_next_width(pr, d, str);
}
