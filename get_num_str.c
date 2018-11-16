/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:36:46 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:31:53 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

	blc = "123456789abcdef";
	buc = "123456789ABCDEF";
	if (c)
		return (buc[n % base]);
	return (blc[n % base]);
}

char			*get_num_str(int *in, unsigned long long n, int b, int c)
{
	size_t	length;
	size_t	digits;
	char	*tr;
	size_t	i;

	digits = digits_from_base(n, b);
	length = digits + *in;
	tr = ft_strnew(length);
	i = 0;
	while (i < digits)
	{
		tr[-1 + length - i] = get_char_from_base(n, b, c);
		n /= b;
		i++;
	}
	if (*in)
		tr[0] = '-';
	return (tr);
}
