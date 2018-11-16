/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:04:56 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:35:35 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_pointer(va_list list, int *chars)
{
	void	*val;
	char	*num;

	val = va_arg(list, void *);
	ft_putstr_wc("0x", chars);
	num = get_num_str(0, (unsigned long long)val, 16, 0);
	ft_putstr_wc(num, chars);
	free(num);
}
