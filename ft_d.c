/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 11:56:05 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/01 16:24:53 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		ft_max(va_list *all, t_print *pr)
{
	intmax_t	max;

	if (pr->j == 1)
		max = va_arg(*all, intmax_t);
	else if (pr->z == 1)
		max = va_arg(*all, size_t);
	else if (pr->ll == 1 || (pr->l == 1 && pr->type == 'D'))
		max = va_arg(*all, long long int);
	else if (pr->l == 1 || pr->type == 'D')
		max = va_arg(*all, long int);
	else if (pr->h == 1)
		max = (short int)va_arg(*all, int);
	else if (pr->hh == 1)
		max = (char)va_arg(*all, int);
	else
		max = va_arg(*all, int);
	return (max);
}

void			ft_string_trans(t_print *pr, intmax_t max)
{
	if (pr->format == 0 && max == 0)
		pr->str.s = ft_strnew(0);
	else
		pr->str.s = ft_itoa_b(max);
	ft_cheak(pr, max);
	if (pr->probel == 1 && max >= 0 && pr->format == -1)
		pr->str.p = ft_strjoin(" ", pr->str.s);
	else
		pr->str.p = ft_strdup(pr->str.s);
	if (pr->str.p[0] == '-')
		pr->str.z = '-';
}

char			*ft_tochnost_d(t_print *pr, intmax_t max)
{
	char		*t;

	if (pr->format > (int)ft_strlen(pr->str.p))
	{
		if (max < 0)
		{
			t = ft_strnew(pr->format - ft_strlen(pr->str.p) + 1);
			ft_memset(t, '0', (pr->format - ft_strlen(pr->str.p) + 1));
		}
		else
		{
			t = ft_strnew(pr->format - ft_strlen(pr->str.p));
			ft_memset(t, '0', (pr->format - ft_strlen(pr->str.p)));
		}
	}
	else
		t = ft_strnew(0);
	return (t);
}

char			*ft_wid(t_print *pr)
{
	char		*c;
	char		*q;
	char		*arr;

	c = ft_strnew(1);
	ft_memset(c, '\0', 2);
	if (pr->plus == 1)
		pr->str.z = '+';
	q = ft_strnew(pr->width - pr->str.i - (int)(ft_strlen(pr->str.p)
		+ ft_strlen(pr->str.t)));
	if (pr->nol == 1 && pr->minus == 0)
		ft_memset(q, '0', (pr->width - pr->str.i - (int)(ft_strlen(pr->str.p)
			+ ft_strlen(pr->str.t))));
	else
		ft_memset(q, ' ', (pr->width - pr->str.i - (int)(ft_strlen(pr->str.p)
			+ ft_strlen(pr->str.t))));
	arr = ft_strjoin(c, q);
	free(q);
	free(c);
	return (arr);
}

void			ft_f_d(t_print *pr, va_list *all)
{
	intmax_t	max;
	char		*arr;

	max = ft_max(all, pr);
	ft_string_trans(pr, max);
	pr->str.t = ft_tochnost_d(pr, max);
	pr->str.i = ((pr->plus || pr->str.z == '-') && max >= 0) ? 1 : 0;
	ft_cheak(pr, max);
	if (pr->width - pr->str.i > (int)ft_strlen(pr->str.p) +
		(int)ft_strlen(pr->str.t))
		arr = ft_wid(pr);
	else
		arr = ft_strnew(0);
	ft_printf_d(pr->str.z, arr, pr, max);
}
