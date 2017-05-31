/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:34:49 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/25 10:42:07 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_ret_f(uintmax_t k, int sys, char c)
{
	char	x;

	if (c == 'X' || c == 'x' || c == 'p')
	{
		if (k < 10)
			x = k + '0';
		else
		{
			if (c == 'x' || c == 'p')
				x = k - 10 + 'a';
			else if (c == 'X')
				x = k - 10 + 'A';
		}
	}
	else if (c == 'o' || c == 'O')
		x = k + '0';
	else if (c == 'u' || c == 'U')
		x = k + '0';
	return (x);
}

char		*ft_string(uintmax_t k, int sys, int i, char c)
{
	uintmax_t	q;
	char		u[25];
	char		*p;
	int			j;

	j = 0;
	p = (char *)malloc(sizeof(char) * 25);
	while (k > 0)
	{
		q = k % sys;
		k /= sys;
		u[i] = ft_ret_f(q, sys, c);
		i++;
	}
	u[i] = '\0';
	i -= 1;
	while (u[i] != '\0')
	{
		p[j] = u[i];
		j++;
		i--;
	}
	p[j] = '\0';
	return (p);
}

char		*ft_itoa_new(uintmax_t k, char c)
{
	int		sys;

	if (k == 0)
		return ("0");
	if (c == 'x' || c == 'X' || c == 'p')
		sys = 16;
	else if (c == 'o' || c == 'O')
		sys = 8;
	else if (c == 'u' || c == 'U')
		sys = 10;
	return (ft_string(k, sys, 0, c));
}
