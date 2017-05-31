/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:52:43 by dchirkin          #+#    #+#             */
/*   Updated: 2017/05/31 16:49:40 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_all;


void	ft_list(t_print *pr)
{
	pr->minus = 0;
	pr->plus = 0;
	pr->probel = 0;
	pr->reshotka = 0;
	pr->nol = 0;
	pr->width = 0;
	pr->format = -1;
	pr->j = 0;
	pr->l = 0;
	pr->hh = 0;
	pr->h = 0;
	pr->ll = 0;
	pr->z = 0;
	pr->type = 0;
}

int		ft_struct(char *format, t_print *pr)
{
	if(*format == '-')
		pr->minus = 1;
	if(*format == '+')
		pr->plus = 1;
	if(*format == ' ')
		pr->probel = 1;
	if(*format == '#')
		pr->reshotka = 1;
	if(*format == '0')
		pr->nol = 1;
	if(*format == '-' || *format == '+' || *format == ' ' || *format == '#' || *format == '0')
	{
		return(1);
	}
	else
		return(0);
}

int		ft_conversions(char *format, t_print *pr, va_list *all)
{
//	printf("QL\n");
	if(*format == 'p')
	{
		pr->type = *format;
		ft_f_p(pr, all);
	}
	else if(*format == 'd' || *format == 'D' || *format == 'i')
	{
		pr->type = *format;
		ft_f_d(pr, all);
	}
	else if(*format == 'u' || *format == 'U' || *format == 'x' || *format == 'X' || *format == 'o' || *format == 'O')
	{
//		printf("L\n");
		pr->type = *format;
		ft_uxo(pr, all);
	}
	else if(*format == 'c' || *format == 'C' || *format == 's' || *format == 'S')
	{
//		printf("%d\n", *format);
//		printf("%c\n", *format);
		pr->type = *format;
		ft_sc(pr, all);
//		printf("%c\n", *format);
	}
	else if(*format == '%')
		ft_protsent(pr, format);
	else
		return(0);
	return(1);
}

int		ft_search(const char *format)
{
	char *f;

	if(*format == '\0')
		return(0);
	ft_strcat(f, format);
	while(*f != '\0' || *f != '%')
		f++;
	if(*f != '%')
		return(1);
	else
		return(0);
}

const char	*ft_width_for_z(t_print *pr, const char *format)
{
	char *y;

	if (pr->width > 1)
	{
		y = ft_strnew(pr->width - 1);
		if(pr->nol == 1 && pr->minus == 0)
			memset(y, '0', pr->width - 1);
		else
			memset(y, ' ', pr->width - 1);
	}
	else
		y = ft_strnew(0);
	if(pr->minus == 1)
	{
		ft_putchar(*format);
		ft_putstr(y);
	}
	else
	{
		ft_putstr(y);
		ft_putchar(*format);
	}
	format++;
	return(format);
}

const char	*ft_printf_2(t_print *pr, va_list *all, const char *format)
{
	while(*format != '\0')
	{
		if(ft_struct((char *)format, pr) == 1)
		{
			format++;
			while(ft_struct((char *)format, pr) == 1)
				format++;
			format--;
		}
		else if(ft_width((char *)format, pr) != 0)
		{
			format++;
			while(ft_width((char *)format, pr) != 0)
			{
				format++;
			}
			format--;
		}
		else if(*format == '.')
			format = ft_tochnost((char *)format, pr);
		else if(*format == 'h' || *format == 'l' || *format == 'j' || *format == 'z')
			format = ft_flag((char *)format, pr);
		else if(ft_conversions((char *)format, pr, all) == 1)
		{
			ft_list(pr);
			break ;
		}
		else
		{
			if(pr->width > 0)
				format = ft_width_for_z(pr, format);
			else
			{
				while(*format != '%' && *format != '\0' && *format != '\n' && *format == ' ')
					format++;
				while(*format != '%' && *format != '\0' && *format != '\n')
				{
					ft_putchar(*format);
					format++;
				}
			}
			ft_list(pr);
			format--;
			break ;
		}
		format++;
	}
	return(format);
}

int		ft_printf(const char *format, ...)
{
	va_list all;
	int p;

	t_print pr;
	g_all = 0;
	ft_list(&pr);
	va_start(all, format);
	//printf("ATA\n");
	while(*format != '\0')
	{
		if(*format == '%')
		{
//			printf("AAA\n");
			format++;
			if(*format == '\0')
				break ;
			format = ft_printf_2(&pr, &all, format);
		}
		else
			ft_putchar(*format);
		if(!format || *format == '\0')
			break ;
		format++;
	}
	va_end(all);
	return(g_all);
}
