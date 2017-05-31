/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:46:26 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/31 19:26:30 by dchirkin         ###   ########.fr       */
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

void	ft_pr_d(char z, char *arr, t_print *pr, intmax_t max)
{
//	printf("p%s      i\n", pr->str.p);
//	printf("arr%s\n", arr);
//	printf("t%s\n", pr->str.t);
//	printf("prob %d\n", pr->probel);
//	printf("pr->width %d\n", pr->width);
//	if(pr->width > 0 && pr->probel == 1)
//		ft_putchar(' ');
	if (((z == '+' && pr->nol == 0 && (pr->width > 0 && pr->nol == 1)) || (pr->width > 0 && pr->nol == 1) || pr->width == 0) && max >= 0 && pr->plus == 1)
        ft_putchar('+');
	if (max < 0 && pr->width && pr->nol == 1 && (arr[0] == '0' || pr->str.t[0] == 48))
	{
		ft_putchar('-');
		pr->str.p++;
	}
	ft_putstr(arr);
//	else if (max < 0 && pr->str.t[0] == '0')
	if (max < 0 && pr->str.t[0] == '0')
	{
		ft_putchar('-');
		pr->str.p++;
	}
//	ft_putstr(arr);
	if(pr->plus == 1 && max >= 0 && ((pr->width > 0 && pr->nol != 1)))
		ft_putchar('+');
	ft_putstr(pr->str.t);
/*	if (ft_strchr(pr->str.p, '+') != NULL && arr[0] != '\0')
	{
		if (pr->nol >= 1)
			pr->str.p[0] = '0';
		else
			pr->str.p[0] = ' ';
			}*/
//	printf("t%s\n", pr->str.t);
//	printf("qqp%s\n", pr->str.p);
	ft_putstr(pr->str.p);
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
/*	printf("t %s\n", t);
	printf("resh %s\n", pr->str.resh);
	printf("s %s\n", pr->str.s);
	printf("q %s\n", pr->str.q);*/
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
