/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:51:36 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/31 17:37:23 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_transl_two(intmax_t uc, t_print *pr)
{
	unsigned char	c;
	intmax_t		num;
	intmax_t		num2;

//	printf("2\n");
	num = ((uc >> 6) & 0x1F) | 0xc0;
	num2 = (uc & 0x3f) | 0x80;
	c = (unsigned char)num;
	ft_putchar(c);
	c = (unsigned char)num2;
	ft_putchar(c);
}

void				ft_transt_three(intmax_t uc, t_print *pr)
{
	unsigned char	c;
	intmax_t		n1;

//	printf("3\n");
	n1 = ((uc >> 12) & 0x0f) | 0xe0;
	c = (unsigned char)n1;
	ft_putchar(c);
	n1 = ((uc >> 6) & 0x3f) | 0x80;
	c = (unsigned char)n1;
	ft_putchar(c);
	n1 = (uc & 0x3f) | 0x80;
	c = (unsigned char)n1;
	ft_putchar(c);
//	printf("QWE\n");
}

void				ft_trans_four(intmax_t uc, t_print *pr)
{
	unsigned char	c;
	intmax_t		n;
	int				q;

//	printf("4\n");
	q = 12;
	n = ((uc >> 18) & 0x07) | 0xF0;
	c = (unsigned char)n;
	ft_putchar(c);
	while (q > 0)
	{
		n = ((uc >> q) & 0x3f) | 0x80;
		c = (unsigned char)n;
		ft_putchar(c);
		q -= 6;
	}
	n = (uc & 0x3f) | 0x80;
	c = (unsigned char)n;
	ft_putchar(c);
}

void				ft_trans_five(intmax_t uc)
{
	unsigned char	c;
	intmax_t		n;
	int				q;

	q = 18;
	n = ((uc >> 24) & 0x03) | 0xF8;
	c = (unsigned char)n;
	ft_putchar(c);
	while (q > 0)
	{
		n = ((uc >> q) & 0x3f) | 0x80;
		c = (unsigned char)n;
		ft_putchar(c);
		q -= 6;
	}
	n = (uc & 0x3f) | 0x80;
	c = (unsigned char)n;
	ft_putchar(c);
}

void				ft_trans_six(intmax_t uc)
{
	unsigned char	c;
	intmax_t		n;
	int				q;

	q = 24;
	n = ((uc >> 30) & 0x03) | 0xF8;
	c = (unsigned char)n;
	ft_putchar(c);
	while (q > 0)
	{
		n = ((uc >> q) & 0x3f) | 0x80;
		c = (unsigned char)n;
		ft_putchar(c);
		q -= 6;
	}
	n = (uc & 0x3f) | 0x80;
	c = (unsigned char)n;
	ft_putchar(c);
}
