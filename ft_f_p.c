/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:01:01 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/25 11:26:08 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_ch(t_print *pr, intmax_t max)
{
	if (pr->format != -1 || pr->minus == 1)
		pr->nol = 0;
}

void			ft_print(t_print *pr)
{
	if (pr->minus == 1)
	{
		ft_putstr("0x");
		ft_putstr(pr->str.t);
		ft_putstr(pr->str.s);
		ft_putstr(pr->str.q);
	}
	else if (pr->format == -1 && pr->nol == 1)
	{
		ft_putstr("0x");
		ft_putstr(pr->str.q);
		ft_putstr(pr->str.s);
	}
	else
	{
		ft_putstr(pr->str.q);
		ft_putstr("0x");
		ft_putstr(pr->str.t);
		ft_putstr(pr->str.s);
	}
}

void			ft_width_p(t_print *pr)
{
	pr->str.q = ft_strnew(pr->width - 2 - (int)(ft_strlen(pr->str.s)
		+ ft_strlen(pr->str.t)));
	if (pr->nol == 1)
		ft_memset(pr->str.q, '0', (pr->width - 2 -
			(int)(ft_strlen(pr->str.s) + ft_strlen(pr->str.t))));
	else
		ft_memset(pr->str.q, ' ', (pr->width - 2 -
			(int)(ft_strlen(pr->str.s) + ft_strlen(pr->str.t))));
}

void			ft_f_p(t_print *pr, va_list *all)
{
	uintmax_t	max;

	max = (uintmax_t)va_arg(*all, void *);
	ft_ch(pr, max);
	if (pr->format == 0 && max == 0)
		pr->str.s = ft_strnew(0);
	else
		pr->str.s = ft_itoa_new(max, pr->type);
	if (pr->format > (int)ft_strlen(pr->str.s))
	{
		pr->str.t = ft_strnew(pr->format - ft_strlen(pr->str.s));
		ft_memset(pr->str.t, '0', (pr->format - ft_strlen(pr->str.s)));
	}
	else
		pr->str.t = ft_strnew(0);
	if (pr->width > (int)ft_strlen(pr->str.s) + (int)ft_strlen(pr->str.t) + 2)
		ft_width_p(pr);
	else
		pr->str.q = ft_strnew(0);
	ft_print(pr);
}
