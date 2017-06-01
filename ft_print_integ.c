/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:46:26 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/01 16:26:56 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cheak(t_print *pr, intmax_t max)
{
	if (pr->plus == 1)
		pr->probel = 0;
	if (pr->format != -1 && max >= 0)
		pr->nol = 0;
	if (pr->plus == 1 && max < 0)
		pr->plus = 0;
}

void	ft_pr_d_next(t_print *pr, intmax_t max)
{
	if (max < 0 && pr->str.t[0] == '0')
	{
		ft_putchar('-');
		pr->str.p++;
	}
	if (pr->plus == 1 && max >= 0 && ((pr->width > 0 && pr->nol != 1)))
		ft_putchar('+');
	ft_putstr(pr->str.t);
	ft_putstr(pr->str.p);
}

void	ft_pr_d(char z, char *arr, t_print *pr, intmax_t max)
{
	if (((z == '+' && pr->nol == 0 && (pr->width > 0 && pr->nol == 1))
		|| (pr->width > 0 && pr->nol == 1) ||
		pr->width == 0) && max >= 0 && pr->plus == 1)
		ft_putchar('+');
	if (max < 0 && pr->width && pr->nol == 1
		&& (arr[0] == '0' || pr->str.t[0] == 48))
	{
		ft_putchar('-');
		pr->str.p++;
	}
	if (arr[0] == '0' && pr->str.p[0] == ' ')
	{
		ft_putchar(' ');
		pr->str.p[0] = '0';
	}
	else
		ft_putstr(arr);
	ft_pr_d_next(pr, max);
}

void	ft_printf_d(char z, char *arr, t_print *pr, intmax_t max)
{
	if (pr->minus == 1)
	{
		if (z == '+')
			ft_putchar(z);
		ft_putstr(pr->str.t);
		ft_putstr(pr->str.p);
		ft_putstr(arr);
	}
	else
		ft_pr_d(z, arr, pr, max);
}

void	ft_print_uxo(t_print *pr, char *t)
{
	if (pr->minus == 1)
	{
		ft_putstr(t);
		ft_putstr(pr->str.resh);
		ft_putstr(pr->str.s);
		ft_putstr(pr->str.q);
	}
	else
	{
		if (pr->str.q[0] == '0' || pr->str.q[0] == '\0')
			ft_putstr(pr->str.resh);
		ft_putstr(pr->str.q);
		if (pr->str.q[0] == ' ')
			ft_putstr(pr->str.resh);
		ft_putstr(t);
		ft_putstr(pr->str.s);
	}
}
