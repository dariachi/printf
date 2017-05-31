/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 11:38:51 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/28 15:18:05 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(char *format, t_print *pr)
{
	if (*format >= '0' && *format <= '9')
	{
		pr->width = (pr->width * 10) + (*format - '0');
		return (1);
	}
	return (0);
}

char	*ft_flag(char *format, t_print *pr)
{
	if (*format == 'h' && *(format + 1) != 'h')
		pr->h = 1;
	else if (*format == 'h' && *(format + 1) == 'h')
	{
		pr->hh = 1;
		format++;
	}
	else if (*format == 'l' && *(format + 1) != 'l')
		pr->l = 1;
	else if (*format == 'l' && *(format + 1) == 'l')
	{
		pr->ll = 1;
		format++;
	}
	else if (*format == 'j')
		pr->j = 1;
	else if (*format == 'z')
		pr->z = 1;
	return (format);
}

char	*ft_tochnost(char *format, t_print *pr)
{
	if (*format == '.')
	{
		pr->format = 0;
		format++;
		while (*format >= '0' && *format <= '9')
		{
			pr->format = (pr->format * 10) + *format - '0';
			format++;
		}
	}
	format--;
	return (format);
}
