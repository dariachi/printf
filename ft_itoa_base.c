/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:21:30 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/25 10:47:34 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_lenint(intmax_t p)
{
	int			che;

	che = 2;
	p /= -10;
	while (p > 0)
	{
		p /= 10;
		che++;
	}
	return (che);
}

static int		ft_nlen(intmax_t n)
{
	int			i;

	i = 0;
	if (n == INTMAX_MIN)
		return (ft_lenint(n));
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n > 9)
	{
		while (n > 9)
		{
			i++;
			n = n / 10;
		}
	}
	i++;
	return (i);
}

static char		*ft_minstr(long int nbr, int i, char *ptr)
{
	int			l;

	l = 0;
	if (nbr == INTMAX_MIN)
	{
		i--;
		ptr[i] = (nbr % 10) * (-1) + '0';
		nbr /= 10;
	}
	nbr = -1 * nbr;
	ptr[0] = '-';
	while (--i > 0)
	{
		ptr[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (ptr);
}

char			*ft_itoa_b(intmax_t n)
{
	char		*ptr;
	int			i;
	intmax_t	nbr;

	nbr = n;
	i = ft_nlen(nbr);
	ptr = (char *)malloc(sizeof(char) * i + 1);
	ptr[i] = '\0';
	if (ptr == NULL)
		return (NULL);
	if (nbr < 0)
		ptr = ft_minstr(nbr, i, ptr);
	else
		while (--i >= 0)
		{
			ptr[i] = n % 10 + '0';
			n = n / 10;
		}
	return (ptr);
}
