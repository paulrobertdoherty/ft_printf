/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:03:28 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:36:15 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		put_string(va_list list, t_format *format, int *chars)
{
	char	*tr;

	tr = format->precision > 0 ? ft_strncpy(va_arg(list, char *), 0,
			format->precision) : ft_strdup(va_arg(list, char *));
	print_with_flags(tr, format, chars, 's');
	free(tr);
}
