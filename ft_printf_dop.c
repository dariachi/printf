/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:58:11 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/29 12:11:10 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printf_dop(t_print *pr, const char *format)
{
	format++;
	while (ft_struct((char *)format, pr) == 1)
		format++;
	format--;
	return (format);
}
