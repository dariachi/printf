/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protsent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:56:26 by dchirkin          #+#    #+#             */
/*   Updated: 2017/06/01 16:29:02 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_protsent(t_print *pr)
{
	char	p;
	char	*u;

	p = '%';
	if (pr->width > 1)
	{
		u = ft_strnew(pr->width - 1);
		if (pr->nol == 1 && pr->minus != 1)
			ft_memset(u, '0', pr->width - 1);
		else
			ft_memset(u, ' ', pr->width - 1);
	}
	else
		u = ft_strnew(0);
	if (pr->minus == 1)
	{
		ft_putchar(p);
		ft_putstr(u);
	}
	else
	{
		ft_putstr(u);
		ft_putchar(p);
	}
}
