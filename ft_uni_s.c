/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:17:34 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/31 19:10:54 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_s(char *dl, t_print *pr, char *d)
{
	if (pr->minus == 1 && pr->width > pr->str.u)
	{
		ft_putstr(dl);
		ft_putstr(d);
	}
	else
	{
		ft_putstr(d);
		ft_putstr(dl);
	}
}

wchar_t		*ft_cpy(wchar_t *dst, wchar_t *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i++] = '\0';
	return (dst);
}

void		ft_print_sc_uni(wchar_t *str, t_print *pr, char *d, int i)
{
//	printf("d %s\n", d);
	if (pr->minus == 1 && pr->width > pr->str.u)
	{
		while (*str != '\0' && i > 0)
		{
			ft_unicode_c(pr, *str);
			str++;
			i--;
		}
		ft_putstr(d);
	}
	else
	{
		ft_putstr(d);
		while (*str != '\0' && i > 0)
		{
			ft_unicode_c(pr, *str);
			str++;
			i--;
//			printf("ii %d\n", i);
		}
	}
}

char		*ft_next_width(t_print *pr, char *d)
{
//	printf("u %d\n",pr->str.u);
//	printf("format %d\n", pr->format);
//	if (pr->str.u > pr->format && pr->format != -1)
//		pr->str.i = pr->format;
//	printf("u %d\n",pr->str.u);
	if (pr->width > pr->str.u) // && pr->format != 0)
	{
		d = ft_strnew(pr->width - pr->str.u);
		if (pr->nol == 1)
			ft_memset(d, '0', pr->width - pr->str.u);
		else
		ft_memset(d, ' ', pr->width - pr->str.u);
	}
	else
		d = ft_strnew(0);
	return (d);
}

void		ft_type_unis(t_print *pr, va_list *all)
{
	wchar_t	*str;
	char	*d;
	wchar_t	*dl;
	int		i;
	intmax_t uc;
	int pred;
	i = 0;
	pred = 0;
	pr->str.u = 0;
	str = va_arg(*all, wchar_t *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	dl = str;
//	printf("u %d\n", pr->str.u);
//	printf("dl %d", *dl);
//	printf("for %d\n", pr->format);
	while (*dl != '\0')
	{
		if (*dl <= 0x0000007F)
			pr->str.u += 1;
		else if(*dl <= 0x000007FF)
			pr->str.u += 2;			
 		else if(*dl <= 0x0000FFFF)
			pr->str.u += 3;
    	else if(*dl <= 0x001FFFFF)
			pr->str.u += 4;
		dl++;
		i++;
//		printf("u %d\n", pr->str.u);
//		printf("format %d\n", pr->format);
		if((pr->str.u >= pr->format) && pr->format != -1)
		{
			if(pr->str.u > pr->format) //&& pr->format != 0)
			{
				pr->str.u = pred;
				i--;
			}
//			printf("u %d\n", pr->str.u);
//			printf("KL\n");
			break ;
		}
		pred = pr->str.u;
		//	printf("u\n");
	}
//	printf("Q\n");
//	printf("i %d\n", i);
//	printf("%u d\n", pr->str.u);
	d = ft_next_width(pr, d);
//	pri = pr->str.u;
	ft_print_sc_uni(str, pr, d, i);
}
