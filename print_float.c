/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:57:52 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:32:57 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*get_dig_str(long double num, t_format *format)
{
	int		precision;
	int		i;
	char	*tr;

	if (format->precision != -1)
		precision = format->precision;
	else
		precision = 6;
	tr = ft_strnew(precision);
	i = 0;
	num -= (long)num;
	num *= 10;
	while (i < precision)
	{
		tr[i] = num + '0';
		i++;
		num -= (long)num;
		num *= 10;
	}
	return (tr);
}

int			print_float(unsigned long long first, long double num,
		t_format *format, int is_negative)
{
	char	*s;
	int		chars;

	chars = 0;
	s = get_num_str(&is_negative, first, 10, 0);
	print_with_flags(s, format, &chars, 'f');
	ft_strdel(&s);
	s = get_dig_str(num, format);
	ft_putchar_wc('.', &chars);
	ft_putstr_wc(s, &chars);
	return (chars);
}
