/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdoherty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:44:32 by pdoherty          #+#    #+#             */
/*   Updated: 2018/11/15 17:16:35 by pdoherty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	read_format_string(char *str, t_format *format)
{
	int	i;

	i = 0;
	add_flags(str, format);
	add_zero(str, format);
	add_width(str, format);
	add_precision(str, format);
}

t_format	*get_format(char *str, int j)
{
	char		*split;
	t_format	*format;

	split = ft_strsub(str, 0, j);
	if (split == NULL)
		return (NULL);
	format = (t_format *)malloc(sizeof(t_format));
	if (format == NULL)
		return (NULL);
	read_format_string(split, format);
	free(split);
	return (format);
}
