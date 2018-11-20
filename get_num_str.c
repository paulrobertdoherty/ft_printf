/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:36:46 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/19 19:45:35 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static size_t	digits_from_base(unsigned long long n, int base)
{
	int	tr;
	
	if (n == 0)
		return (1);
	tr = 0;
	while (n > 0)
	{
		tr++;
		n /= base;
	}
	return (tr);
}

static char		get_char_from_base(unsigned long long n, int base, int c)
{
	char	*blc;
	char	*buc;

	blc = "0123456789abcdef";
	buc = "0123456789ABCDEF";
	if (c)
		return (buc[n % base]);
	return (blc[n % base]);
}

static char		*get_base(int in, ull n, int b, int c)
{
	size_t	length;
	size_t	digits;
	char	*tr;
	size_t	i;

	digits = digits_from_base(n, b);
	length = digits + in;
	tr = ft_strnew(length);
	i = 0;
	while (i < digits)
	{
		tr[-1 + length - i] = get_char_from_base(n, b, c);
		n /= b;
		i++;
	}
	if (in)
		tr[0] = '-';
	return (tr);
}

char			*get_num_str(int *in, unsigned long long n, char c, t_format *f)
{
	int		b;
	int		ca;
	char	*base;
	char	*tr;

	ca = 0;
	if (c == 'd' || c == 'i')
		b = 10;
	else if (c == 'o')
		b = 8;
	else
	{
		b = 16;
		ca = c == 'X';
	}
	base = get_base(*in, n, b, ca);
	tr = get_front(base, n, c, f);
	ft_strdel(&base);
	return (tr);
}
