/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:51:55 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:32:39 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	dis(char *str, int pre, int zero, int *chars)
{
	int	i;
	int	is;

	i = 0;
	is = 0;
	while (i < pre)
	{
		if (!is && str[i])
			ft_putchar_wc(str[i], chars);
		else
		{
			is = 1;
			if (zero)
				ft_putchar_wc('0', chars);
			else
				ft_putchar_wc(' ', chars);
			i++;
		}
	}
}

static void	spaces(int n, int *chars)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_wc(' ', chars);
		i++;
	}
}

void		ft_putchar_wc(char c, int *chars)
{
	write(1, &c, 1);
	(*chars)++;
}

void		ft_putstr_wc(char *str, int *chars)
{
	if (str[0])
	{
		ft_putchar_wc(str[0], chars);
		ft_putstr_wc(&str[1], chars);
	}
}

void		print_with_flags(char *str, t_format *format, int *chars, char c)
{
	char	*j;

	if (format->hash)
	{
		if (c == 'o')
			j = ft_strjoin("0", str);
		else if (c == 'x')
			j = ft_strjoin("0x", str);
		else if (c == 'X')
			j = ft_strjoin("0X", str);
		else
			j = ft_strdup(str);
	}
	else
		j = ft_strdup(str);
	if (format->l)
	{
		dis(j, format->precision, format->zero, chars);
		spaces(format->width - format->precision, chars);
	}
	else
	{
		spaces(format->width - format->precision, chars);
		dis(j, format->precision, format->zero, chars);
	}
	free(j);
}
