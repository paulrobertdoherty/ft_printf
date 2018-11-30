/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:57:52 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/29 10:44:06 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static long double	ft_decimal_pow(long double n, int p)
{
	if (p == 0)
		return (1.0);
	if (p == 1)
		return (n);
	return (n * ft_decimal_pow(n, p - 1));
}

static long double	round_half_to_even(long double num, int precision)
{
	long double	a;

	a = 5 * ft_decimal_pow(0.1, precision);
	return (num + a);
}

static char			*get_dig_str(long double num, t_format *format)
{
	int		precision;
	int		i;
	char	*tr;

	if (format->precision != -1)
		precision = format->precision;
	else
		precision = 6;
	if (num < 0)
		num = -num;
	num = round_half_to_even(num, precision + 1);
	tr = ft_strnew(precision);
	i = 0;
	num -= (long)num;
	num *= 10;
	while (i < precision)
	{
		tr[i] = (long)num + '0';
		i++;
		num -= (long)num;
		num *= 10;
	}
	return (tr);
}

static t_format		*copy_format(t_format *format)
{
	t_format	*tr;

	tr = (t_format *)malloc(sizeof(t_format));
	tr->hash = 0;
	tr->plus = format->plus;
	tr->minus = format->minus;
	tr->precision = -1;
	tr->width = 0;
	tr->zero = format->zero;
	tr->space = format->space;
	return (tr);
}

int					print_float(unsigned long long first, long double num,
		t_format *format, int is_negative)
{
	char		*f;
	char		*s;
	char		*t;
	t_format	*nf;
	int			chars;

	chars = 0;
	nf = copy_format(format);
	if (!format->precision)
		first += (ull)(num - (long)num);
	f = get_num_str(&is_negative, first, 'f', nf);
	free(nf);
	if (format->hash || format->precision)
		s = ft_strjoin(f, ".");
	else
		s = ft_strdup(f);
	ft_strdel(&f);
	t = ft_strjoin(s, get_dig_str(num, format));
	ft_strdel(&s);
	print_with_flags(t, format, &chars);
	ft_strdel(&t);
	return (chars);
}
