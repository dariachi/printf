/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:41:43 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/01 14:02:29 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_format(t_print *pr)
{
	if (pr->format != -1)
		pr->nol = 0;
}

intmax_t		ft_max_uxo(va_list *all, t_print *pr)
{
	intmax_t	max;

	if (pr->j == 1)
		max = va_arg(*all, uintmax_t);
	else if (pr->z == 1)
		max = va_arg(*all, size_t);
	else if (pr->ll == 1 || (pr->l == 1 && (pr->type == 'O'
		|| pr->type == 'U')))
		max = va_arg(*all, unsigned long long int);
	else if (pr->l == 1 || pr->type == 'O' || pr->type == 'U')
		max = va_arg(*all, unsigned long int);
	else if (pr->h == 1)
		max = (unsigned short int)va_arg(*all, unsigned int);
	else if (pr->hh == 1)
		max = (unsigned char)va_arg(*all, unsigned int);
	else
		max = va_arg(*all, unsigned int);
	return (max);
}

void			ft_format_uxo(t_print *pr, intmax_t max)
{
	if (pr->reshotka == 1)
	{
		if (pr->type == 'x' && max != 0)
			ft_strcat(pr->str.resh, "0x");
		else if (pr->type == 'o' || pr->type == 'O')
			ft_strcat(pr->str.resh, "0");
		else if (pr->type == 'X')
			ft_strcat(pr->str.resh, "0X");
	}
	if (pr->format == 0 && max == 0)
	{
		pr->str.s = ft_strnew(0);
		if (pr->type == 'x' || pr->type == 'X')
			ft_memset(pr->str.resh, '\0', (int)ft_strlen(pr->str.resh));
		else if (pr->type == 'o' || pr->type == 'O')
		{
			ft_memset(pr->str.resh, '\0', (int)ft_strlen(pr->str.resh));
			if (pr->reshotka == 1)
				pr->str.resh[0] = '0';
		}
	}
	else
		pr->str.s = ft_itoa_new(max, pr->type);
}

void			ft_width_uxo(t_print *pr, char *t)
{
	if (pr->width > (int)ft_strlen(pr->str.s) + (int)ft_strlen(pr->str.resh)
		+ (int)ft_strlen(t))
	{
		pr->str.q = ft_strnew(pr->width - (int)ft_strlen(pr->str.s)
			+ ft_strlen(pr->str.resh) + ft_strlen(t));
		if (pr->nol == 1 && pr->minus == 0)
			ft_memset(pr->str.q, '0', (pr->width - (int)(ft_strlen(pr->str.s)
			+ ft_strlen(pr->str.resh) + ft_strlen(t))));
		else
			ft_memset(pr->str.q, ' ', (pr->width - (int)(ft_strlen(pr->str.s)
			+ ft_strlen(pr->str.resh) + ft_strlen(t))));
	}
	else
		pr->str.q = ft_strnew(0);
}

void			ft_uxo(t_print *pr, va_list *all)
{
	uintmax_t	max;
	char		*t;

	max = ft_max_uxo(all, pr);
	ft_format_uxo(pr, max);
	ft_format(pr);
	if (pr->format > (int)ft_strlen(pr->str.s))
	{
		t = ft_strnew(pr->format - ft_strlen(pr->str.s));
		ft_memset(t, '0', (pr->format - ft_strlen(pr->str.s)));
	}
	else
		t = ft_strnew(0);
	ft_width_uxo(pr, t);
	if ((pr->str.s[0] == '0' || t[0] == '0') && pr->str.resh[1] != 'x')
		ft_memset(pr->str.resh, '\0', (int)ft_strlen(pr->str.resh));
	ft_print_uxo(pr, t);
}
