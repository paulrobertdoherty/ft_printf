/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:28:21 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:35:47 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	put_conversion(char c, t_format *format, va_list list, int *chars)
{
	char	g;

	if (c == 's')
		put_string(list, format, chars);
	else if (c == 'p')
		put_pointer(list, chars);
	else if (c == 'd'  || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
			c == 'X')
		put_num(list, format, chars, c);
	else if (c == 'f')
		put_float(list, format, chars);
	else if (c == 'c')
	{
		g = (char)va_arg(list, int);
		print_with_flags(&g, format, chars, 'c');
	}
	else if (c == '%')
		print_with_flags("%", format, chars, '%');
}


static int	is_conversion(char c)
{
	return (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
			c == 'u' || c == 'x' || c == 'X' || c == 'c' || c == '%' ||
			c == 'f');
}

static void	print_conversion(char *str, va_list list, int *i, int *chars)
{
	int			j;
	t_format	*format;

	j = 0;
	while (str[j])
	{
		if (is_conversion(str[j]))
		{
			format = get_format(str, j);
			put_conversion(str[j], format, list, chars);
			free(format);
			*i += j + 1;
			return ;
		}
		j++;
	}
	ft_putstr_wc(str, chars);
	*i += j + 1;
}

static int	print(const char *str, va_list list)
{
	int chars;
	int i;
	int mode;

	i = 0;
	chars = 0;
	mode = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_wc(str[i], &chars);
			i++;
		}
		else
			print_conversion((char *)(&str[i + 1]), list, &i, &chars);
	}
	return (chars);
}

int			ft_printf(const char *format, ...)
{
	va_list	list;
	int		chars;

	va_start(list, format);
	chars = print(format, list);
	va_end(list);
	return (chars);
}
