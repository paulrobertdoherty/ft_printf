/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:56:10 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/14 21:33:50 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	llof(va_list list, t_format *format, int *chars)
{
	long double			num;
	unsigned long long	first;
	int					in;

	num = va_arg(list, long double);
	in = 0;
	first = (unsigned long long)num;
	if (num < 0)
	{
		in = 1;
		first = (unsigned long long)-num;
	}
	*chars += print_float(first, num, format, in);
	return (1);
}

static int	lof(va_list list, t_format *format, int *chars)
{
	double				num;
	unsigned long long	first;
	int					in;

	num = va_arg(list, double);
	in = 0;
	first = (unsigned long long)num;
	if (num < 0)
	{
		in = 1;
		first = (unsigned long long)-num;
	}
	*chars += print_float(first, (long double)num, format, in);
	return (1);
}

static int	f(va_list list, t_format *format, int *chars)
{
	float				num;
	unsigned long long	first;
	int					in;

	num = (float)va_arg(list, double);
	in = 0;
	first = (unsigned long long)num;
	if (num < 0)
	{
		in = 1;
		first = (unsigned long long)-num;
	}
	*chars += print_float(first, (long double)num, format, in);
	return (1);
}

int			put_float(va_list list, t_format *format, int *chars)
{
	if (format->l)
	{
		if (format->L)
			return (llof(list, format, chars));
		return (1);
	}
	else
	{
		if (format->L)
			return (lof(list, format, chars));
		return (f(list, format, chars));
	}
}
